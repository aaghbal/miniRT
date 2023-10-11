/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   effects_on_cyl.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houmanso <houmanso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 13:24:52 by houmanso          #+#    #+#             */
/*   Updated: 2023/10/08 14:05:38 by houmanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_uv	cyl_uv_map(t_point p)
{
	t_uv	uv;
	double	raw;
	double	theta;

	theta = atan2(p.x, p.z);
	raw = theta / M_2_PI;
	uv.u = 1 - (raw + 0.5);
	uv.v = p.y;
	return (uv);
}
