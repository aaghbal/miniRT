/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_ray.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghbal <aaghbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 10:47:36 by aaghbal           #+#    #+#             */
/*   Updated: 2023/09/27 13:01:22 by aaghbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// t_ray transform(t_ray ray, float **m)
// {
// 	t_ray ray2;
// 	ray2.origine = multiple_tuple(m, ray.origine);
// 	ray2.direction = multiple_tuple(m, ray.direction);
// 	return(ray2);
// }

// void set_transformation(t_shape *sp, float **t)
// {
// 	sp->trans = t;
// }

// t_tuple normal_at(t_shape *sp, t_tuple word_point)
// {
// 	t_tuple obj_point;
// 	t_tuple obj_normal;
// 	t_tuple word_normal;

// 	obj_point = multiple_tuple(inverse_gausselimination(sp->trans),word_point);
// 	obj_normal = substraction(obj_point, create_tuple(0, 0, 0, 1));
// 	word_normal =multiple_tuple(Transposing_Matrices(inverse_gausselimination(sp->trans)),obj_normal);
// 	word_normal.w = 0;
// 	return (word_normal);
// }

// t_tuple reflect(t_tuple in, t_tuple normal)
// {
// 	t_tuple mul;
// 	t_tuple res;

// 	mul = multip(normal, 2 * dot(in , normal));
// 	res = substraction(in, mul);
// 	return (res);
// }