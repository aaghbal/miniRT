/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_sphere.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghbal <aaghbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 15:35:23 by aaghbal           #+#    #+#             */
/*   Updated: 2023/10/03 18:03:58 by aaghbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_shape	*parsing_sphere(char **elem, t_d_am am)
{
	char **spl;
	double diam;
	t_shape *s;

	s = malloc(sizeof(t_shape));
	spl = ft_split(elem[1], ',');
	diam = conver_range(elem[2]);
	s->obj = 0;
	s->m = material();
	s->m.ambient = am.ratio;
	s->m.amb_color = create_color(am.res[0] / 255, am.res[1] / 255,
			am.res[2] / 255);
	s->tranform = multiple_matrice(translation(conver_range(spl[0]),
	conver_range(spl[1]), conver_range(spl[2])),
		scaling(diam/ 2, diam/ 2, diam/ 2));
	free_doublep(spl);
	spl = ft_split(elem[3], ',');
	s->m.color = create_color(conver_range(spl[0]) / 255, 
			conver_range(spl[1]) / 255 , conver_range(spl[2]) / 255);
	free_doublep(spl);
	return (s);
}

t_shape	*parsing_plan(char **elem, t_d_am am)
{
	char **spl;
	t_shape *s;

	s = malloc(sizeof(t_shape));
	spl = ft_split(elem[1], ',');
	s->obj = 1;
	s->m = material();
	s->m.ambient = am.ratio;
	s->m.amb_color = create_color(am.res[0] / 255, am.res[1] / 255,
			am.res[2] / 255);
	s->tranform = translation(conver_range(spl[0]), conver_range(spl[1])
					,conver_range(spl[2])),
	free_doublep(spl);
	spl = ft_split(elem[2], ',');
	s->normal_pl = create_vector(conver_range(spl[0]), conver_range(spl[1]),
				conver_range(spl[2]));
	free_doublep(spl);
	spl = ft_split(elem[3], ',');
	s->m.color = create_color(conver_range(spl[0]) / 255, 
			conver_range(spl[1]) / 255 , conver_range(spl[2]) / 255);
	free_doublep(spl);
	return (s);
}

t_shape	*parsing_cyl(char **elem, t_d_am am)
{
	char **spl;
	double diam;
	double **tr;
	t_shape *s;

	s = malloc(sizeof(t_shape));
	spl = ft_split(elem[1], ',');
	diam = conver_range(elem[3]);
	s->obj = 2;
	s->m = material();
	s->m.ambient = am.ratio;
	s->m.amb_color = create_color(am.res[0] / 255, am.res[1] / 255,
			am.res[2] / 255);
	tr = multiple_matrice(translation(conver_range(spl[0]),
	conver_range(spl[1]), conver_range(spl[2])),
		scaling(diam/ 2, diam/ 2, diam/ 2));
	s->tranform
	free_doublep(spl);
	spl = ft_split(elem[2], ',');
	s->normal_pl = create_vector(conver_range(spl[0]), conver_range(spl[1]),
				conver_range(spl[2]));
	free_doublep(spl);
	spl = ft_split(elem[4], ',');
	s->m.color = create_color(conver_range(spl[0]) / 255, 
			conver_range(spl[1]) / 255 , conver_range(spl[2]) / 255);
	free_doublep(spl);
	return (s);
}
