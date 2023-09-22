/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghbal <aaghbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 15:08:58 by aaghbal           #+#    #+#             */
/*   Updated: 2023/09/22 15:32:05 by aaghbal          ###   ########.fr       */
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

t_sphere *create_sphere(void)
{
	t_sphere *sp;
	sp = malloc(sizeof(t_sphere) * 1);
	sp[0] = sphere();
	sp[0].m.color = create_color(1,0.9,0.9);
	sp[0].m.specular = 0;
	sp[0].trans = scaling(10, 0.01, 10);
	//////////////////////////////////////
	sp[1] = sphere();
	sp[1].m.color = create_color(1,0.9,0.9);
	sp[1].m.specular = 0;
	double **sc = scaling(10, 0.01, 10);
	double **rx = rotation_x(M_PI / 2);
	double **res1 = multiple_matrice(sc, rx);
	double **ry = rotation_y((M_PI / 4) * -1);
	res1 = multiple_matrice(res1, ry);
	double **tran = translation(0, 0, 5);
	res1 = multiple_matrice(res1, tran);
	sp[1].trans = res1;
	//////////////////////////////////////
	sp[2] = sphere();
	sp[2].m.color = create_color(1,0.9,0.9);
	sp[2].m.specular = 0;
	sc = scaling(10, 0.01, 10);
	rx = rotation_x(M_PI / 2);
	res1 = multiple_matrice(sc, rx);
	ry = rotation_y((-M_PI / 4) * -1);
	res1 = multiple_matrice(res1, ry);
	tran = translation(0, 0, 5);
	res1 = multiple_matrice(res1, tran);
	sp[2].trans = res1;
	// /////////////////////////////////////////
	sp[3] = sphere();
	sp[3].trans = translation(-0.5, 1, 0.5);
	sp[3].m.color = create_color(0.1, 1, 0.5);
	sp[3].m.diffuse = 0.7;
	sp[3].m.specular = 0.3;
	
	// /////////////////////////////////////////
	sp[4] = sphere();
	sp[4].trans = multiple_matrice(translation(1.5, 0.5, -0.5) ,scaling(0.5, 0.5, 0.5));
	sp[4].m.color = create_color(0.5, 1, 0.1);
	sp[4].m.diffuse = 0.7;
	sp[4].m.specular = 0.3;
	// /////////////////////////
	sp[5] = sphere();
	sp[5].trans = multiple_matrice(translation(-1.5, 0.33, -0.75) ,scaling(0.33, 0.33, 0.33));
	sp[5].m.color = create_color(1, 0.8, 0.1);
	sp[5].m.diffuse = 0.7;
	sp[5].m.specular = 0.3;
	return (sp);
}
int main()
{
	t_sphere *s = create_sphere();
	t_light l = point_light(create_point(-10, 10, -10), create_color(1, 1, 1));
	t_word w = word(s, l);
	t_camera c = camera(500, 500, M_PI/ 3);
	c.trans = view_transformation(create_point(0, 1.5, -5), create_point(0, 1, 0), create_vector(0, 1, 0));
	render(c, w);
	// t_ray r = ray_for_pixel(c, 100, 50);
	// printf("o   (%f, %f, %f, %f)\n", r.origine.x, r.origine.y, r.origine.z, r.origine.w);
	// printf("d   (%f, %f, %f, %.f)\n", r.direction.x, r.direction.y, r.direction.z, r.direction.w);
	
	// t_intersect *xs = intersect_world(w, r);
	// int i = 0;
	// while (xs)
	// {
	// 	printf("%d : %f  %f\n",i,  xs->min, xs->max);
	// 	xs = xs->next;
	// 	i++;
	// }
	
}
