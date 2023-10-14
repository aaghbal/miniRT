/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_sphere.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houmanso <houmanso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 15:35:23 by aaghbal           #+#    #+#             */
/*   Updated: 2023/10/14 02:13:53 by houmanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_shape	set_txtr(t_shape s, t_d_bonus d)
{
	s.type = texture;
	if (d.path_bump)
	{
		s.bump_img = mlx_load_png(d.path_bump);
		if (!s.bump_img)
			_err("Something wrong with bump image");
	}
	if (d.path_txtr)
	{
		s.txtr_img = mlx_load_png(d.path_txtr);
		printf("%p | %p\n", s.txtr_img, d.path_txtr);
		if (!s.txtr_img)
			_err("Something wrong with texture image");
	}
	return (s);
}

char	*ret_str(char *str)
{
	char	*dup_str;

	if (!ft_strcmp(str, "<NULL>"))
		return (NULL);
	dup_str = ft_strdup(str);
	ft_free(ADD, dup_str);
	return (dup_str);
}

t_d_bonus	init_sphere(int n, char **elem)
{
	t_d_bonus	d;
	char		**spl;
	char		*str;

	if (n == 6 && elem[4])
		d.nb = conver_ratio_number(elem[4], SP);
	if (n == 6 && !equal(d.nb, 0) && !equal(d.nb, 1))
		print_error(SP);
	if (n == 6 && elem[5] && d.nb == 0)
		d.c = rgb_color(elem[5], 1, SP);
	else if (n == 6 && elem[5] && d.nb == 1)
	{
		str = ft_strdup(elem[5]);
		ft_free(ADD, str);
		spl = ft_split(str, '|');
		if (!spl || !spl[0] || !spl[1] || spl[2]
			|| (!ret_str(spl[0]) && !ret_str(spl[1])))
			print_error(SP);
		d.path_txtr = ret_str(spl[0]);
		d.path_bump = ret_str(spl[1]);
		free_doublep(spl);
	}
	return (d);
}

t_shape	parsing_sphere(char **elem, int n)
{
	t_point		o;
	t_shape		s;
	t_d_bonus	d;

	if (n != 4 && n != 6)
		print_error(SP);
	s = default_shape();
	s.obj = sp;
	o = parse_origine(elem[1], SP);
	s.raduis = conver_ratio_number(elem[2], SP) / 2;
	set_transform(&s, multiple_matrice(translation(o.x, o.y, o.z),
			rotation_y(M_PI)));
	s.m.color = rgb_color(elem[3], 1, SP);
	if (n == 4)
		return (s);
	d = init_sphere(n, elem);
	s.effects = true;
	if (d.nb == 0)
	{
		s.type = checkers;
		s.mapping.uv_pattern = uv_checkers(s.raduis * 2 * M_PI, s.raduis * M_PI,
				s.m.color, d.c);
		return (s.mapping.uv_map = sphere_uv_map, s);
	}
	return (s.mapping.uv_map = sphere_uv_map, set_txtr(s, d));
}
