/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cyl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houmanso <houmanso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 16:42:18 by aaghbal           #+#    #+#             */
/*   Updated: 2023/10/08 14:02:00 by houmanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	check_cap(t_ray r, double t)
{
	double	x;
	double	y;

	x = r.origine.x + t * r.direction.x;
	y = r.origine.z + t * r.direction.z;
	return (pow(x, 2) + pow(y, 2) <= 1);
}

t_intersect	*intersect_caps(t_shape s, t_ray r, t_intersect **xs)
{
	double	t;

	if (equal(r.direction.y, 0))
		return (*xs);
	t = (s.min - r.origine.y) / r.direction.y;
	if (check_cap(r, t))
	{
		if ((*xs)->min == 0)
			(*xs)->min = t;
		else if (t > (*xs)->min)
			add_back(xs, new_intersec(t, s));
		else
			add_front(xs, new_intersec(t, s));
	}
	t = (s.max - r.origine.y) / r.direction.y;
	if (check_cap(r, t))
	{
		if ((*xs)->min == 0)
			(*xs)->min = t;
		else if (t > (*xs)->min)
			add_back(xs, new_intersec(t, s));
		else
			add_front(xs, new_intersec(t, s));
	}
	return (*xs);
}

t_intersect	*cyl_intersect(t_shape s, t_ray ray)
{
	t_ray		r;
	t_data		data;
	t_intersect	*xs;

	xs = new_intersec(0, s);
	r = transform(ray, s.ivers_tran);
	data.a = pow(r.direction.x, 2) + pow(r.direction.z, 2);
	if (equal(data.a, 0))
		return (intersect_caps(s, r, &xs));
	data.b = 2 * (r.origine.x * r.direction.x + r.origine.z * r.direction.z);
	data.c = (pow(r.origine.x, 2) + pow(r.origine.z, 2)) - 1;
	data.discr = pow(data.b, 2) - 4 * data.a * data.c;
	if (data.discr < 0)
		return (xs);
	data.t0 = (-data.b - sqrt(data.discr)) / (2 * data.a);
	data.t1 = (-data.b + sqrt(data.discr)) / (2 * data.a);
	if (data.t0 > data.t1)
		ft_swap(&data.t0, &data.t1);
	data.y0 = r.origine.y + data.t0 * r.direction.y;
	if (data.y0 >= s.min && data.y0 <= s.max)
		xs = new_intersec(data.t0, s);
	data.y1 = r.origine.y + data.t1 * r.direction.y;
	if (data.y1 >= s.min && data.y1 <= s.max)
		add_back(&xs, new_intersec(data.t1, s));
	return (intersect_caps(s, r, &xs), xs);
}
