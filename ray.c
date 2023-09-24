/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghbal <aaghbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 13:05:10 by aaghbal           #+#    #+#             */
/*   Updated: 2023/09/23 22:32:19 by aaghbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_ray ray(t_point origine, t_vector direc)
{
	t_ray ray;
	ray.origine = origine;
	ray.direction = direc;
	return(ray);
}

t_point position(t_ray ray, double t)
{
	t_point point;

	point.x = ray.origine.x + ray.direction.x * t;
	point.y = ray.origine.y + ray.direction.y * t;
	point.z = ray.origine.z + ray.direction.z * t;
	point.w = ray.origine.w + ray.direction.w * t;
	return (point);
}


t_intersect hit(t_intersect *res)
{
	t_intersect r;

	r.min = __DBL_MAX__;
	while (res)
	{
		if(res->min < r.min && res->min > 0)
		{
			r.min = res->min;
			r.s = res->s;
		}
		res = res->next;
	}
	if(r.min == __DBL_MAX__)
		r.min = 0;
	return(r);
}
