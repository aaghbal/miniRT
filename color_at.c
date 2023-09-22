/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_at.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghbal <aaghbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 13:43:20 by aaghbal           #+#    #+#             */
/*   Updated: 2023/09/22 16:01:35 by aaghbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color color_at(t_word w, t_ray r)
{
	t_comps c;
	t_intersection i;
	t_color col;
	t_intersect *xs;
	t_intersect h;

	col = create_color(0, 0, 0);
	xs = intersect_world(w, r);
	h = hit(xs);
	printf("hit %f\n", h.min);
	puts("********************");
	if (h.min == 0)
		return (col);
	i = intersection(h.min, h.s);	
	c = prepare_computations(i, r);
	col = shade_hit(w, c);
	return (col);
}