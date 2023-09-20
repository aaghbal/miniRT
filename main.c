/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghbal <aaghbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 15:08:58 by aaghbal           #+#    #+#             */
/*   Updated: 2023/09/20 19:51:13 by aaghbal          ###   ########.fr       */
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

double radiane(double deg)
{
	float res;
	res = (deg / 180) * M_PI;
	return (res);
}

int main()
{
	double **d = identity();
	// double **d2 = identity();
	d[0][0] = 8;
	d[0][1] = -5;
	d[0][2] = 9;
	d[0][3] = 2;
	d[1][0] = 7;
	d[1][1] = 5;
	d[1][2] = 6;
	d[1][3] = 1;
	d[2][0] = -6;
	d[2][1] = 0;
	d[2][2] = 9;
	d[2][3] = 6;
	d[3][0] = -3;
	d[3][1] = 0;
	d[3][2] = -9;
	d[3][3] = -4;
	///////////////////
	// d2[0][0] = -2;
	// d2[0][1] = 1;
	// d2[0][2] = 2;
	// d2[0][3] = 3;
	// d2[1][0] = 3;
	// d2[1][1] = 2;
	// d2[1][2] = 1;
	// d2[1][3] = -1;
	// d2[2][0] = 4;
	// d2[2][1] = 3;
	// d2[2][2] = 6;
	// d2[2][3] = 5;
	// d2[3][0] = 1;
	// d2[3][1] = 2;
	// d2[3][2] = 7;
	// d2[3][3] = 8;
	// print_matrice(d2);
	// double **r = scaling(-1, 1, 1);
	// double **r = rotation_z(M_PI / 4);
	// // double **rf = rotation_z(M_PI / 2);
	// double **t = translation(10, 5, 7);
	// // double **inv = inverse_matrix(r);
	// // print_matrice(inv);
	// // puts ("-----------------------");
	// double **r = multiple_matrice(t, scaling(5, 5, 5));
	// r = multiple_matrice(r, rotation_x(M_PI / 2));
	// t_point p = mul_mat_point(r, create_point(1, 0, 1));
	// // t_point p2 = mul_mat_point(inv, create_point(0, 1, 0));
	// t_vector p = mul_mat_vector(d2, create_vector(1, 2, 3));
	// printf("1   (%f, %.10f, %f, %f)\n", p.x, p.y, p.z, p.w);
	// printf("2   (%f, %.10f, %f, %f)\n", p1.x, p1.y, p1.z, p1.w);
}