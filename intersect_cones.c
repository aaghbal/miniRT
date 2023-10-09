/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cones.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghbal <aaghbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 17:31:31 by aaghbal           #+#    #+#             */
/*   Updated: 2023/10/08 21:40:34 by aaghbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector	cone_normal_at(t_shape s, t_point word_point)
{
	double		dist;
	double		**inv;
	t_point		obj_point;
	t_vector	w_normal;
	t_vector	o_normal;

	inv = inverse_gauss(s.tranform);
	obj_point = mul_mat_point(inv, word_point);
	dist = obj_point.x * obj_point.x + obj_point.z * obj_point.z;
	if (dist < 1 && obj_point.y >= s.max - EPSILON)
		o_normal = create_vector(0, 1, 0);
	else if (dist < 1 && obj_point.y <= s.min + EPSILON)
		o_normal = create_vector(0, -1, 0);
	else
	{
		if (obj_point.y > 0)
			o_normal = create_vector(obj_point.x, -sqrt(dist), obj_point.z);
		else
			o_normal = create_vector(obj_point.x, sqrt(dist), obj_point.z);
	}
	inv = transposing(inv);
	w_normal = mul_mat_vector(inv, o_normal);
	w_normal.w = 0;
	return (normalize(w_normal));
}

// t_vector	cone_normal_at(t_shape s, t_point word_point)
// {
// 	double		dist;
// 	double		**inv;
// 	t_point		obj_point;
// 	t_vector	w_normal;

// 	(void)s;
// 	inv = inverse_gauss(s.tranform);
// 	obj_point = mul_mat_point(inv, word_point);
// 	dist = pow(obj_point.x, 2) + pow(obj_point.z, 2);
// 	if (dist < 1 && obj_point.y >= s.max - EPSILON)
// 		w_normal = create_vector(0, 1, 0);
// 	else if (dist < 1 && obj_point.y <= s.min + EPSILON)
// 		w_normal = create_vector(0, -1, 0);
// 	else
// 	{
// 		if (obj_point.y > 0)
// 			w_normal = create_vector(obj_point.x, -sqrt(dist), obj_point.z);
// 		else
// 			w_normal = create_vector(obj_point.x, sqrt(dist), obj_point.z);
// 	}
// 	w_normal.w = 0;
// 	return (normalize(w_normal));
// }

bool	check_cap_cone(t_ray r, double t)
{
	double	x;
	double	z;

	x = r.origine.x + t * r.direction.x;
	z = r.origine.z + t * r.direction.z;
	return (x * x + z * z <= 1);
}

// t_intersect	*intersect_caps_cone(t_shape s, t_ray r, t_intersect **xs)
// {
// 	double	t;

// 	if (equal(r.direction.y, 0))
// 		return (*xs);
// 	t = (s.min - r.origine.y) / r.direction.y;
// 	if (check_cap_cone(r, t, s.raduis))
// 	{
// 		if ((*xs)->min == 0)
// 			(*xs)->min = t;
// 		else if (t > (*xs)->min)
// 			add_back(xs, new_intersec(t, s));
// 		else
// 			add_front(xs, new_intersec(t, s));
// 	}
// 	t = (s.max - r.origine.y) / r.direction.y;
// 	if (check_cap_cone(r, t, s.raduis))
// 	{
// 		if ((*xs)->min == 0)
// 			(*xs)->min = t;
// 		else if (t > (*xs)->min)
// 			add_back(xs, new_intersec(t, s));
// 		else
// 			add_front(xs, new_intersec(t, s));
// 	}
// 	return (*xs);
// }

t_intersect	*intersect_caps_cone(t_shape s, t_ray r, t_intersect **xs)
{
	double	t;

	if (equal(r.direction.y, 0))
		return (*xs);
	t = (s.min - r.origine.y) / r.direction.y;
	if (check_cap_cone(r, t))
	{
		if ((*xs)->min == 0)
			(*xs)->min = t;
		else if (t > (*xs)->min)
			add_back(xs, new_intersec(t, s));
		else
			add_front(xs, new_intersec(t, s));
	}
	t = (s.max - r.origine.y) / r.direction.y;
	if (check_cap_cone(r, t))
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
// t_intersect	*cone_intersect(t_shape s, t_ray ray)
// {
// 	t_ray r;
// 	t_data data;
// 	t_intersect *xs;

// 	xs = new_intersec(0, s);
// 	r = transform(ray, inverse_gauss(s.tranform));
// 	data.a = pow(r.direction.x, 2) + ((pow(r.direction.y, 2) * -1))
// 		+ pow(r.direction.z, 2);
// 	data.b = (2 * r.origine.x * r.direction.x) - (2 * r.origine.y
// 			* r.direction.y) + (2 * r.origine.z * r.direction.z);
// 	data.c = pow(r.origine.x, 2) + ((pow(r.origine.y, 2) * -1)
// 			+ pow(r.origine.z, 2));

// 	if (equal(data.a, 0) && equal(data.b, 0))
// 		return (intersect_caps(s, r, &xs));
// 	if (equal(data.a, 0))
// 		return (new_intersec(-data.c / 2 * data.b, s));
// 	data.discr = pow(data.b, 2) - 4 * data.a * data.c;
// 	if (data.discr < 0)
// 		return (xs);
// 	data.t0 = (-data.b - sqrt(data.discr)) / (2 * data.a);
// 	data.t1 = (-data.b + sqrt(data.discr)) / (2 * data.a);
// 	if (data.t0 > data.t1)
// 		ft_swap(&data.t0, &data.t1);
// 	data.y0 = r.origine.y + data.t0 * r.direction.y;
// 	if (data.y0 > s.min && data.y0 < s.max)
// 		xs = new_intersec(data.t0, s);
// 	data.y1 = r.origine.y + data.t1 * r.direction.y;
// 	if (data.y1 > s.min && data.y1 < s.max)
// 		add_back(&xs, new_intersec(data.t1, s));
// 	return (intersect_caps(s, r, &xs), xs);
// }

t_intersect	*cone_intersect(t_shape s, t_ray ray)
{
	t_ray		r;
	t_data		data;
	t_intersect	*xs;
	double		y;

	xs = new_intersec(0, s);
	r = transform(ray, inverse_gauss(s.tranform));
	data.a = pow(r.direction.x, 2) + ((pow(r.direction.y, 2) * -1))
		+ pow(r.direction.z, 2);
	data.b = (2 * r.origine.x * r.direction.x) - (2 * r.origine.y
			* r.direction.y) + (2 * r.origine.z * r.direction.z);
	data.c = pow(r.origine.x, 2) + (pow(r.origine.y, 2) * -1) + pow(r.origine.z,
			2);
	if (equal(data.a, 0) && equal(data.b, 0))
		return (intersect_caps(s, r, &xs));
	if (equal(data.a, 0))
	{
		xs = new_intersec(-data.c / (2 * data.b), s);
		return (intersect_caps_cone(s, r, &xs));
	}
	data.discr = pow(data.b, 2) - 4 * data.a * data.c;
	if (data.discr < 0)
		return (xs);
	y = sqrt(data.discr);
	data.t0 = (-data.b - y) / (2 * data.a);
	data.t1 = (-data.b + y) / (2 * data.a);
	if (data.t0 > data.t1)
		ft_swap(&data.t0, &data.t1);
	data.y0 = r.origine.y + data.t0 * r.direction.y;
	if (data.y0 >= s.min && data.y0 <= s.max && data.t0 > 0)
		xs = new_intersec(data.t0, s);
	data.y1 = r.origine.y + data.t1 * r.direction.y;
	if (data.y1 >= s.min && data.y1 <= s.max && data.t1 > 0)
		add_back(&xs, new_intersec(data.t1, s));
	return (intersect_caps_cone(s, r, &xs), xs);
}
