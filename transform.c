/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houmanso <houmanso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 16:46:06 by aaghbal           #+#    #+#             */
/*   Updated: 2023/10/08 12:59:51 by houmanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_ray	transform(t_ray r, double **m)
{
	t_ray	ray;

	ray.origine = mul_mat_point(m, r.origine);
	ray.direction = mul_mat_vector(m, r.direction);
	return (ray);
}

void	set_transform(t_shape *s, double **t)
{
	s->tranform = t;
	s->ivers_tran = inverse_gauss(t);
	if (!s->ivers_tran)
		s->ivers_tran = identity();
}
