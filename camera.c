/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghbal <aaghbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 14:33:38 by aaghbal           #+#    #+#             */
/*   Updated: 2023/10/09 21:31:38 by aaghbal          ###   ########.fr       */
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

typedef struct s_d
{
	t_word		w;
	t_mlx		*mlx;
	t_mlx_image	*img;
}				t_d;

// void rez(int width, int height, void *v)
// {
// 	t_d *d =v;
// 	t_color		col;
// 	t_camera	c;

// 	mlx_delete_image(d.mlx, d->img);
// 	c = camera(height, width, M_PI / 3);
// 	c.trans = view_transformation(create_point(0, 5.5, -7), create_point(0, 1,
// 				1), create_vector(0, 1, 0));
// 	d->img = mlx_new_image(d->mlx, c.vsize, c.hsize);
// 	mlx_image_to_window(d->mlx, d->img, 0, 0);
// 	int i = 1, j;
// 	while (i < c.vsize)
// 	{
// 		j = 1;
// 		while (j < c.hsize)
// 		{
// 			col = color_at(d->w, ray_for_pixel(c, i, j), 5);
// 			mlx_putpixel(d->img, i, j, conv_color(col.red, col.green,
						// col.blue));
// 			j++;
// 		}
// 		i++;
// 	}
// }

void	render(t_word w, t_camera c, t_d_pars p)
{
	int			i;
	int			j;
	t_mlx		*mlx;
	t_mlx_image	*img;
	t_color		col;
	t_d			d;

	i = 0;
	mlx = mlx_init(WIDTH, HEIGHT, "test", true);
	img = mlx_new_image(mlx, c.vsize, c.hsize);
	mlx_image_to_window(mlx, img, 0, 0);
	while (i < c.vsize)
	{
		j = 0;
		while (j < c.hsize)
		{
			col = color_at(w, ray_for_pixel(c, i, j), p);
			mlx_putpixel(img, i, j, conv_color(col.red, col.green, col.blue));
			j++;
		}
		i++;
	}
	d.img = img;
	d.mlx = mlx;
	d.w = w;
	// mlx_resize_hook(mlx, rez, &d);
	puts("llklk");
	ft_free(FREE, NULL);
	system("leaks miniRT");
	mlx_loop(mlx);
}
