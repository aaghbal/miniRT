/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_computations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghbal <aaghbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 11:51:09 by aaghbal           #+#    #+#             */
/*   Updated: 2023/09/17 12:55:22 by aaghbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_comps prepare_computations(t_oneinters inter, t_ray ray)
{
	t_comps com;

	com.inside = false;
	com.t = inter.inters;  
	com.object = inter.object;
	com.point = positione(ray, com.t);
	com.eyev = multip(ray.direction, -1);
	com.normalv = normal_at(&inter.object.sp, com.point);
	if(dot(com.normalv, com.eyev) < 0)
	{
		com.inside = true;
		com.normalv = multip(com.normalv, -1);
	}
	return (com);
}

t_tuple shade_hit(t_word w, t_comps com, t_min m)
{
	t_tuple col;

	col = lighting(w.sp[m.sp].materia, w.light, com.point, com.eyev, com.normalv);
	return (col);
}