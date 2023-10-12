/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_at.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houmanso <houmanso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 18:35:58 by aaghbal           #+#    #+#             */
/*   Updated: 2023/10/12 13:34:31 by houmanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector	cyl_normal_at(t_shape s, t_point word_point)
{
	double		dist;
	double		**inv;
	t_point		obj_point;
	t_vector	w_normal;
	t_vector	o_normal;

	(void)s;
	inv = inverse_gauss(s.tranform);
	obj_point = mul_mat_point(inv, word_point);
	dist = obj_point.x * obj_point.x + obj_point.z * obj_point.z;
	if (dist < 1 && obj_point.y >= s.max - EPSILON)
		o_normal = create_vector(0, 1, 0);
	else if (dist < 1 && obj_point.y <= s.min + EPSILON)
		o_normal = create_vector(0, -1, 0);
	else
		o_normal = create_vector(obj_point.x, 0, obj_point.z);
	inv = transposing(inv);
	w_normal = mul_mat_vector(inv, o_normal);
	w_normal.w = 0;
	return (normalize(w_normal));
}

t_vector	plan_normal_at(t_shape *sp, t_point word_point)
{
	double		**inv;
	t_vector	world_normal;
	t_vector	vect;
	t_vector	bump;

	(void)word_point;
	inv = sp->ivers_tran;
	world_normal = mul_mat_vector(transposing(inv), create_vector(0, 1, 0));
	world_normal.w = 0;
	vect = normalize(world_normal);
	bump = normalize(create_vector(.1, .2, 0));
	t_vector tmp = normalize(create_vector(
		vect.x * bump.z * 0.2,
		vect.y * bump.x * 0.2,
		vect.z * bump.y * 0.2
	));
	return (tmp);
}

t_vector	sphere_normal_at(t_shape *sp, t_point word_point)
{
	double		**inv;
	t_point		object_point;
	t_vector	object_normal;
	t_vector	world_normal;
	t_vector	vect;

	inv = sp->ivers_tran;
	object_point = mul_mat_point(inv, word_point);
	object_normal = sub_to_point(object_point, create_point(0, 0, 0));
	world_normal = mul_mat_vector(transposing(inv), object_normal);
	world_normal.w = 0;
	vect = normalize(world_normal);
	t_vector new_normal;
	new_normal = normalize(create_vector(
		vect.x + sin(vect.z * 100.0) * 0.2,
		vect.y + sin(vect.x * 100.0) * 0.2,
		vect.z + sin(vect.y * 100.0) * 0.2
	));
	return (new_normal);
}

t_vector	reflect(t_vector in, t_vector normal)
{
	t_vector	mul;
	t_vector	ref;
	double		dot;

	dot = 2 * dot_product(in, normal);
	mul = scaler_vect(normal, dot);
	ref = sub_to_vector(in, mul);
	return (ref);
}

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
