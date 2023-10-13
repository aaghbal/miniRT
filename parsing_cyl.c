/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_cyl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghbal <aaghbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 14:03:42 by aaghbal           #+#    #+#             */
/*   Updated: 2023/10/13 20:36:26 by aaghbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_d_bonus	init_cyl(int n, char **elem)
{
	t_d_bonus	d;
	char		**spl;
	char		*str;

	if (n == 9 && elem[7])
		d.nb = conver_ratio_number(elem[7], CY);
	if (n == 9 && !equal(d.nb, 0) && !equal(d.nb, 1))
		print_error(CY);
	if (n == 9 && elem[8] && d.nb == 0)
		d.c = rgb_color(elem[8], 1, CY);
	else if (n == 9 && elem[8] && d.nb == 1)
	{
		str = ft_strdup(elem[8]);
		ft_free(ADD, str);
		spl = ft_split(str, '|');
		if (!spl || !spl[0] || !spl[1] || spl[2]
				|| (!ret_str(spl[0]) && !ret_str(spl[1])))
			print_error(CY);
		d.path_txtr = ret_str(spl[0]);
		d.path_bump = ret_str(spl[1]);
		free_doublep(spl);
	}
	return (d);
}

t_shape	parsing_cyl(char **elem, int n)
{
	t_vector	orie;
	t_point		o;
	t_shape		s;
	t_d_bonus	d;

	if (n != 7 && n != 9)
		print_error(CY);
	s = default_shape();
	s.obj = cy;
	s.m.specular = conver_ratio_number(elem[6], CY);;
	o = parse_origine(elem[1], CY);
	orie = parse_vector(elem[2], CY);
	d.dm = conver_ratio_number(elem[3], CY) / 2;
	d.h = conver_ratio_number(elem[4], CY);
	s.tranform = multiple_matrice(scaling(d.dm, 1, d.dm), scaling(1, d.h, 1));
	s.tranform = multiple_matrice(s.tranform, orient(orie));
	s.tranform = multiple_matrice(s.tranform, translation(o.x, o.y, o.z));
	set_transform(&s, s.tranform);
	s.m.color = rgb_color(elem[5], 1, CY);
	d = init_cyl(n, elem);
	if (n == 7)
		return (s);
	s.has_effects = true;
	s.pattern = uv_checkers(2, 2, s.m.color, create_color(0, 0, 0));
	s.mapping = texture_map(s.pattern, cyl_uv_map);
	return (s);
}
