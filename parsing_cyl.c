/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_cyl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houmanso <houmanso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 14:03:42 by aaghbal           #+#    #+#             */
/*   Updated: 2023/10/08 14:17:17 by houmanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_shape	parsing_cyl(char **elem)
{
	double		diam;
	double		hei;
	t_vector	orie;
	t_point		o;
	t_shape		s;


	if (!elem[0] || !elem[1] || !elem[2] || !elem[3] || !elem[4] || !elem[5]
		|| elem[6])
		print_error(CY);
	s = default_shape();
	s.obj = cy;
	s.m.specular = 0.1;
	o = parse_origine(elem[1], CY);
	orie = parse_vector(elem[2], CY);
	diam = conver_ratio_number(elem[3], CY) / 2;
	hei = conver_ratio_number(elem[4], CY);
	s.tranform = multiple_matrice(scaling(diam, 1, diam), scaling(1, hei, 1));
	s.tranform = multiple_matrice(s.tranform, translation(o.x, o.y, o.z));
	s.tranform = multiple_matrice(s.tranform, orient(orie));
	set_transform(&s, s.tranform);
	s.m.color = rgb_color(elem[5], 1, CY);
	s.has_effects = true;
	s.pattern = uv_checkers(1, 1, s.m.color, create_color(0, 0, 0));
	s.mapping = texture_map(s.pattern, cyl_uv_map);
	return (s);
}
