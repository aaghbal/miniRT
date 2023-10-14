/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   effects_on_cyl.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houmanso <houmanso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 13:24:52 by houmanso          #+#    #+#             */
/*   Updated: 2023/10/14 02:45:26 by houmanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

//for checkers uv mapping
t_uv	cyl_uv_map(t_point p)
{
	t_uv	uv;
	double	raw;
	double	theta;

	theta = atan2(p.x, p.z);
	raw = theta / (2 * M_PI);
	uv.u = 1 - (raw + 0.5);
	uv.v = p.y - (int)p.y;
	return (uv);
}

// for textures uv mapping
t_uv	cyl_uv_bump(t_point p)
{
	t_uv	uv;
	double	raw;
	double	theta;

	theta = atan2(p.x, p.z);
	raw = theta / (2 * M_PI);
	uv.u = 1 - (raw + 0.5);
	uv.v = fabs(p.y) - (int)fabs(p.y);
	return (uv);
}
