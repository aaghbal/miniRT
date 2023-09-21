/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghbal <aaghbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 13:05:10 by aaghbal           #+#    #+#             */
/*   Updated: 2023/09/21 14:30:37 by aaghbal          ###   ########.fr       */
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


// float dot(t_tuple v1, t_tuple v2)
// {
// 	float res;
// 	res = (v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z);
// 	return (res);
// }

// t_intersect calculate_intersect(t_sphere sp, t_ray ra)
// {
// 	t_intersect res;
// 	t_ray ray;
// 	float **inv;
// 	inv = inverse_matrix(sp.trans, 4, 4);
// 	ray = transform(ra, inv);
// 	t_tuple sph_to_ray = substraction(ray.origine, create_tuple(0, 0, 0, 1));
// 	float a = dot(ray.direction, ray.direction);
// 	float b = 2 * dot(ray.direction, sph_to_ray);
// 	float c = dot (sph_to_ray, sph_to_ray) - 1;
// 	float discr = pow(b, 2) - 4 * a * c;
// 	if (discr < 0)
// 	{
// 		res.xs[0] = -1;
// 		res.xs[1] = -1;
// 		res.count = 0;
// 		res.id = sp;
// 		return (res);
// 	}
// 	float t1 = (-b - sqrt(discr)) / (2 * a); 
// 	float t2 = (-b + sqrt(discr)) / (2 * a);
// 	res.xs[0] = t1;
// 	res.xs[1] = t2;
// 	res.count = 2;
// 	res.id = sp;
// 	return (res); 
// }

// t_oneinters one_intersection(float inter, t_sphere sph)
// {
// 	t_oneinters i;
// 	i.object.sp = sph;
// 	i.inters = inter;
// 	return (i);
// }

// t_intersections *all_intersection(t_oneinters t1, t_oneinters t2)
// {
// 	t_intersections *res = malloc(sizeof(t_intersections) * 2);
// 	res[0].interss = malloc(sizeof(t_oneinters) * 2);
// 	res[1].interss = malloc(sizeof(t_oneinters) * 2);
// 	res[0].counter = 2;
// 	res[1].counter = 2;
// 	res[0].interss->inters = t1.inters;
// 	res[1].interss->inters = t2.inters;
// 	return (res);
// }
// t_min min_num(t_intersect *res, int nob)
// {
// 	int i = 0;
// 	t_min m;
	
// 	m.min = -1;
// 	while (i < nob)
// 	{
// 		if (res[i].xs[0] > 0)
// 		{
// 			m.min = res[i].xs[0];
// 			m.sp = i;
// 			break;
// 		}
// 		else if (res[i].xs[1] > 0)
// 		{
// 			m.min = res[i].xs[1];
// 			m.sp = i;
// 			break;
// 		}
// 		i++;
// 	}
// 	return (m);
// }

// t_min hit(t_intersect *res, int nob)
// {
// 	int i;
// 	t_min m;

// 	i = 0;
// 	m = min_num(res, nob);
// 	while (i < nob)
// 	{
// 		if (res[i].xs[0] < 0 &&  res[i].xs[1] < 0)
// 			i++;
// 		else if ((res[i].xs[0] < res[i].xs[1]) && res[i].xs[0] > 0)
// 		{
// 			if (m.min > res[i].xs[0])
// 			{
// 				puts("hhhh");
// 				m.min = res[i].xs[0];
// 				m.sp = i;
// 			}
// 		}
// 		else if ((m.min > res[i].xs[1]) && res[i].xs[1] > 0)
// 		{
// 				puts("dddd");
// 			m.min = res[i].xs[1];
// 			m.sp = i;
// 		}
// 		i++;
// 	}
// 	return(m);
// }

// t_tuple positione(t_ray r, float t)
// {
// 	t_tuple res = add(r.origine, multip(r.direction, t));
// 	return (res);
// }