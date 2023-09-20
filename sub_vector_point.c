/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_vector_point.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghbal <aaghbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 11:04:20 by aaghbal           #+#    #+#             */
/*   Updated: 2023/09/20 11:11:57 by aaghbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector sub_to_point(t_point p1, t_point p2)
{
	t_vector v;

	v.x = p1.x - p2.x;
	v.y = p1.y - p2.y;
	v.z = p1.z - p2.z;
	v.w = p1.w - p2.w;
	return (v);
}

t_point sub_point_vect(t_point p, t_vector v)
{
	t_point res;

	res.x = p.x - v.x;
	res.y = p.y - v.y;
	res.z = p.z - v.z;
	res.w = p.w - v.w;
	return (res);
}

t_vector sub_to_vector(t_vector v1, t_vector v2)
{
	t_vector v;

	v.x = v1.x - v2.x;
	v.y = v1.y - v2.y;
	v.z = v1.z - v2.z;
	v.w = v1.w - v2.w;
	return (v);
}