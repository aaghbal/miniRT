/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ocluck.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghbal <aaghbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 18:38:14 by aaghbal           #+#    #+#             */
/*   Updated: 2023/09/20 19:51:05 by aaghbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int main()
{
	int i = 0;
	float tuple[4];
	float *res;
	t_point p;
	t_point p2;
	p2.x = 0;
	p2.y = 1;
	p.x = 0;
	p.y = 0;
	p2.z = p.z = 0;
	tuple[0] = p2.x;
	tuple[1] = p2.y;
	tuple[2] = p2.z;
	tuple[3] = 1;
	t_mlx* mlx;
	mlx = mlx_init(WIDTH, HEIGHT, "minirt", false);
	t_mlx_image *img = mlx_new_image(mlx, WIDTH, HEIGHT);
	mlx_image_to_window(mlx, img, 0, 0);
	mlx_putpixel(img, px(p.x),py(p.y), 0xFF0000ff);
	while (i <= 360)
	{
		res = multiple_tuple(rotation_z(radiane(i)), tuple, 4 , 4);
		mlx_putpixel(img, px(res[0]), py(res[1]), 0xFF0000ff);
		i += 30;
	}
	mlx_loop(mlx);
}


	// t_point p = create_point(0, 0, 0);
	// t_mlx* mlx;
	// mlx = mlx_init(WIDTH, HEIGHT, "minirt", false);
	// t_mlx_image *img = mlx_new_image(mlx, WIDTH, HEIGHT);
	// mlx_image_to_window(mlx, img, 0, 0);
	// mlx_putpixel(img, px(p.x),py(p.y), conv_color(1, 0, 0));
	// int i = 0;
	// while (i <= 360)
	// {
	// 	t_point d = mul_mat_point(rotation_z(radiane(i)), create_point(0, 1, 0));
	// 	mlx_putpixel(img, px(d.x), py(d.y), conv_color(1, 0, 0));
	// 	i += 30;
	// }
	// mlx_loop(mlx);