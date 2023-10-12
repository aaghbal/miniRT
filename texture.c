/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houmanso <houmanso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 16:33:51 by houmanso          #+#    #+#             */
/*   Updated: 2023/10/12 23:22:44 by houmanso         ###   ########.fr       */
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
	return (pixel_at(s, round(x), round(y)));
}


t_vector	uv_texture_vector(t_shape s, t_uv uv)
{
	t_color		c;
	t_vector	v;

	c = uv_texture_at(s, uv);
	v = create_vector(c.red, c.green, c.blue);
	return (v);
}

t_vector	bump_normal(t_shape s, t_vector n, t_vector eye, t_point p)
{
	t_uv		uv;
	int			c[2];
	int			x[2];
	int			y[2];
	double		b_scale[2];

	uv = s.mapping.uv_map(mul_mat_point(s.ivers_tran, p));
	x[0] = uv.u * (s.img->width - 1);
	y[0] = (1 - uv.v) * (s.img->height - 1);
	y[1] = (y[0] + 1) % s.img->height;
	x[1] = (x[0] + 1) % s.img->width;
	c[0] = ((int *)s.img->pixels)[x[0] + y[0] * s.img->width] & 255;
	c[1] = ((int *)s.img->pixels)[x[0] + y[1] * s.img->width] & 255;
	b_scale[0] = ((double)c[0] - c[1])/3;
	c[1] = ((int *)s.img->pixels)[x[1] + y[0] * s.img->width] & 255;
	b_scale[1] = ((double)c[0] - c[1])/3;

	t_vector v;
	t_vector pu;
	t_vector pv;
	pu = cross_product(n, eye);
	pv = cross_product(n, pu);
	v = n;
	v = add_to_vector(v, scaler_vect(cross_product(pu, n), b_scale[1]));
	v = add_to_vector(v, scaler_vect(cross_product(pv, n), b_scale[0]));
	return (normalize(v));
}



