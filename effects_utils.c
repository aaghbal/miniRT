/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   effects_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houmanso <houmanso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 19:48:21 by houmanso          #+#    #+#             */
/*   Updated: 2023/10/08 12:08:29 by houmanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_check	uv_checkers(int w, int h, t_color a, t_color b)
{
	t_check c;

	c.a = a;
	c.b = b;
	c.width = w;
	c.height = h;
	return (c);
}

t_color	uv_checkers_at(t_check ch, double u, double v)
{
	int u_floor;
	int v_floor;
	int mod;

	u_floor = floor(u * ch.width);
	v_floor = floor(v * ch.height);
	mod = (u_floor + v_floor) % 2;
	if (mod)
		return (ch.b);
	return (ch.a);
}

t_texture_map	texture_map(t_check pattern, t_uv (*map)(t_point))
{
	t_texture_map	tm;

	tm.uv_pattern = pattern;
	tm.uv_map = map;
	return (tm);
}


t_color	checkers_at(t_texture_map tm, t_point p)
{
	t_uv	uv;

	uv = tm.uv_map(p);
	return (uv_checkers_at(tm.uv_pattern, uv.u, uv.v));
}
