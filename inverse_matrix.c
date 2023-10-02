/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inverse_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghbal <aaghbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 12:37:22 by aaghbal           #+#    #+#             */
/*   Updated: 2023/10/02 11:21:43 by aaghbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	add_row(double **mat, double **m, int i, double **id)
{
	int	j;
	int	l;

	j = 0;
	l = 0;
	while (j < 8)
	{
		if (j < 4)
			mat[i][j] = m[i][j];
		else
		{
			mat[i][j] = id[i][l];
			l++;
		}
		j++;
	}
}

double	**join_matr_ind(double **m, t_free **f)
{
	int		i;
	int		j;
	int		l;
	double	**mat;
	double	**id;

	id = identity(f);
	i = 0;
	mat = malloc(sizeof(double *) * 4);
	add_addr(f, new_addr(mat));
	while (i < 4)
	{
		j = 0;
		l = 0;
		mat[i] = malloc(sizeof(double) * 8);
		add_addr(f, new_addr(mat[i]));
		add_row(mat, m, i, id);
		i++;
	}
	return (mat);
}

int	swap_diagonal_element(double **mat, int i)
{
	int	swaprow;
	int	k;

	swaprow = -1;
	k = i + 1;
	while (k < 4)
	{
		if (fabs(mat[k][i]) >= EPSILON)
		{
			swaprow = k;
			return (swaprow);
		}
		k++;
	}
	return (swaprow);
}

void	swap_row(double **mat, int swaprow, int i)
{
	int		j;
	double	temp;

	j = 0;
	while (j < 8)
	{
		temp = mat[i][j];
		mat[i][j] = mat[swaprow][j];
		mat[swaprow][j] = temp;
		j++;
	}
}
