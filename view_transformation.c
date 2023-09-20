/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_transformation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghbal <aaghbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 11:04:38 by aaghbal           #+#    #+#             */
/*   Updated: 2023/09/20 10:15:28 by aaghbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

float **orientation(t_tuple left, t_tuple true_up, t_tuple forward)
{
	float **m;

	m = identity();
	m[0][0] = left.x;
	m[0][1] = left.y;
	m[0][2] = left.z;
	m[1][0] = true_up.x;
	m[1][1] = true_up.y;
	m[1][2] = true_up.z;
	m[2][0] = forward.x * -1;
	m[2][1] = forward.y * -1;
	m[2][2] = forward.z * -1;
	return(m);
}

t_tuple cross_product(t_tuple v1, t_tuple v2)
{
	t_tuple res;

	res.x = (v1.y * v2.z) - (v1.z * v2.y);
	res.y = (v1.z * v2.x) - (v1.x * v2.z);
	res.z = (v1.x * v2.y) - (v1.y * v2.x);
	return (res);
}

float **view_transformation(t_tuple from, t_tuple to, t_tuple up)
{
	t_tuple forward;
	t_tuple left;
	t_tuple true_up;
	t_tuple upn;
	float **res;

	forward = normali(substraction(to, from));
	upn = normali(up);
	left = cross_product(forward, upn);
	true_up = cross_product(left, forward);
	res = multiple_matrice(orientation(left, true_up, forward),
			translation(from.x * -1, from.y * -1, from.z * -1));
	return (res);
}