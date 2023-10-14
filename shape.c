/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houmanso <houmanso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 17:28:41 by aaghbal           #+#    #+#             */
/*   Updated: 2023/10/14 01:50:44 by houmanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_swap(double *t0, double *t1)
{
	double	tmp;

	tmp = *t0;
	*t0 = *t1;
	*t1 = tmp;
}

t_shape	default_shape(void)
{
	t_shape	s;

	s.tranform = identity();
	s.ivers_tran = s.tranform;
	s.m = material();
	s.min = -1;
	s.max = 1;
	s.type = none;
	s.closed = true;
	s.effects = false;
	s.txtr_img = NULL;
	s.bump_img = NULL;
	return (s);
}
