/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghbal <aaghbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 17:45:38 by aaghbal           #+#    #+#             */
/*   Updated: 2023/10/03 17:38:59 by aaghbal          ###   ########.fr       */
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

t_shape	check_ident_shap(char **elem, t_d_am am)
{
	t_shape s;
	
	s = test_shape();
	if (!ft_strncmp("sp", elem[0], ft_strlen(elem[0])))
		s = *parsing_sphere(elem, am);
	else if (!ft_strncmp("pl", elem[0], ft_strlen(elem[0])))
		s = *parsing_plan(elem, am);
	// else if (!ft_strncmp("cy", elem[0], ft_strlen(elem[0])))
	// 	return ;
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

void	ft_create_world(int fd, t_word *w)
{
	char	*line;
	char	**spl;
	t_d_am	am;
	int		i;
	
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		spl = ft_split(line, ' ');
		if (!ft_strncmp("A", spl[0], ft_strlen(spl[0])))
			am = parsing_am_light(spl);
		// else if (!ft_strncmp("L", spl[0], ft_strlen(spl[0])))
		// 	break;
		// else if (!ft_strncmp("C", spl[0], ft_strlen(spl[0])))
		// 	break;
		else if (!ft_strncmp("pl", spl[0], ft_strlen(spl[0])))
		{
			w->s[i] = check_ident_shap(spl, am);
			printf("%f %f %f\n", w->s[i].normal_pl.x, w->s[i].normal_pl.y,w->s[i].normal_pl.z);
			i++;
		}
		i++;
		free_doublep(spl);
	}
}


void read_file(char *file)
{
	int			fd;
	t_d_pars	p;
	t_word		w;

	if (!check_exten(file))
	{
		printf("Error extention!\n");
		exit(1);
	}
	fd = open(file, O_RDONLY);
	p = data_shape(fd);
	close(fd);
	w.s = malloc(sizeof(t_shape) *p.num_shap);
	w.l = malloc(sizeof(t_shape) *p.num_ligh);
	fd = open(file, O_RDONLY);
	ft_create_world(fd, &w);
}
