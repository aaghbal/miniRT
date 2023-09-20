/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghbal <aaghbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 13:13:33 by aaghbal           #+#    #+#             */
/*   Updated: 2023/09/15 14:23:04 by aaghbal          ###   ########.fr       */
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