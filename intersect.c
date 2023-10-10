/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghbal <aaghbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 15:31:08 by aaghbal           #+#    #+#             */
/*   Updated: 2023/10/10 11:09:04 by aaghbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	plan_intersect(t_shape s, t_ray ray)
{
	t_ray	r;
	double	t;

	r = transform(ray, s.ivers_tran);
	if (equal(r.direction.y, EPSILON))
		return (0);
	t = -r.origine.y / r.direction.y;
	return (t);
}

t_intersect	*sphere_intersect(t_shape s, t_ray ray)
{
	t_intersect	*res;
	t_data		data;
	t_ray		r;
	t_vector	sph_to_ray;

	res = NULL;
	r = transform(ray, s.ivers_tran);
	sph_to_ray = sub_to_point(r.origine, create_point(0, 0, 0));
	data.a = dot_product(r.direction, r.direction);
	data.b = 2 * dot_product(r.direction, sph_to_ray);
	data.c = dot_product(sph_to_ray, sph_to_ray) - (s.raduis * s.raduis);
	data.discr = pow(data.b, 2) - 4 * data.a * data.c;
	if (data.discr < 0)
	{
		res = new_intersec(0, s);
		return (res);
	}
	data.t0 = (-data.b - sqrt(data.discr)) / (2 * data.a);
	data.t1 = (-data.b + sqrt(data.discr)) / (2 * data.a);
	if (data.t0 < data.t1 && data.t0 > 0)
		return (new_intersec(data.t0, s));
	else if (data.t1 > 0)
		return (new_intersec(data.t1, s));
	return (new_intersec(0, s));
}

t_intersect	*intersect_world(t_word w, t_ray r, int n_object)
{
	t_intersect	*xs;
	t_intersect	*new;
	int			i;

	i = 0;
	xs = NULL;
	while (i < n_object)
	{
		if (w.s[i].obj == sp)
			new = sphere_intersect(w.s[i], r);
		else if (w.s[i].obj == pl)
			new = new_intersec(plan_intersect(w.s[i], r), w.s[i]);
		else if (w.s[i].obj == cy)
			new = cyl_intersect(w.s[i], r);
		else if (w.s[i].obj == co)
			new = cone_intersect(w.s[i], r);
		if (!xs)
			xs = new;
		else if (new->min < xs->min)
			add_front(&xs, new);
		else
			add_back(&xs, new);
		i++;
	}
	return (xs);
}

t_intersection	intersection(double t, t_shape s)
{
	t_intersection	i;

	i.t = t;
	i.sp = s;
	return (i);
}
