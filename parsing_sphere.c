/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_sphere.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houmanso <houmanso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 15:35:23 by aaghbal           #+#    #+#             */
/*   Updated: 2023/10/08 14:11:13 by houmanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_shape	parsing_sphere(char **elem)
{
	t_point	o;
	t_shape	s;

	if (!elem[0] && !elem[1] && !elem[2] && !elem[3] && elem[4])
		print_error(C);
	s = default_shape();
	s.obj = sp;
	o = parse_origine(elem[1], SP);
	s.raduis = conver_ratio_number(elem[2], SP) / 2;
	set_transform(&s, translation(o.x, o.y, o.z));
	s.m.color = rgb_color(elem[3], 1, SP); 
	s.has_effects = true;
	s.pattern = uv_checkers(s.raduis * M_2_PI, s.raduis * M_PI,
			s.m.color, create_color(0, 0, 0));
	s.mapping = texture_map(s.pattern, sphere_uv_map);
	return (s);
}


