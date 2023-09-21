/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghbal <aaghbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 13:13:33 by aaghbal           #+#    #+#             */
/*   Updated: 2023/09/21 18:15:58 by aaghbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
int main()
{
	t_mlx *mlx = mlx_init(WIDTH, HEIGHT, "test", false);
	t_mlx_image *img = mlx_new_image(mlx, WIDTH, HEIGHT);
	mlx_image_to_window(mlx, img, 0, 0);
	t_sphere sp;
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
					mlx_putpixel(img, i, j, 0xFF0000ff);
			j++;
		}
		i++; 
	}
	mlx_loop(mlx);
}

int main()
{
	t_canvas c = create_canvas(1000, 1000);
	t_mlx *mlx = mlx_init(c.width, c.height, "test", true);
	t_mlx_image *img = mlx_new_image(mlx, c.width, c.height);
	mlx_image_to_window(mlx, img, 0, 0);
	////////////////////////////
	int i = 0;
	int j;
	t_sphere s = sphere();
	print_matrice(s.sp);
	while (i < c.width)
	{
		double x = mx(i);
		j = 0;
		while (j < c.height)
		{
			double y = mx(j);
			printf("%f  %f\n", x, y);
			t_ray r = ray(create_point(0, 0, -5), normalize(sub_to_point(create_point(x, y, 10),create_point(0, 0, -5))));
			t_intersect *res = intersect(s, r);
			// printf("%f  %f\n", res->min, res->max);
			if (res->min)
				mlx_putpixel(img, i, j, conv_color(1, 0, 0));
			else
				mlx_putpixel(img, i, j, conv_color(0, 0, 0));
				
			j++;
		}
		i++;
	}
	mlx_loop(mlx);
	// printf("O   (%.f, %.f, %.f, %.f)\n", r2.origine.x, r2.origine.y, r2.origine.z, r2.origine.w);
	// printf("d   (%.f, %.f, %.f, %.f)\n", r2.direction.x, r2.direction.y, r2.direction.z, r2.direction.w);
}

	// d[0][0] = 8;
	// d[0][1] = -5;
	// d[0][2] = 9;
	// d[0][3] = 2;
	// d[1][0] = 7;
	// d[1][1] = 5;
	// d[1][2] = 6;
	// d[1][3] = 1;
	// d[2][0] = -6;
	// d[2][1] = 0;
	// d[2][2] = 9;
	// d[2][3] = 6;
	// d[3][0] = -3;
	// d[3][1] = 0;
	// d[3][2] = -9;
	// d[3][3] = -4;