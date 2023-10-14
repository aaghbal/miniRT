/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houmanso <houmanso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 14:33:38 by aaghbal           #+#    #+#             */
/*   Updated: 2023/10/14 15:24:48 by houmanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_camera	camera(double width, double height, double field_view)
{
	t_camera	c;
	double		half_view;
	double		aspect;

	c.width = width;
	c.height = height;
	c.field_of_view = field_view;
	c.trans = identity();
	c.trans[0][0] = 2;
	half_view = tan(c.field_of_view / 2);
	aspect = c.width / c.height;
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
	c.pixel_size = (c.half_width * 2) / c.width;
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

// void resize(int width, int height, void *v)
// {
// 	t_d			*d;
// 	t_color		col;
// 	t_camera	c;

// 	d = v;
// 	mlx_delete_image(d->mlx, d->img);
// 	c = camera(height, width, M_PI / 3);
// 	c.trans = view_transformation(create_point(0, 5.5, -7), create_point(0, 1,
// 				1), create_vector(0, 1, 0));
// 	d->img = mlx_new_image(d->mlx, c.height, c.width);
// 	mlx_image_to_window(d->mlx, d->img, 0, 0);
// 	int i = 0, j;
// 	while (i < c.height)
// 	{
// 		j = 0;
// 		while (j < c.width)
// 		{
// 			col = color_at(d->w, ray_for_pixel(c, i, j), d->p);
// 			mlx_putpixel(d->img, i, j, conv_color(col.red, col.green,
// 						col.blue));
// 			j++;
// 		}
// 		i++;
// 	}
// }

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
	y_end = da->y_sta + da->c.height / 4;
	while (x < da->c.width)
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
	t_d			d;

	d.i = 0;
	d.mlx = p.mlx;
	d.ca = &ca;
	d.p = &p;
	d.w = &w;
	d.img = mlx_new_image(d.mlx, ca.width, ca.height);
	if (!d.img)
		_err("Something wrong with image");
	mlx_image_to_window(d.mlx, d.img, 0, 0);
	run_workers(d);
	mlx_resize_hook(d.mlx, resize, &d);
	mlx_key_hook(d.mlx, on_click, NULL);
	mlx_loop(d.mlx);
}
