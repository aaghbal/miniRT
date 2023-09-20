/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_vector_point.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghbal <aaghbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 10:45:54 by aaghbal           #+#    #+#             */
/*   Updated: 2023/09/20 10:58:10 by aaghbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector add_to_vector(t_vector v1, t_vector v2)
{
	t_vector res;

	res.x = v1.x + v2.x;
	res.y = v1.y + v2.y;
	res.z = v1.z + v2.z;
	res.w = v1.w + v2.w;
	return (res);
}

t_point add_point_vector(t_point p, t_vector v)
{
	t_point res;

	res.x = p.x + v.x;
	res.y = p.y + v.y;
	res.z = p.z + v.z;
	res.w = p.w + v.w;
	return (res);
}