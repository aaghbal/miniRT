/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_at.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghbal <aaghbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 18:35:58 by aaghbal           #+#    #+#             */
/*   Updated: 2023/09/28 18:26:32 by aaghbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector plan_normal_at(t_shape *sp, t_point word_point)
{
	(void)sp;
	(void)word_point;
	return(create_vector(0, 1, 0));
}

t_vector normal_at(t_shape *sp, t_point word_point)
{
	double **inv;
	t_point object_point;
	t_vector object_normal;
	t_vector world_normal;
	t_vector vect;

	inv = inverse_gauss(sp->tranform);
	object_point = mul_mat_point(inv, word_point);
	object_normal = sub_to_point(object_point, create_point(0, 0, 0));
	world_normal = mul_mat_vector(transposing(inv), object_normal);
	world_normal.w = 0;
	vect = normalize(world_normal);
	return (vect);
}

t_vector reflect(t_vector in, t_vector normal)
{
	t_vector mul;
	t_vector ref;
	double dot;

	dot = 2 * dot_product(in , normal);
	mul = scaler_vect(normal, dot);
	ref = sub_to_vector(in, mul);
	return (ref);
}
