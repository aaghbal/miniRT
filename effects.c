/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   effects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houmanso <houmanso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 11:22:02 by houmanso          #+#    #+#             */
/*   Updated: 2023/10/08 11:00:08 by houmanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_pattern	stripe_pattern(t_color a, t_color b)
{
	t_pattern	p;

	p.a = a;
	p.b = b;
	p.transform = identity();
	p.inverse = p.transform;
	return (p);
}

t_color	stripe_at(t_pattern p, t_point point)
{
	int x_floor;
	int y_floor;
	int z_floor;
	int mod;

	x_floor = floor(point.x);
	y_floor = floor(point.y);
	z_floor = floor(point.z);
	mod = x_floor + y_floor + z_floor;
	if (mod % 2)
		return (p.b);
	return (p.a);
}

void	pattern_set_transform(t_pattern *p, double **m)
{
	p->transform = m;
	p->inverse = inverse_gauss(m);
}

t_color	stripe_at_shape(t_pattern p, t_shape s, t_point point)
{
	t_point	obj_point;

	obj_point = mul_mat_point(s.ivers_tran, point);
	obj_point = mul_mat_point(p.inverse, obj_point);
	return (stripe_at(p, obj_point));
}

