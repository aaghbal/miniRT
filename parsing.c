/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghbal <aaghbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 17:45:38 by aaghbal           #+#    #+#             */
/*   Updated: 2023/10/09 19:00:58 by aaghbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	init_data(t_d_pars *p, t_cal *c)
{
	c->ambiant = 0;
	c->light = 0;
	c->camera = 0;
	p->num_shap = 0;
	p->num_ligh = 0;
}

void	check_cal(char *line, t_cal *c)
{
	if (!ft_strcmp("A", line))
		c->ambiant++;
	if (!ft_strcmp("C", line))
		c->camera++;
	if (!ft_strcmp("L", line))
		c->light++;
}

t_d_pars data_shape(int fd)
{
	char	*line;
	char	**spl;
	t_d_pars p;
	t_cal	c;

	init_data(&p, &c);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		line = ft_strtrim(line, "\n");
		if (!*line)
			continue ;
		spl = ft_split(line, ' ');
		check_cal(spl[0], &c);
		if (!spl || !spl[0])
			print_error(ERR_ID);
		check_element(spl[0]);
		p.num_shap += count_shape(spl[0]);
		if (!ft_strcmp("L", spl[0]))
			p.num_ligh++;
		free_doublep(spl);
		free(line);
	}
	if (c.ambiant != 1 || c.camera != 1 || c.light < 1)
		print_error(ERR_CAL);
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
	ft_free(ADD, w.s);
	ft_free(ADD, w.l);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		line = ft_strtrim(line, "\n");
		if (!*line)
			continue ;
		spl = ft_split(line, ' ');
		if (!ft_strcmp("A", spl[0]))
			w.ambiant = parsing_am_light(spl);
		else if (!ft_strcmp("L", spl[0]))
			w.l[j++] = parsing_light(spl);
		else if (!ft_strcmp("C", spl[0]))
			c = parsing_camera(spl);
		else
			w.s[i++] = check_ident_shap(spl);
		free_doublep(spl);
		free(line);
	}
	render(w, c, p);
}

void read_file(char *file)
{
	int			fd;
	t_d_pars	p;

	if (!check_exten(file))
		print_error(EXTE);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		print_error(OP);
	p = data_shape(fd);
	close(fd);	
	fd = open(file, O_RDONLY);
	ft_create_world(fd, p);
	close(fd);
}
