/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghbal <aaghbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 14:33:38 by aaghbal           #+#    #+#             */
/*   Updated: 2023/10/02 13:17:02 by aaghbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_camera	camera(double hsize, double vsize, double field_view, t_free **f)
{
	t_camera	c;
	double		half_view;
	double		aspect;

	c.hsize = hsize;
	c.vsize = vsize;
	c.field_of_view = field_view;
	c.trans = identity(f);
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

t_ray	ray_for_pixel(t_camera camera, double px, double py, t_free **f)
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
	data.inv = inverse_gauss(camera.trans, f);
	pixel = mul_mat_point(data.inv, create_point(data.word_x, data.word_y, -1));
	origine = mul_mat_point(data.inv, create_point(0, 0, 0));
	direc = normalize(sub_to_point(pixel, origine));
	r = ray(origine, direc);
	return (r);
}

void	render(t_camera c, t_word w, t_free **f)
{
	int			i;
	int			j;
	t_mlx		*mlx;
	t_mlx_image	*img;
	t_color		col;

	i = 0;
	mlx = mlx_init(c.vsize, c.hsize, "test", true);
	img = mlx_new_image(mlx, c.vsize, c.hsize);
	mlx_image_to_window(mlx, img, 0, 0);
	while (i < c.vsize)
	{
		j = 0;
		while (j < c.hsize)
		{
			col = color_at(w, ray_for_pixel(c, i, j, f), 5, f);
			mlx_putpixel(img, i, j, conv_color(col.red, col.green, col.blue));
			j++;
		}
		i++;
	}
	free_all(*f);
	system("leaks minirt");
	mlx_loop(mlx);
}
