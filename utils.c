/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghbal <aaghbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 18:36:33 by aaghbal           #+#    #+#             */
/*   Updated: 2023/09/23 22:16:40 by aaghbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double mx(int x)
{
	return ((x - WIDTH / 2) * (10.0 / WIDTH));
}
double my(int x)
{
	return (-(x - HEIGHT/2)*(10.0/HEIGHT));
}

int px(double x)
{
	return (x * WIDTH / 10 + WIDTH/2);
}
int py(double x)
{
	return ((-x) * HEIGHT / 10 + HEIGHT/2);
}

bool equal(double a, double b)
{
	if (fabs(a - b) < EPSILON)
		return (true);
	return (false);
}
// double	**join_matr_ind(double **m)
// {
// 	int i = 0;
// 	int j = 0;
// 	int l = 0;
// 	double **mat;
// 	double **id = identity();
// 	mat = malloc(sizeof(double *) * 4);
// 	while (i < 4)
// 	{
// 		j = 0;
// 		l = 0;
// 		mat[i] = malloc(sizeof(double) * 8);
// 		while (j < 8)
// 		{
// 			if (j < 4)
// 				mat[i][j] = m[i][j];
// 			else
// 			{
// 				mat[i][j] = id[i][l];
// 				l++;
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// 	return(mat);
// }

// double **inverse_matrix(double **m) 
// {
// 	int i = 0;
// 	int j = 0;
// 	double **mat = join_matr_ind(m);
// 	puts("jjjjjj");
//     while(i < 4)
// 	{
//         double diagElem = mat[i][i];
// 		j = 0;
//         while(j < 8)
// 		{
//             mat[i][j] /= diagElem;
// 			j++;
//         }
// 		int k = 0;
//         while(k < 4)
// 		{
//             if (k != i)
// 			{
//                 double factor = mat[k][i];
// 				j = 0;
//                  while(j < 8)
// 				 {
//                     mat[k][j] -= factor * mat[i][j];
// 					j++;
//                 }
//             }
// 			k++;
//         }
// 		i++;
//     }
// 	int r = 0;
// 	i = 0;
// 	int a;
// 	while (r < 4)
// 	{
// 		a = 4;
// 		i = 0;
// 		while(a < 8)
// 		{
// 			m[r][i] = mat[r][a];
// 			i++;
// 			a++;
// 		}
// 		r++;
// 	}
// 	return (m);
// }