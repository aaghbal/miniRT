/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_plan.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghbal <aaghbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 15:32:52 by aaghbal           #+#    #+#             */
/*   Updated: 2023/10/07 15:47:35 by aaghbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"


t_shape	parsing_plan(char **elem)
{
	t_shape		s;
	t_point		o;
	t_vector	orie;

	if (!elem[0] || !elem[1] || !elem[2] || !elem[3] || elem[4])
		print_error(PL);
	s = default_shape();
	s.obj = pl;
	s.m.specular = 0;
	o = parse_origine(elem[1], PL);
	orie = parse_vector(elem[2], PL);
	s.tranform = multiple_matrice(orient(orie), translation(o.x, o.y, o.z));
	s.m.color = rgb_color(elem[3], 1, PL);
	return (s);
}