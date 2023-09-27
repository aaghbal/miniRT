/* ************************************************************************** */
/*                                                                      row  col  */
/*                                                        :::      ::::::::   */
/*   operation_matrice.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghbal <aaghbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 14:40:18 by aaghbal           #+#    #+#             */
/*   Updated: 2023/08/27 14:19:50 by aaghbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"


double **multiple_matrice(double **m1, double **m2)
{
	double **res;
	int col;
	int i;
	int row;

	 row = 0;
	res = malloc(sizeof(double *) * 4);
	while (row < 4)
	{
		col = 0;
		res[row] = malloc(sizeof(double) * 4);
		while(col < 4)
		{
			i = 0;
			res[row][col] = 0;
			while (i < 4)
			{
				res[row][col] += m1[row][i] * m2[i][col];
				i++;
			}
			col++;		
		}
		row++;
	}
	return(res);
}

bool comparaison_matrix(double **m1, double **m2)
{
	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (!equal(m1[i][j], m2[i][j]))
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

double **transposing(double **m)
{
	int row = 0;
	int col = 0;
	double **res;
	res = malloc(sizeof(double *) * 4);
	while (row < 4)
	{
		res[row] = malloc(sizeof(double) * 4);
		col = 0;
		while (col < 4)
		{
			res[row][col] = m[col][row];
			col++;
		}
		row++;
	}
	return (res);
}

double **identity(void)
{
	int row = 0;
	int col = 0;
	double **res;
	res = malloc(sizeof(double *) * 4);
	while (row < 4)
	{
		res[row] =malloc(sizeof(double) * 4);
		col = 0;
		while (col < 4)
		{
			if (col == row)
				res[row][col] = 1;
			else
				res[row][col] = 0;
			col++;
		}
		row++;
	}
	return res;
}



// video explaine rotation https://www.youtube.com/watch?v=ttUdr_OW7-8





// float	**join_matr_ind(float **m)
// {
// 	int i = 0;
// 	int j = 0;
// 	int l = 0;
// 	float **mat;
// 	float **id = identity();
// 	mat = malloc(sizeof(float *) * 4);
// 	while (i < 4)
// 	{
// 		j = 0;
// 		l = 0;
// 		mat[i] = malloc(sizeof(float) * 8);
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
