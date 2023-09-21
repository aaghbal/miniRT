/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghbal <aaghbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 15:08:58 by aaghbal           #+#    #+#             */
/*   Updated: 2023/09/21 19:21:04 by aaghbal          ###   ########.fr       */
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

// double radiane(double deg)
// {
// 	float res;
// 	res = (deg / 180) * M_PI;
// 	return (res);
// }

int main()
{
	// t_sphere s = sphere();
	// double **m = multiple_matrice(scaling(1, 0.5, 1) , rotation_z(M_PI/5));
	// set_transform(&s, m);
	// t_vector v = normal_at(&s, create_point(0, 0.70710678118, -0.70710678118));
	t_vector v = reflect(create_vector(0, -1, 0), create_vector(0.70710678118, 0.70710678118, 0));
	printf("O   (%.5f, %.5f, %.5f, %.5f)\n", v.x, v.y, v.z, v.w);
	// printf("d   (%.f, %.f, %.f, %.f)\n", r2.direction.x, r2.direction.y, r2.direction.z, r2.direction.w);
}
