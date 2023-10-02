/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_at.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghbal <aaghbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 13:43:20 by aaghbal           #+#    #+#             */
/*   Updated: 2023/10/02 13:24:39 by aaghbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color	color_at(t_word w, t_ray r, int n_object)
{
	t_comps			c;
	t_intersection	i;
	t_color			col;
	t_intersect		*xs;
	t_intersect		h;

	col = create_color(0, 0, 0);
	xs = intersect_world(w, r, n_object);
	h = hit(xs);
	if (equal(h.min, 0))
		return (create_color(0, 0, 0));
	i = intersection(h.min, h.s);
	c = prepare_computations(i, r);
	col = shade_hit(w, c, n_object);
	return (col);
}

unsigned char	float_to_char(float n)
{
	if (n < 0)
		n = 0.0;
	else if (n > 1)
		n = 1.0;
	return ((unsigned char)ceil(n * 255));
}

unsigned int	conv_color(double r, double g, double b)
{
	unsigned char	rc;
	unsigned char	gc;
	unsigned char	bc;
	unsigned int	final_color;

	final_color = 0;
	rc = float_to_char(r);
	gc = float_to_char(g);
	bc = float_to_char(b);
	final_color |= (rc << 24);
	final_color |= (gc << 16);
	final_color |= (bc << 8);
	final_color |= 255;
	return (final_color);
}
