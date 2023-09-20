/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_vect_point2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghbal <aaghbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 11:45:42 by aaghbal           #+#    #+#             */
/*   Updated: 2023/09/20 12:17:57 by aaghbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_point div_scaler_point(t_point p, double s)
{
	t_point res;

	res.x = p.x / s;
	res.y = p.y / s;
	res.z = p.z / s;
	res.w = p.w / s;
	return (res);
}

double magnitude(t_vector v)
{
	double res;

	res = (sqrt((v.x * v.x) + (v.y * v.y) + (v.z * v.z) + (v.w * v.w)));
	return (res);
}

t_vector normalize(t_vector v)
{
	t_vector res;
	
	res.x = v.x / magnitude(v);
	res.y = v.y / magnitude(v);
	res.z = v.z / magnitude(v);
	res.w = v.w / magnitude(v);
	return (res);
}

double dot_product(t_vector v1, t_vector v2)
{
	double res;

	res = (v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z) + (v1.w * v2.w);
	return (res);
}

t_vector cross_product(t_vector a, t_vector b)
{
	t_vector res;

	res.x = a.y * b.z - a.z * b.y;
	res.y = a.z * b.x - a.x * b.z;
	res.z = a.x * b.y - a.y * b.x;
	res.w = 0.0;
	return (res);
}