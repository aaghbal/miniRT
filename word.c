/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghbal <aaghbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 11:02:31 by aaghbal           #+#    #+#             */
/*   Updated: 2023/09/24 15:58:39 by aaghbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_word default_word()
{
	t_word w;
	
	w.s = malloc(sizeof(t_sphere) * 2);
	w.l[0] = point_light(create_point(-10, 10, -10), create_color(1, 1, 1));
	w.s[0] = sphere();
	w.s[0].m.color = create_color(0.8, 1.0, 0.6);
	w.s[0].m.diffuse = 0.7;
	w.s[0].m.specular = 0.7;
	w.s[1] = sphere();
	w.s[1].trans = scaling(0.5, 0.5, 0.5);
	return (w);
}

t_word word(t_sphere *s, t_light *l)
{
	t_word w;

	w.s = s;
	w.l = l;
	return (w);
}
	
