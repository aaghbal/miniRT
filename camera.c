/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghbal <aaghbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 14:33:38 by aaghbal           #+#    #+#             */
/*   Updated: 2023/09/24 16:00:32 by aaghbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"



t_camera camera(double hsize, double vsize, double field_view)
{
	t_camera c;
	double half_view;
	double aspect;
	

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

t_ray ray_for_pixel(t_camera camera, double px, double py)
{
	double xoffset;
	double yoffset;
	double word_x;
	double word_y;
	double **inv;
	t_ray r;
	t_point pixel;
	t_point origine;
	t_vector direc;

	xoffset = (px + 0.5) * camera.pixel_size;
	yoffset = (py + 0.5) * camera.pixel_size;
	word_x = camera.half_width - xoffset;
	word_y = camera.half_height - yoffset;
	inv = inverse_matrix(camera.trans);
	pixel = mul_mat_point(inv, create_point(word_x, word_y, -1));
	origine = mul_mat_point(inv, create_point(0, 0, 0));
	direc = normalize(sub_to_point(pixel, origine));
	r = ray(origine, direc);
	return (r);
}

void render(t_camera c, t_word w)
{
	int i;
	int j;
	t_ray r;

	i = 0;
	// t_canvas image = create_canvas(c.vsize, c.hsize);
	t_mlx *mlx = mlx_init(c.vsize, c.hsize, "test", true);
	t_mlx_image *img = mlx_new_image(mlx, c.vsize, c.hsize);
	mlx_image_to_window(mlx, img, 0, 0);
	while (i < c.vsize)
	{
		j = 0;
		while (j < c.hsize)
		{
			r = ray_for_pixel(c, i, j);
			t_color col = color_at(w, r, 6);
			mlx_putpixel(img, i, j, conv_color(col.red, col.green, col.blue));			
			j++;
		}
		i++; 
	}
	mlx_loop(mlx);
}