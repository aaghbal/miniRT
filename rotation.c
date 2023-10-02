/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghbal <aaghbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 18:44:13 by aaghbal           #+#    #+#             */
/*   Updated: 2023/10/02 11:45:36 by aaghbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	**rotation_x(double rad, t_free **f)
{
	double	cosr;
	double	sinr;
	double	**res;

	cosr = cos(rad);
	sinr = sin(rad);
	res = identity(f);
	res[1][1] = cosr;
	res[1][2] = (sinr * -1);
	res[2][1] = sinr;
	res[2][2] = cosr;
	return (res);
}

double	**rotation_y(double rad, t_free **f)
{
	double	cosr;
	double	sinr;
	double	**res;

	cosr = cos(rad);
	sinr = sin(rad);
	res = identity(f);
	res[0][0] = cosr;
	res[0][2] = sinr;
	res[2][0] = (sinr * -1);
	res[2][2] = cosr;
	return (res);
}

double	**rotation_z(double rad, t_free **f)
{
	double	cosr;
	double	sinr;
	double	**res;

	cosr = cos(rad);
	sinr = sin(rad);
	res = identity(f);
	res[0][0] = cosr;
	res[0][1] = (sinr * -1);
	res[1][0] = sinr;
	res[1][1] = cosr;
	return (res);
}
