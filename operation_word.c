/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_word.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghbal <aaghbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 16:26:01 by aaghbal           #+#    #+#             */
/*   Updated: 2023/09/17 16:02:50 by aaghbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_word create_word(t_sphere *sp, t_light l)
{
	t_word word;

	word.light = l;
	word.sp = sp;
	return (word);
}

t_intersect *intersect_world(t_word w, t_ray r, int nobej)
{
	t_intersect *xs = malloc(sizeof(t_intersect) * nobej);
	int i = 0;
	while (i < nobej)
	{
		xs[i] = calculate_intersect(w.sp[i], r);
		i++;
	}
	return xs;
}