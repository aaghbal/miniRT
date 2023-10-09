/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_plan.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houmanso <houmanso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 15:32:52 by aaghbal           #+#    #+#             */
/*   Updated: 2023/10/08 13:19:25 by houmanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"


t_shape	parsing_plan(char **elem)
{
	t_shape		s;
	t_point		o;
	t_vector	orie;

	if (!elem[0] || !elem[1] || !elem[2] || !elem[3] || elem[4])
		print_error(PL);
	s = default_shape();
	s.obj = pl;
	s.m.specular = 0;
	o = parse_origine(elem[1], PL);
	orie = parse_vector(elem[2], PL);
	s.tranform = multiple_matrice(orient(orie), translation(o.x, o.y, o.z));
	set_transform(&s, s.tranform);
	s.m.color = rgb_color(elem[3], 1, PL);
	s.has_effects	= true;
	s.pattern = uv_checkers(2, 2, s.m.color, create_color(255, 0, 0));
	s.mapping = texture_map(s.pattern, plan_uv_map);
	return (s);
}
