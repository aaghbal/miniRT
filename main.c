/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghbal <aaghbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 15:08:58 by aaghbal           #+#    #+#             */
/*   Updated: 2023/09/27 18:57:56 by aaghbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void print_matrice(double **m)
{
	int i = 0;
	int j = 0;

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

t_shape *create_shape(void)
{
	t_shape *sp;
	sp = malloc(sizeof(t_shape) * 6);
	sp[0] = test_shape();
	sp[0].m.color = create_color(1,0.9,0.9);
	sp[0].m.specular = 0;
	sp[0].tranform = scaling(10, 0.01, 10);
	//////////////////////////////////////
	sp[1] = test_shape();
	sp[1].m.color = create_color(1,0.9,0.9);
	sp[1].m.specular = 0;
	double **tran = translation(0, 0, 5);
	double **ry = rotation_y(((M_PI * -1) / 4));
	double **res1 = multiple_matrice(tran, ry);
	double **rx = rotation_x(M_PI / 2);
	res1 = multiple_matrice(res1, rx);
	double **sc = scaling(10, 0.01, 10);
	res1 = multiple_matrice(res1, sc);
	sp[1].tranform = res1;
	//////////////////////////////////////
	sp[2] = test_shape();
	sp[2].m.color = create_color(1,0.9,0.9);
	sp[2].m.specular = 0;
	tran = translation(0, 0, 5);
	ry = rotation_y((M_PI / 4));
	res1 = multiple_matrice(tran, ry);
	rx = rotation_x(M_PI / 2);
	res1 = multiple_matrice(res1, rx);
	sc = scaling(10, 0.01, 10);
	res1 = multiple_matrice(res1, sc);
	sp[2].tranform = res1;
	// /////////////////////////////////////////
	sp[3] = test_shape();
	sp[3].tranform = translation(-0.5, 1, 0.5);
	sp[3].m.color = create_color(0.1, 1, 0.5);
	sp[3].m.diffuse = 0.7;
	sp[3].m.specular = 0.3;
	
	// /////////////////////////////////////////
	sp[4] = test_shape();
	sp[4].tranform = multiple_matrice(translation(1.5, 0.5, -0.5) ,scaling(0.5, 0.5, 0.5));
	sp[4].m.color = create_color(0.5, 1, 0.1);
	sp[4].m.diffuse = 0.7;
	sp[4].m.specular = 0.3;
	// /////////////////////////
	sp[5] = test_shape();
	sp[5].tranform = scaling(1.5, 0.5, 0.5);//multiple_matrice(translation(-1.5, 0.33, -0.75) ,scaling(0.33, 0.33, 0.33));
	sp[5].m.color = create_color(1, 0.8, 0.1);
	sp[5].m.diffuse = 0.7;
	sp[5].m.specular = 0.3;
	return (sp);
}
int main()
{
	t_shape *s = create_shape();
	t_light *l = malloc(sizeof(t_light) * 2);
	l[0] = point_light(create_point(-10, 10, -10), create_color(1, 1, 1));
	l[1] = point_light(create_point(10, 10, -10), create_color(0.5, 0.5, 0.5));
	t_word w = word(s, l);
	t_camera c = camera(500, 500, M_PI/ 3);
	c.trans = view_transformation(create_point(0, 2.5, -3), create_point(0,-1, 0), create_vector(0, 1, 0));
	 render(c, w);
	
	// t_word w = default_word();
	// t_point point = create_point(-2, 2, -2);
	// printf("is %d\n", is_shadowed(w, point, 2));
	// t_camera c = camera(800, 800, M_PI/ 3);
	// c.trans = view_transformation(create_point(0, 1.5, -5), create_point(0, 1, 0), create_vector(0, 1, 0));
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
