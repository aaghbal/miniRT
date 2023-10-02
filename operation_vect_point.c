/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_vect_point.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghbal <aaghbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 11:30:58 by aaghbal           #+#    #+#             */
/*   Updated: 2023/09/20 11:45:18 by aaghbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector	negating_vect(t_vector v)
{
	t_vector	n;

	n.x = v.x * -1.0;
	n.y = v.y * -1.0;
	n.z = v.z * -1.0;
	n.w = v.w * -1.0;
	return (n);
}

t_point	negating_point(t_point p)
{
	t_point	n;

	n.x = p.x * -1.0;
	n.y = p.y * -1.0;
	n.z = p.z * -1.0;
	n.w = p.w * -1.0;
	return (n);
}

t_vector	scaler_vect(t_vector v, double s)
{
	t_vector	res;

	res.x = v.x * s;
	res.y = v.y * s;
	res.z = v.z * s;
	res.w = v.w * s;
	return (res);
}

t_point	scaler_point(t_point p, double s)
{
	t_point	res;

	res.x = p.x * s;
	res.y = p.y * s;
	res.z = p.z * s;
	res.w = p.w * s;
	return (res);
}

t_vector	div_scaler_vect(t_vector v, double s)
{
	t_vector	res;

	res.x = v.x / s;
	res.y = v.y / s;
	res.z = v.z / s;
	res.w = v.w / s;
	return (res);
}
