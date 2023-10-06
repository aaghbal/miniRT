/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_at.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghbal <aaghbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 18:35:58 by aaghbal           #+#    #+#             */
/*   Updated: 2023/10/06 17:34:16 by aaghbal          ###   ########.fr       */
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

	(void)word_point;
	inv = inverse_gauss(sp->tranform);
	world_normal = mul_mat_vector(transposing(inv), create_vector(0, 1, 0));
	world_normal.w = 0;
	vect = normalize(world_normal);
	return (vect);
}

t_vector	sphere_normal_at(t_shape *sp, t_point word_point)
{
	double		**inv;
	t_point		object_point;
	t_vector	object_normal;
	t_vector	world_normal;
	t_vector	vect;

	inv = inverse_gauss(sp->tranform);
	object_point = mul_mat_point(inv, word_point);
	object_normal = sub_to_point(object_point, create_point(0, 0, 0));
	world_normal = mul_mat_vector(transposing(inv), object_normal);
	world_normal.w = 0;
	vect = normalize(world_normal);
	return (vect);
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
