/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_matrice.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghbal <aaghbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 14:40:18 by aaghbal           #+#    #+#             */
/*   Updated: 2023/10/10 10:43:55 by aaghbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	**multiple_matrice(double **m1, double **m2)
{
	double	**res;
	t_matr	d;

	d.row = 0;
	res = malloc(sizeof(double *) * 4);
	ft_free(ADD, res);
	while (d.row < 4)
	{
		d.col = 0;
		res[d.row] = malloc(sizeof(double) * 4);
		ft_free(ADD, res[d.row]);
		while (d.col < 4)
		{
			d.i = 0;
			res[d.row][d.col] = 0;
			while (d.i < 4)
			{
				res[d.row][d.col] += m1[d.row][d.i] * m2[d.i][d.col];
				d.i++;
			}
			d.col++;
		}
		d.row++;
	}
	return (res);
}

bool	comparaison_matrix(double **m1, double **m2)
{
	int	i;
	int	j;

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

double	**transposing(double **m)
{
	int		row;
	int		col;
	double	**res;

	row = 0;
	col = 0;
	res = malloc(sizeof(double *) * 4);
	ft_free(ADD, res);
	while (row < 4)
	{
		res[row] = malloc(sizeof(double) * 4);
		ft_free(ADD, res[row]);
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

double	**identity(void)
{
	int		row;
	int		col;
	double	**res;

	row = 0;
	col = 0;
	res = malloc(sizeof(double *) * 4);
	ft_free(ADD, res);
	while (row < 4)
	{
		res[row] = malloc(sizeof(double) * 4);
		ft_free(ADD, res[row]);
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
	return (res);
}
