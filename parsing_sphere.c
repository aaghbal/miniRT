/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_sphere.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houmanso <houmanso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 15:35:23 by aaghbal           #+#    #+#             */
/*   Updated: 2023/10/05 21:50:53 by houmanso         ###   ########.fr       */
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
	s.tranform = multiple_matrice(s.tranform, scaling(diam, diam, diam));
	s.tranform = multiple_matrice(s.tranform, translation(o.x, o.y, o.z));
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
	s.tranform = multiple_matrice(s.tranform, orient(orie));
	s.tranform = multiple_matrice(s.tranform, translation(o.x, o.y, o.z));
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
	o = parse_origine(elem[1]);
	orie = parse_vector(elem[2]);
	diam = conver_range(elem[3]) / 2;
	hei = conver_range(elem[4]);
	// s.tranform = multiple_matrice(s.tranform, orient(orie));
	s.tranform = multiple_matrice(s.tranform, rotation_z(radiane(90)));
	s.tranform = multiple_matrice(s.tranform, translation(o.x, o.y, o.z));
	s.tranform = multiple_matrice(s.tranform, scaling(diam, 1, diam));
	s.tranform = multiple_matrice(s.tranform, scaling(1, hei, 1));
	s.m.color = parse_color(elem[5]);
	return (s);
}
