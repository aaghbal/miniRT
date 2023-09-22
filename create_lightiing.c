/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_lightiing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghbal <aaghbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 16:35:35 by aaghbal           #+#    #+#             */
/*   Updated: 2023/09/22 10:59:11 by aaghbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"



int main()
{	
	t_mlx *mlx = mlx_init(WIDTH, HEIGHT, "test", true);
	t_mlx_image *img = mlx_new_image(mlx, WIDTH, HEIGHT);
	mlx_image_to_window(mlx, img, 0, 0);
	t_sphere sp;
	t_tuple light_pos = create_tuple(0, 10, -10, 1);
	t_tuple light_col = create_tuple(1 ,1, 1, 1);
	t_light light = point_light(light_pos, light_col);
	sp.materia.color = create_tuple(1, 0.2, 1, 1);
	sp.materia.ambient = 0.1;
	sp.materia.diffuse = 0.9;
	sp.materia.specular = 0.9;
	sp.materia.shininess = 10.0;
	sp.trans = identity();
	float i = 0;
	float j = 0;
	double x, y;
	t_tuple pos;
	t_ray r = ray(create_tuple(0, 0, -5, 1),create_tuple(0, 0, 1, 0));
	t_ray r2;
	while (i < HEIGHT)
	{
		x = mx(i);
		j = 0;
		while (j < WIDTH)
		{
			y = my(j);
			pos = create_tuple(x, y, 10, 1);
			r2 = ray(r.origine, normali(substraction(pos, r.origine)));
			t_intersect xs = calculate_intersect(sp, r2);
			if (xs.xs[0] != -1)
			{
				t_tuple point = positione(r2, hit(&xs, 1));
				t_tuple norm = normal_at(&sp, point);
				t_tuple eye = multip(r2.direction, -1);
				t_tuple color = lighting(sp.materia, light, point, eye, norm);
				mlx_putpixel(img, i, j, conv_color(color.x, color.y, color.z));
			}
			else
				mlx_putpixel(img, i, j, conv_color(1, 1, 1));
				
			j++;
		}
		i++; 
	}
	mlx_loop(mlx);	
}

int main()
{
	int i = 0;
	int j;
	t_canvas c = create_canvas(1000, 1000);
	t_mlx *mlx = mlx_init(c.width, c.height, "test", true);
	t_mlx_image *img = mlx_new_image(mlx, c.width, c.height);
	mlx_image_to_window(mlx, img, 0, 0);
	t_sphere s = sphere();
	s.m.color = create_color(1, 0.9, 0.9);
	s.trans = scaling(10, 0.01, 10);
	s.m.specular = 0;
	t_light l = point_light(create_point(-10, -10, -10), create_color(1, 1, 1));
	while (i < c.width)
	{
		double x = mx(i);
		j = 0;
		while (j < c.height)
		{
			double y = mx(j);
			t_ray r = ray(create_point(0, 0, -5), normalize(sub_to_point(create_point(x, y, 10),create_point(0, 0, -5))));
			t_intersect *res = intersect(s, r);
			t_point point = position(r, res->min);
			t_vector normal = normal_at(&res->s, point);
			t_vector eye = negating_vect(r.direction);
			t_color ca = lighting(res->s.m, l, point, eye, normal);
			if (res->min)
				mlx_putpixel(img, i, j, conv_color(ca.red, ca.green, ca.blue));
			else
				mlx_putpixel(img, i, j, conv_color(0, 0, 0));
				
			j++;
		}
		i++;
	}
	mlx_loop(mlx);
	// printf("d   (%.f, %.f, %.f, %.f)\n", r2.direction.x, r2.direction.y, r2.direction.z, r2.direction.w);
}