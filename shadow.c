/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghbal <aaghbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 10:20:42 by aaghbal           #+#    #+#             */
/*   Updated: 2023/09/24 22:00:27 by aaghbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool is_shadowed(t_word w, t_point point, int n_obj, t_light l)
{
	t_vector v;
	double distance;
	t_vector direction;
	t_ray r;
	t_intersect *xs;
	t_intersect h;
	
	v = sub_to_point(l.position, point);
	distance = magnitude(v);
	direction = normalize(v);
	r = ray(point , direction);
	xs = intersect_world(w, r, n_obj);
	h = hit(xs);
	if (!equal(h.min, 0) && h.min < distance)
		return (true);
	return (false);
}