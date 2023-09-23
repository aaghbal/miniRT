/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghbal <aaghbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 15:39:16 by aaghbal           #+#    #+#             */
/*   Updated: 2023/09/23 09:32:23 by aaghbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double **submatrix(double **A, int num_row, int num_col, int row ,  int col)
{
	int	i = 0;
	int	k = 0;
	int	r = 0;
	int	j = 0;
	double **res;
	res = malloc(sizeof(double *) * num_row - 1);
	while (i < num_row)
	{
		res[i] = malloc(sizeof(double) * num_col - 1);
		j = 0;
		r = 0;
		if ( i == row)
		{
			i++;
			continue;
		}
		while (j < num_col)
		{
			if (j != col)
			{
				res[k][r] = A[i][j];
				r++;
			}
			j++;
		}
		i++;
		k++;
	}
	return (res);
}

double cofactor(double **A, int row, int col)
{
	double **res = submatrix(A, 3 , 3 , row , col);
	double res2 = (res[0][0] * res[1][1]) - (res[0][1] * res[1][0]);
	if ((row + col) % 2 != 0)
		res2 *= -1;
	return(res2); 
}
bool is_inverse(double **M, int row, int col)
{
	double res;
	res = determinant_4(M, row, col);
	if (!res)
		return (false);
	return (true);
}

double determinant_3(double **M, int row, int col)
{
	int i = 0;
	double det = 0;
	if (row == 2 && col == 2)
		det = (M[0][0] * M[1][1]) - (M[0][1] * M[1][0]);
	else
	{
		while (i < row)
		{
			det += M[0][i] * cofactor(M, 0, i);

			i++;
		}
	}
	return(det);
}

double determinant_4(double **M, int row, int col)
{
	(void)col;
	int i = 0;
	double det = 0;
	double res2 = 0;
	double **sub;
	while (i < row)
	{
		sub = submatrix(M, 4, 4, 0, i);
		det = determinant_3(sub, 3, 3);
		if (i % 2 != 0)
			det *= -1;
		res2 += det * M[0][i]; 
		i++;
	}
	return(res2);
}
double **inverse_matrix(double **m)
{
	int i = 0;
	int j = 0;
	double det3;
	double **res;
	double det;
	det = determinant_4(m, 4, 4);
	if (!det)
		return (m);
	res = malloc(sizeof(double *) * 4);
	while (i < 4)
	{
		res[i] = malloc(sizeof(double) * 4);
		i++;
	}
	i = 0;
	j = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			double **sub = submatrix(m, 4, 4, i, j);
			det3 = determinant_3(sub, 3, 3);
			if ((i + j) % 2 != 0)
				det3 *= -1;
			res[j][i] = det3 / det;
			j++;
		}
		i++;
	}
	return (res);
}