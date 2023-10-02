/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghbal <aaghbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 15:31:08 by aaghbal           #+#    #+#             */
/*   Updated: 2023/10/02 12:45:33 by aaghbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	plan_intersect(t_shape s, t_ray ray, t_free **f)
{
	t_ray	r;
	double	t;

	r = transform(ray, inverse_gauss(s.tranform, f));
	if (equal(r.direction.y, EPSILON))
		return (0);
	t = -r.origine.y / r.direction.y;
	return (t);
}

t_intersect	*sphere_intersect(t_shape s, t_ray ray, t_free **f)
{
	t_intersect	*res;
	t_data		data;
	t_ray		r;
	t_vector	sph_to_ray;

	res = NULL;
	r = transform(ray, inverse_gauss(s.tranform, f));
	sph_to_ray = sub_to_point(r.origine, create_point(0, 0, 0));
	data.a = dot_product(r.direction, r.direction);
	data.b = 2 * dot_product(r.direction, sph_to_ray);
	data.c = dot_product(sph_to_ray, sph_to_ray) - 1;
	data.discr = pow(data.b, 2) - 4 * data.a * data.c;
	if (data.discr < 0)
	{
		res = new_intersec(0, s, f);
		return (res);
	}
	data.t0 = (-data.b - sqrt(data.discr)) / (2 * data.a);
	data.t1 = (-data.b + sqrt(data.discr)) / (2 * data.a);
	if (data.t0 < data.t1 && data.t0 > 0)
		return (new_intersec(data.t0, s, f));
	else if (data.t1 > 0)
		return (new_intersec(data.t1, s, f));
	return (new_intersec(0, s, f));
}

t_intersect	*intersect_world(t_word w, t_ray r, int n_object, t_free **f)
{
	t_intersect	*xs;
	t_intersect	*new;
	int			i;

	i = 0;
	xs = NULL;
	while (i < n_object)
	{
		if (w.s[i].obj == sph)
			new = sphere_intersect(w.s[i], r, f);
		else if (w.s[i].obj == pla)
			new = new_intersec(plan_intersect(w.s[i], r, f), w.s[i], f);
		else if (w.s[i].obj == cyl)
			new = cyl_intersect(w.s[i], r, f);
		else if (w.s[i].obj == cub)
			new = cube_intersect(w.s[i], r, f);
		else if (w.s[i].obj == con)
			new = cone_intersect(w.s[i], r, f);
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
