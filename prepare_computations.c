/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_computations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghbal <aaghbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 11:51:09 by aaghbal           #+#    #+#             */
/*   Updated: 2023/09/22 13:56:00 by aaghbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_comps prepare_computations(t_intersection i, t_ray ray)
{
	t_comps com;

	com.inside = false;
	com.t = i.t;  
	com.obj = i.sp;
	com.point = position(ray, com.t);
	com.eyev = negating_vect(ray.direction);
	com.normalv = normal_at(&com.obj, com.point);
	if(dot_product(com.normalv, com.eyev) < 0)
	{
		com.inside = true;
		com.normalv = negating_vect(com.normalv);
	}
	return (com);
}

t_color shade_hit(t_word w, t_comps com)
{
	t_color col;

	col = lighting(com.obj.m, w.l, com.point, com.eyev, com.normalv);
	return (col);
}