/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houmanso <houmanso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 20:23:55 by aaghbal           #+#    #+#             */
/*   Updated: 2023/10/14 16:13:55 by houmanso         ###   ########.fr       */
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

char	**split_line(char *line)
{
	char	**spl;

	spl = ft_split(line, ' ');
	if (!spl || !spl[0])
		print_error(ERR_ID);
	return (spl);
}

t_d_pars	data_shape(int fd)
{
	char		**spl;
	t_d_pars	p;
	t_cal		c;

	init_data(&p, &c);
	while (1)
	{
		p.line = get_next_line(fd);
		if (!p.line)
			break ;
		if (*p.line == '\n')
		{
			free(p.line);
			continue ;
		}
		spl = split_line(p.line);
		check_cal(spl[0], &c);
		p.num_shap += count_shape(spl[0]);
		!ft_strcmp("L", spl[0]) && p.num_ligh++;
		free_doublep(spl);
		free(p.line);
	}
	if (c.ambiant != 1 || c.camera != 1 || c.light < 1)
		print_error(ERR_CAL);
	return (p);
}
