/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghbal <aaghbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 14:33:38 by aaghbal           #+#    #+#             */
/*   Updated: 2023/09/20 10:19:43 by aaghbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"



t_camera constructing_camera(float hsize, float vsize, float field_view)
{
	t_camera c;
	float half_view;
	float aspect;
	

	c.hsize = hsize;
	c.vsize = vsize;
	c.field_of_view = field_view;
	c.transform = identity();
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

t_ray ray_for_pixel(t_camera camera, float px, float py)
{
	float xoffset;
	float yoffset;
	float word_x;
	float word_y;
	t_ray r;
	t_tuple pixel;
	t_tuple origine;
	t_tuple direc;

	xoffset = (px + 0.5) * camera.pixel_size;
	yoffset = (py + 0.5) * camera.pixel_size;
	word_x = camera.half_width - xoffset;
	word_y = camera.half_height - yoffset;
	float **inv = inverse_gausselimination(camera.transform);
	pixel = multiple_tuple(inv, create_tuple(word_x, word_y, -1, 1));
	origine = multiple_tuple(inv, create_tuple(0, 0, 0, 1));
	direc = normali(substraction(pixel, origine));
	r = ray(origine, direc);
	return (r);
}

t_tuple color_at(t_word w, t_ray r)
{
	t_comps com;
	t_tuple col;
	col = create_tuple(0, 0, 0, 1);
	t_intersect *xs = intersect_world(w, r, 2);
	printf("%f  %f\n", xs[0].xs[0], xs[0].xs[1]);
	printf("%f  %f\n", xs[1].xs[0], xs[1].xs[1]);
	// printf("%f  %f\n", xs[2].xs[0], xs[2].xs[1]);
	// printf("%f  %f\n", xs[3].xs[0], xs[3].xs[1]);
	// printf("%f  %f\n", xs[4].xs[0], xs[4].xs[1]);
	// printf("%f  %f\n", xs[5].xs[0], xs[5].xs[1]);
	puts("------------------------------");
	t_min h = hit(xs, 2);
	if (h.min < 0)
		return (col);
	t_oneinters i = one_intersection(h.min, w.sp[h.sp]);
	com = prepare_computations(i, r);
	col = shade_hit(w, com, h);
	return (col);
}

void render(t_camera c, t_word w)
{
	int i;
	int j;
	t_ray r;

	i = 0;
	float x, y;
	t_mlx *mlx = mlx_init(WIDTH, HEIGHT, "test", true);
	t_mlx_image *img = mlx_new_image(mlx, WIDTH, HEIGHT);
	mlx_image_to_window(mlx, img, 0, 0);
	while (i < HEIGHT)
	{
		j = 0;
		x = mx(i);
		while (j < WIDTH)
		{
			y = mx(j);
			r = ray_for_pixel(c, x, y);
			t_tuple col = color_at(w, r);
			mlx_putpixel(img, i, j, conv_color(col.x, col.y, col.z));			
			j++;
		}
		i++; 
	}
	mlx_loop(mlx);
}