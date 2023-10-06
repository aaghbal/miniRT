/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_sphere.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghbal <aaghbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 15:35:23 by aaghbal           #+#    #+#             */
/*   Updated: 2023/10/06 18:29:34 by aaghbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_shape	parsing_sphere(char **elem)
{
	double	diam;
	t_point	o;
	t_shape	s;

	s = default_shape();
	s.obj = sp;
	o = parse_origine(elem[1]);
	diam = conver_range(elem[2]) / 2;
	s.tranform = multiple_matrice(translation(o.x, o.y, o.z), scaling(diam, diam, diam));
	s.m.color = parse_color(elem[3]); 
	return (s);
}

t_shape	parsing_plan(char **elem)
{
	t_shape		s;
	t_point		o;
	t_vector	orie;

	s = default_shape();
	s.obj = pl;
	s.m.specular = 0;
	o = parse_origine(elem[1]);
	orie = parse_vector(elem[2]);
	s.tranform = multiple_matrice(orient(orie), translation(o.x, o.y, o.z));
	s.m.color = parse_color(elem[3]);
	return (s);
}

t_shape	parsing_cyl(char **elem)
{
	double		diam;
	double		hei;
	t_vector	orie;
	t_point		o;
	t_shape		s;

	s = default_shape();
	s.obj = cy;
	s.m.specular = 0.1;
	o = parse_origine(elem[1]);
	orie = parse_vector(elem[2]);
	diam = conver_range(elem[3]) / 2;
	hei = conver_range(elem[4]);
	s.tranform = multiple_matrice(scaling(diam, 1, diam), scaling(1, hei, 1));
	s.tranform = multiple_matrice(s.tranform, translation(o.x, o.y, o.z));
	s.tranform = multiple_matrice(s.tranform, orient(orie));
	s.m.color = parse_color(elem[5]);
	print_matrice(s.tranform);
	return (s);
}
