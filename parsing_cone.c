/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_cone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghbal <aaghbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 12:00:30 by aaghbal           #+#    #+#             */
/*   Updated: 2023/10/09 19:48:14 by aaghbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_d_bonus	init_cone(int n, char **elem)
{
	t_d_bonus	d;

	if(n == 8 && elem[6])
		d.nb = conver_ratio_number(elem[6], CY);
	if (n == 8 && !equal(d.nb, 0) && !equal(d.nb, 1))
		print_error(CY);
	if(n == 8 && elem[7] && d.nb == 0)
		d.c = rgb_color(elem[7], 1, CY);
	else if (n == 8 && elem[7] && d.nb == 1)
	{
		d.path = ft_strdup(elem[7]);
		ft_free(ADD, d.path);
	}
	return (d);
}

t_shape	parsing_cone(char **elem, int n)
{
	double		diam;
	double		hei;
	t_vector	orie;
	t_point		o;
	t_shape		s;
	t_d_bonus	d;


	if (n != 6 && n != 8)
		print_error(CO);
	s = default_shape();
	s.obj = co;
	s.m.specular = 0.1;
	o = parse_origine(elem[1], CO);
	orie = parse_vector(elem[2], CO);
	diam = conver_ratio_number(elem[3], CO) / 2;
	hei = conver_ratio_number(elem[4], CO);
	s.tranform = multiple_matrice(scaling(diam, 1, diam), scaling(1, hei, 1));
	s.tranform = multiple_matrice(s.tranform, translation(o.x, o.y, o.z));
	s.tranform = multiple_matrice(s.tranform, orient(orie));
	set_transform(&s, s.tranform);
	s.m.color = rgb_color(elem[5], 1, CO);
	d = init_cone(n , elem);
	s.has_effects = true;
	s.pattern = uv_checkers(2, 2, s.m.color, create_color(0, 0, 0));
	s.mapping = texture_map(s.pattern, cyl_uv_map);
	return (s);
	
}
