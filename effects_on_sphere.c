/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   effects_on_sphere.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houmanso <houmanso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 11:45:37 by houmanso          #+#    #+#             */
/*   Updated: 2023/10/11 18:38:25 by houmanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_uv	sphere_uv_map(t_point p)
{
	t_uv		uv;
	t_vector	vec;
	double		polar;
	double		radius;
	double		azimuthal;

	azimuthal = atan2(p.x, p.z);
	vec = create_vector(p.x, p.y, p.z);
	radius = magnitude(vec);
	polar = acos(p.y / radius);
	uv.u = 1 - (azimuthal / (2 * M_PI) + 0.5);
	uv.v = 1 - polar / M_PI;
	return (uv);
}
