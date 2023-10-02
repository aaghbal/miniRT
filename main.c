/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghbal <aaghbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 15:08:58 by aaghbal           #+#    #+#             */
/*   Updated: 2023/10/02 13:18:14 by aaghbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	print_matrice(double **m)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			printf("%.5f  ", m[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

t_shape	*create_shape(t_free **f)
{
	t_shape	*sp;

	sp = malloc(sizeof(t_shape) * 5);
	add_addr(f, new_addr(sp));
	sp[0] = test_shape(f);
	sp[0].tranform = scaling(10, 0.01, 10, f);
	sp[0].m.color = create_color(1, 0.9, 0.9);
	sp[0].m.specular = 0.0;
	sp[0].obj = pla;
	// /////////////////////////////////////////
	sp[1] = test_shape(f);
	sp[1].closed = true;
	sp[1].raduis = 1;
	sp[1].min = 0;
	sp[1].max = 3;
	sp[1].m.color = create_color(1, 1, 0);
	sp[1].obj = cyl;
	// /////////////////////////////////////////
	sp[2] = test_shape(f);
	sp[2].tranform = multiple_matrice(translation(1.5, 0.5, -0.5, f), scaling(0.5,
				0.5, 0.5, f), f);
	sp[2].closed = true;
	sp[2].raduis = 2;
	sp[2].min = -2;
	sp[2].max = 2;
	sp[2].m.color = create_color(0.5, 1, 0.1);
	sp[2].obj = cyl;
	// /////////////////////////
	sp[3] = test_shape(f);
	sp[3].raduis = 2;
	sp[3].closed = true;
	sp[3].tranform = multiple_matrice(translation(-1.5, 0.33, -0.75, f),
			scaling(0.33, 0.33, 0.33, f), f);
	sp[3].m.color = create_color(1, 0.8, 0.1);
	sp[3].min = -2;
	sp[3].max = 1;
	sp[3].obj = cyl;
	// /////////////////////////
	sp[4] = test_shape(f);
	sp[4].tranform = multiple_matrice(translation(0, 3, 0, f), scaling(1, 1, 1, f), f);
	sp[4].m.color = create_color(1, 0, 0);
	sp[4].obj = cub;
	return (sp);
}
int	main(void)
{
	t_shape		*s;
	t_light		*l;
	t_word		w;
	t_camera	c;
	t_free		*f;

	f = NULL;
	s = create_shape(&f);
	l = malloc(sizeof(t_light) * 2);
	add_addr(&f, new_addr(l));
	l[0] = point_light(create_point(-10, 10, -10), create_color(1, 1, 1));
	l[1] = point_light(create_point(10, 10, -10), create_color(0, 0, 1));
	w = word(s, l);
	c = camera(500, 500, M_PI / 3, &f);
	c.trans = view_transformation(create_point(0, 5.5, -7), create_point(0, 1,
				1), create_vector(0, 1, 0), &f);
	render(c, w, &f);
	// t_shape s = test_shape();
	// t_intersect *xs = cube_intersect(s, ray(create_point(-2, 0, 0), create_vector(0.2673, 0.5345, 0.8018)));
	// printf ("%f  \n", xs->min);
	// t_word w = default_word();
	// t_point point = create_point(-2, 2, -2);
	// printf("is %d\n", is_shadowed(w, point, 2));
	// t_camera c = camera(800, 800, M_PI/ 3);
	// c.trans = view_transformation(create_point(0, 1.5, -5), create_point(0,
				// 1, 0), create_vector(0, 1, 0));
	// render(c, w);
	// t_ray r = ray_for_pixel(c, 100, 50);
	// t_intersect *xs = intersect_world(w, r);
	// int i = 0;
	// while (xs)
	// {
	// 	printf("%d : %f  %f\n",i,  xs->min, xs->max);
	// 	xs = xs->next;
	// 	i++;
	// }
	// int main()
	// {
	// double **m = identity();
	// m[0][0] =  -5;
	// m[0][1] =  2;
	// m[0][2] =  6;
	// m[0][3] =  -8;
	// m[1][0] =  1;
	// m[1][1] =  -5;
	// m[1][2] =  1;
	// m[1][3] =  8;
	// m[2][0] =  7;
	// m[2][1] =  7;
	// m[2][2] =  -6;
	// m[2][3] =  -7;
	// m[3][0] =  1;
	// m[3][1] =  -3;
	// m[3][2] =  7;
	// m[3][3] =  4;
	// // double **n = identity();
	// // for (int i = 0; i < 4; i++)
	// // 	for (int j = 0; j < 4; j++)
	// // 		n[i][j] = m[i][j];
	// double **res = inverse_gauss(m);
	// print_matrice(res);
	// puts("---------------------");
	// print_matrice(m);
}
