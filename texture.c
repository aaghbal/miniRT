/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houmanso <houmanso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 16:33:51 by houmanso          #+#    #+#             */
/*   Updated: 2023/10/13 19:54:31 by houmanso         ###   ########.fr       */
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

typedef struct s_tools
{
	t_uv			uv;
	t_vector		n_;
	t_vector		pu;
	t_vector		pv;
	t_mlx_texture	*t;
}	t_tools;

t_vector	bump_normal(t_shape s, t_vector n, t_vector eye, t_point p)
{
	int			c[2];
	int			x[2];
	int			y[2];
	double		b_scale[2];
	t_tools		b;

	b.t = s.bumpimg;
	b.uv = s.mapping.uv_map(mul_mat_point(s.ivers_tran, p));
	x[0] = b.uv.u * (b.t->width - 1);
	y[0] = (1 - b.uv.v) * (b.t->height - 1);
	y[1] = (y[0] + 1) % b.t->height;
	x[1] = (x[0] + 1) % b.t->width;
	c[0] = ((int *)b.t->pixels)[x[0] + y[0] * b.t->width] & 255;
	c[1] = ((int *)b.t->pixels)[x[0] + y[1] * b.t->width] & 255;
	b_scale[0] = ((double)c[1] - c[0]) / 9;
	c[1] = ((int *)b.t->pixels)[x[1] + y[0] * b.t->width] & 255;
	b_scale[1] = ((double)c[1] - c[0]) / 9;
	b.pu = cross_product(n, eye);
	b.pv = cross_product(n, b.pu);
	b.n_ = n;
	b.n_ = add_to_vector(b.n_, scaler_vect(cross_product(b.pu, n), b_scale[1]));
	b.n_ = add_to_vector(b.n_, scaler_vect(cross_product(b.pv, n), b_scale[0]));
	return (normalize(b.n_));
}
