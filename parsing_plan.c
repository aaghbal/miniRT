/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_plan.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houmanso <houmanso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 15:32:52 by aaghbal           #+#    #+#             */
/*   Updated: 2023/10/14 11:46:01 by houmanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_d_bonus	init_plan(int n, char **elem)
{
	t_d_bonus	d;
	char		**spl;
	char		*str;

	if (n == 7 && elem[5])
		d.nb = conver_ratio_number(elem[5], PL);
	if (n == 7 && !equal(d.nb, 0) && !equal(d.nb, 1))
		print_error(PL);
	if (n == 7 && elem[6] && d.nb == 0)
		d.c = rgb_color(elem[6], 1, PL);
	else if (n == 7 && elem[6] && d.nb == 1)
	{
		str = ft_strdup(elem[6]);
		ft_free(ADD, str);
		spl = ft_split(str, '|');
		if (!spl || !spl[0] || !spl[1] || spl[2]
			|| (!ret_str(spl[0]) && !ret_str(spl[1])))
			print_error(PL);
		d.path_txtr = ret_str(spl[0]);
		d.path_bump = ret_str(spl[1]);
		free_doublep(spl);
	}
	return (d);
}

t_shape	parsing_plan(char **elem, int n)
{
	t_shape		s;
	t_point		o;
	t_vector	orie;
	t_d_bonus	d;

	if (n != 5 && n != 7)
		print_error(PL);
	s = default_shape();
	s.obj = pl;
	s.m.specular = conver_ratio_number(elem[4], PL);
	o = parse_origine(elem[1], PL);
	orie = parse_vector(elem[2], PL);
	s.tranform = multiple_matrice(orient(orie), translation(o.x, o.y, o.z));
	set_transform(&s, s.tranform);
	s.m.color = rgb_color(elem[3], 1, PL);
	if (n == 5)
		return (s);
	d = init_plan(n, elem);
	s.effects = true;
	if (d.nb == 0)
	{
		s.mapping = texture_map(uv_checkers(2, 2, s.m.color, d.c), plan_uv_map);
		return (s.type = checkers, s);
	}
	return (s.mapping.uv_map = plan_uv_bump, set_txtr(s, d));
}
