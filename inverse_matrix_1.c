/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inverse_matrix_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghbal <aaghbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 12:00:48 by aaghbal           #+#    #+#             */
/*   Updated: 2023/10/02 13:25:40 by aaghbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	div_row_by_diagonale(double **mat, double diagelem, int i)
{
	int	j;

	j = 0;
	while (j < 8)
	{
		mat[i][j] /= diagelem;
		j++;
	}
}

void	set_colon_diag_withzero(double **mat, int i)
{
	int		k;
	int		j;
	double	factor;

	k = 0;
	j = 0;
	while (k < 4)
	{
		if (k != i)
		{
			factor = mat[k][i];
			j = 0;
			while (j < 8)
			{
				mat[k][j] -= factor * mat[i][j];
				j++;
			}
		}
		k++;
	}
}

double	**copy_result(double **mat)
{
	int		r;
	int		i;
	double	**n;
	int		a;

	i = 0;
	r = 0;
	n = identity();
	while (r < 4)
	{
		a = 4;
		i = 0;
		while (a < 8)
		{
			n[r][i] = mat[r][a];
			i++;
			a++;
		}
		r++;
	}
	return (n);
}

double	**inverse_gauss(double **m)
{
	int		i;
	int		j;
	double	**mat;
	double	diagelem;
	int		swaprow;

	i = 0;
	j = 0;
	mat = join_matr_ind(m);
	while (i < 4)
	{
		diagelem = mat[i][i];
		if (fabs(diagelem) < EPSILON)
		{
			swaprow = swap_diagonal_element(mat, i);
			if (swaprow == -1)
				return (NULL);
			swap_row(mat, swaprow, i);
			diagelem = mat[i][i];
		}
		div_row_by_diagonale(mat, diagelem, i);
		set_colon_diag_withzero(mat, i);
		i++;
	}
	return (copy_result(mat));
}
