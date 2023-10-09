/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   effects_on_plan.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houmanso <houmanso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 13:11:52 by houmanso          #+#    #+#             */
/*   Updated: 2023/10/08 13:16:56 by houmanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_pattern	stripe_pattern(t_color a, t_color b)
{
	t_pattern	p;

	p.a = a;
	p.b = b;
	p.transform = identity();
	p.inverse = p.transform;
	return (p);
}

t_uv	plan_uv_map(t_point p)
{
	t_uv	uv;

	uv.u = p.x;
	uv.v = p.z;
	return (uv);
}
