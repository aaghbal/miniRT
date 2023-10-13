/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_sphere.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houmanso <houmanso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 15:35:23 by aaghbal           #+#    #+#             */
/*   Updated: 2023/10/13 15:19:50 by houmanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_shape		texture_checkerboard(t_shape s, t_d_bonus d)
{
	s.has_effects = true;
	if (d.nb == 0)
	{
		s.type = checkers;
		s.pattern = uv_checkers(s.raduis * 2 * M_PI, s.raduis * M_PI, s.m.color,
				create_color(0, 0, 0));
		s.mapping = texture_map(s.pattern, sphere_uv_map);
		return (s);
	}
	s.type = texture;
	s.mapping.uv_map = sphere_uv_map;
	s.img = mlx_load_png(d.path);
	return(s);
}

t_d_bonus	init_sphere(int n, char **elem)
{
	t_d_bonus	d;

	if (n == 6 && elem[4])
		d.nb = conver_ratio_number(elem[4], SP);
	if (n == 6 && !equal(d.nb, 0) && !equal(d.nb, 1))
		print_error(SP);
	if (n == 6 && elem[5] && d.nb == 0)
		d.c = rgb_color(elem[5], 1, SP);
	else if (n == 6 && elem[5] && d.nb == 1)
	{
		d.path = ft_strdup(elem[5]);
		ft_free(ADD, d.path);
	}
	return (d);
}

t_shape	parsing_sphere(char **elem, int n)
{
	t_point		o;
	t_shape		s;
	t_d_bonus	d;

	if (n != 4 && n != 6)
		print_error(SP);
	s = default_shape();
	s.obj = sp;
	o = parse_origine(elem[1], SP);
	s.raduis = conver_ratio_number(elem[2], SP) / 2;
	set_transform(&s, multiple_matrice( translation(o.x, o.y, o.z),
			rotation_y(M_PI + M_PI / 5)));
	s.m.color = rgb_color(elem[3], 1, SP);
	if (n == 4)
		return (s);
	d = init_sphere(n, elem);
	s = texture_checkerboard(s, d);
	return (s);
}
