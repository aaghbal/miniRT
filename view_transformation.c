/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_transformation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghbal <aaghbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 11:04:38 by aaghbal           #+#    #+#             */
/*   Updated: 2023/10/09 20:27:45 by aaghbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	**orientation(t_vector left, t_vector true_up, t_vector forward)
{
	double	**m;

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
	return (m);
}

double	**view_transformation(t_point from, t_point to, t_vector up)
{
	t_vector	forward;
	t_vector	upn;
	t_vector	left;
	t_vector	true_up;
	double		**res;

	forward = normalize(sub_to_point(to, from));
	upn = normalize(up);
	left = cross_product(forward, upn);
	true_up = cross_product(left, forward);
	res = multiple_matrice(orientation(left, true_up, forward),
			translation(from.x * -1, from.y * -1, from.z * -1));
	return (res);
}
