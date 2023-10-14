/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghbal <aaghbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 14:33:38 by aaghbal           #+#    #+#             */
/*   Updated: 2023/10/14 15:32:48 by aaghbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_camera	camera(double hsize, double vsize, double field_view)
{
	t_camera	c;
	double		half_view;
	double		aspect;

	c.hsize = hsize;
	c.vsize = vsize;
	c.field_of_view = field_view;
	c.trans = identity();
	half_view = tan(c.field_of_view / 2);
	aspect = c.hsize / c.vsize;
	if (aspect >= 1)
	{
		c.half_width = half_view;
		c.half_height = half_view / aspect;
	}
	else
	{
		c.half_width = half_view * aspect;
		c.half_height = half_view;
	}
	c.pixel_size = (c.half_width * 2) / c.hsize;
	return (c);
}

t_ray	ray_for_pixel(t_camera camera, double px, double py)
{
	t_pixel		data;
	t_ray		r;
	t_point		pixel;
	t_point		origine;
	t_vector	direc;

	data.xoffset = (px + 0.5) * camera.pixel_size;
	data.yoffset = (py + 0.5) * camera.pixel_size;
	data.word_x = camera.half_width - data.xoffset;
	data.word_y = camera.half_height - data.yoffset;
	data.inv = camera.inverse;
	pixel = mul_mat_point(data.inv, create_point(data.word_x, data.word_y, -1));
	origine = mul_mat_point(data.inv, create_point(0, 0, 0));
	direc = normalize(sub_to_point(pixel, origine));
	r = ray(origine, direc);
	return (r);
}

t_tr	prepare_thr(t_word w, t_camera ca, t_d_pars p, t_mlx_image	*img)
{
	t_tr	data;

	data.img = img;
	data.w = w;
	data.c = ca;
	data.p = p;
	return (data);
}

void	*rotine(void *d)
{
	t_tr	*da;
	int		y_end;
	t_color	c;
	int		y;
	int		x;

	x = 0;
	da = (t_tr *)d;
	y_end = da->y_sta + HEIGHT / 4;
	while (x < da->c.hsize)
	{
		y = da->y_sta;
		while (y < y_end)
		{
			c = color_at(da->w, ray_for_pixel(da->c, x, y), da->p);
			mlx_putpixel(da->img, x, y, conv_color(c.red, c.green, c.blue));
			y++;
		}
		x++;
	}
	return (NULL);
}

void	render(t_word w, t_camera ca, t_d_pars p)
{
	t_mlx		*mlx;
	t_mlx_image	*img;
	t_d			d;
	pthread_t	thr[4];
	t_tr		data[4];

	d.i = 0;
	mlx = p.mlx;
	img = mlx_new_image(mlx, ca.vsize, ca.hsize);
	if (!img)
		_err("Something wrong with image");
	mlx_image_to_window(mlx, img, 0, 0);
	d.y_start = 0;
	while (d.i < 4)
	{
		data[d.i] = (t_tr){mlx, img, d.y_start, w, ca, p};
		d.y_start += HEIGHT / 4;
		pthread_create(&thr[d.i], NULL, rotine, &(data[d.i]));
		d.i++;
	}
	d.i = 0;
	while (d.i < 4)
		pthread_join(thr[d.i++], NULL);
	ft_free(FREE, NULL);
	mlx_loop(mlx);
}
