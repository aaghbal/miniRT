/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghbal <aaghbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 17:28:41 by aaghbal           #+#    #+#             */
/*   Updated: 2023/09/29 16:14:52 by aaghbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void ft_swap(double *t0, double *t1)
{
	double tmp;
	
	tmp = *t0;
	*t0 = *t1;
	*t1 = tmp;
}

t_shape test_shape(void)
{
	t_shape s;
	
	s.tranform = identity();
	s.m = material();
	s.min = __DBL_MAX__;
	s.max = __DBL_MIN__;
	s.closed = false;
	return s;
}