/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghbal <aaghbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 16:33:51 by houmanso          #+#    #+#             */
/*   Updated: 2023/10/11 20:34:34 by aaghbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"


static t_color	int_to_color(int pxl)
{
	t_color			c;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	r = pxl;
	g = pxl >> 8;
	b = pxl >> 16;
	c.red = (double) r / 255;
	c.green = (double) g / 255;
	c.blue = (double) b / 255;
	return (c);
}

static t_color	pixel_at(t_shape s, int u, int v)
{
	t_color	c;
	int		pixel;

	pixel = ((int *)s.img->pixels)[u + v * s.img->width];
	c = int_to_color(pixel);
	return (c);
}

t_color	uv_texture_at(t_shape s, t_uv uv)
{
	int	x;
	int	y;

	x = uv.u * (s.img->width - 1);
	y = (1 - uv.v) * (s.img->height - 1);
	return (pixel_at(s, x, y));
}

