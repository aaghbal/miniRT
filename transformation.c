/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghbal <aaghbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 18:23:40 by aaghbal           #+#    #+#             */
/*   Updated: 2023/09/20 18:59:46 by aaghbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"


double **translation(double x, double y, double z)
{
	double **res;

	res = identity();
	res[0][3] = x;
	res[1][3] = y;
	res[2][3] = z;
	return (res);
}

double **scaling(double x, double y, double z)
{
	double **res;

	res = identity();
	res[0][0] = x;
	res[1][1] = y;
	res[2][2] = z;
	return(res);
}

double **shearing(t_shearing data)
{
	double **res;

	res = identity();
	res[0][1] = data.xy;
	res[0][2] = data.xz;
	res[1][0] = data.yx;
	res[1][2] = data.yz;
	res[2][0] = data.zx;
	res[2][1] = data.zy;
	return (res);
}
