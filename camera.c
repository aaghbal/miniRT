/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houmanso <houmanso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 14:33:38 by aaghbal           #+#    #+#             */
/*   Updated: 2023/10/11 14:20:41 by houmanso         ###   ########.fr       */
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
// 	d->img = mlx_new_image(d->mlx, c.vsize, c.hsize);
// 	mlx_image_to_window(d->mlx, d->img, 0, 0);
// 	int i = 0, j;
// 	while (i < c.vsize)
// 	{
// 		j = 0;
// 		while (j < c.hsize)
// 		{
// 			col = color_at(d->w, ray_for_pixel(c, i, j), d->p);
// 			mlx_putpixel(d->img, i, j, conv_color(col.red, col.green,
// 						col.blue));
// 			j++;
// 		}
// 		i++;
// 	}
// }

void	render(t_word w, t_camera ca, t_d_pars p)
{
	t_mlx		*mlx;
	t_mlx_image	*img;
	t_color		c;
	t_d			d;

	d.i = 0;
	mlx = p.mlx;
	img = mlx_new_image(mlx, ca.vsize, ca.hsize);
	mlx_image_to_window(mlx, img, 0, 0);
	while (d.i < ca.vsize)
	{
		d.j = 0;
		while (d.j < ca.hsize)
		{
			c = color_at(w, ray_for_pixel(ca, d.i, d.j), p);
			mlx_putpixel(img, d.i, d.j, conv_color(c.red, c.green, c.blue));
			d.j++;
		}
		d.i++;
	}
	ft_free(FREE, NULL);
	mlx_loop(mlx);
}
