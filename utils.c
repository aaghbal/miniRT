/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghbal <aaghbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 18:36:33 by aaghbal           #+#    #+#             */
/*   Updated: 2023/10/01 14:51:23 by aaghbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	mx(int x)
{
	return ((x - WIDTH / 2) * (10.0 / WIDTH));
}

double	my(int x)
{
	return (-(x - HEIGHT / 2) * (10.0 / HEIGHT));
}

int	px(double x)
{
	return (x * WIDTH / 10 + WIDTH / 2);
}

int	py(double x)
{
	return ((-x) * HEIGHT / 10 + HEIGHT / 2);
}

bool	equal(double a, double b)
{
	if (fabs(a - b) < EPSILON)
		return (true);
	return (false);
}
