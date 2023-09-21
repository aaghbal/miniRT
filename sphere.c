/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghbal <aaghbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 14:43:46 by aaghbal           #+#    #+#             */
/*   Updated: 2023/09/21 19:22:22 by aaghbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_sphere sphere()
{
	t_sphere s;

	s.trans = identity();
	return (s);
}

t_intersect *new_intersec(double min, double max, t_sphere sp)
{
	t_intersect *new;

	new = malloc(sizeof(t_intersect));
	new->min = min;
	new->max = max;
	new->s = sp;
	new->next = NULL;
	return (new);
}
