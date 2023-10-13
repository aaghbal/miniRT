/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houmanso <houmanso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 16:33:51 by houmanso          #+#    #+#             */
/*   Updated: 2023/10/13 13:09:39 by houmanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

typedef struct s_bump
{
	t_vector	n_;
	t_vector	pu;
	t_vector	pv;
	t_uv		uv;
	int			c1;
	int			c2;
	int			x1;
	int			y1;
	int			x2;
	int			y2;
	int			bu;
	int			bv;
}	t_bump;


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


t_vector	bump_normal(t_shape s, t_vector n, t_vector eye, t_point p)
{
	t_bump	b;

	b.uv = s.mapping.uv_map(mul_mat_point(s.ivers_tran, p));
	b.x1 = b.uv.u * (s.img->width - 1);
	b.y1 = (1 - b.uv.v) * (s.img->height - 1);
	b.x2 = (b.x1 + 1) % s.img->width;
	b.y2 = (b.y1 + 1) % s.img->height;
	b.c1 = ((int *)s.img->pixels)[b.x1 + b.y1 * s.img->width] & 255;
	b.c2 = ((int *)s.img->pixels)[b.x1 + b.y2 * s.img->width] & 255;
	b.bu = ((double)(b.c1 - b.c2)) / 3;
	b.c2 = ((int *)s.img->pixels)[b.x2 + b.y1 * s.img->width] & 255;
	b.bv = ((double)(b.c1 - b.c2)) / 3;
	b.pu = cross_product(n, eye);
	b.pv = cross_product(n, b.pu);
	b.n_ = n;
	b.n_ = add_to_vector(b.n_, scaler_vect(cross_product(b.pu, n), b.bu));
	b.n_ = add_to_vector(b.n_, scaler_vect(cross_product(b.pv, n), b.bv));
	return (normalize(b.n_));
}
