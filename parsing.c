/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghbal <aaghbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 17:45:38 by aaghbal           #+#    #+#             */
/*   Updated: 2023/10/04 18:10:36 by aaghbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"


char *ft_strcpy(char *str)
{
	int i;
	char *res;
	int n;

	n = ft_strlen(str) + 1;
	i = 0;
	res = malloc(sizeof(char) * n);
	ft_free(ADD, res);
	while (str[i])
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return(res);
}

int	check_exten(char *argv)
{
	int		i;
	int		j;
	int		len;
	char	*tab;

	tab = ".rt";
	j = 0;
	len = ft_strlen(argv);
	i = len - 3;
	while (argv[i] != '\0')
	{
		if (argv[i] != tab[j])
			return (0);
		i++;
		j++;
	}
	return (1);
}

t_shape	check_ident_shap(char **elem)
{
	t_shape s;
	
	s = default_shape();
	if (!ft_strncmp("sp", elem[0], ft_strlen(elem[0])))
		s = parsing_sphere(elem);
	else if (!ft_strncmp("pl", elem[0], ft_strlen(elem[0])))
		s = parsing_plan(elem);
	else if (!ft_strncmp("cy", elem[0], ft_strlen(elem[0])))
		s = parsing_cyl(elem);
	return(s);
	// printf("ror identify shape\n");
}

t_d_pars data_shape(int fd)
{
	char	*line;
	char	**spl;
	t_d_pars p;

	p.num_shap = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		spl = ft_split(line, ' ');
		if (!ft_strncmp("A", spl[0], ft_strlen(spl[0])) ||
			!ft_strncmp("L", spl[0], ft_strlen(spl[0])) ||
			!ft_strncmp("C", spl[0], ft_strlen(spl[0])))
			p.num_shap++;
		if (!ft_strncmp("L", spl[0], ft_strlen(spl[0])))
			p.num_ligh++;
		
		free_doublep(spl);
	}
	return (p);
}

void	ft_create_world(int fd, t_d_pars p)
{
	char	*line;
	char	**spl;
	int		i;
	int		j;
	t_camera c;
	t_word	w;
	
	i = 0;
	j = 0;
	w.s = malloc(sizeof(t_shape) * p.num_shap);
	w.l = malloc(sizeof(t_light) * p.num_ligh);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		spl = ft_split(line, ' ');
		if (!ft_strncmp("A", spl[0], ft_strlen(spl[0])))
			w.ambiant = parsing_am_light(spl);
		else if (!ft_strncmp("L", spl[0], ft_strlen(spl[0])))
			w.l[j++] = parsing_light(spl);
		else if (!ft_strncmp("C", spl[0], ft_strlen(spl[0])))
			c = parsing_camera(spl);
		else
			w.s[i++] = check_ident_shap(spl);
		free_doublep(spl);
	}
	render(w, c);
}


void read_file(char *file)
{
	int			fd;
	t_d_pars	p;

	if (!check_exten(file))
	{
		printf("Error extention!\n");
		exit(1);
	}
	fd = open(file, O_RDONLY);
	p = data_shape(fd);
	close(fd);
	fd = open(file, O_RDONLY);
	ft_create_world(fd, p);
	close(fd);
}
