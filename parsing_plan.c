/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_plan.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houmanso <houmanso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 15:32:52 by aaghbal           #+#    #+#             */
/*   Updated: 2023/10/12 15:19:59 by houmanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_d_bonus	init_plan(int n, char **elem)
{
	t_d_bonus	d;

	if (n == 6 && elem[4])
		d.nb = conver_ratio_number(elem[4], PL);
	if (n == 6 && !equal(d.nb, 0) && !equal(d.nb, 1))
		print_error(PL);
	if (n == 6 && elem[5] && d.nb == 0)
		d.c = rgb_color(elem[5], 1, PL);
	else if (n == 6 && elem[5] && d.nb == 1)
	{
		d.path = ft_strdup(elem[5]);
		ft_free(ADD, d.path);
	}
	return (d);
}

t_shape	parsing_plan(char **elem, int n)
{
	t_shape		s;
	t_point		o;
	t_vector	orie;
	t_d_bonus	d;

	if (n != 4 && n != 6)
		print_error(PL);
	s = default_shape();
	s.obj = pl;
	s.m.specular = 0;
	o = parse_origine(elem[1], PL);
	orie = parse_vector(elem[2], PL);
	s.tranform = multiple_matrice(orient(orie), translation(o.x, o.y, o.z));
	set_transform(&s, s.tranform);
	s.m.color = rgb_color(elem[3], 1, PL);
	d = init_plan(n, elem);
	s.has_effects = true;
	if (d.nb == 0)
	{
		s.type = checkers;
		s.pattern = uv_checkers(2, 2, s.m.color, d.c);
		s.mapping = texture_map(s.pattern, plan_uv_map);
		return (s);
	}
	s.type = texture;
	s.mapping.uv_map = plan_uv_map;
	s.img = mlx_load_png(d.path);
	return (s);
}
