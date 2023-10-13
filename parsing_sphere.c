/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_sphere.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghbal <aaghbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 15:35:23 by aaghbal           #+#    #+#             */
/*   Updated: 2023/10/13 20:30:40 by aaghbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_shape	texture_checkerboard(t_shape s, t_d_bonus d)
{
	s.has_effects = true;
	if (d.nb == 0)
	{
		s.type = checkers;
		s.pattern = uv_checkers(s.raduis * 2 * M_PI, s.raduis * M_PI, s.m.color,
				create_color(0, 0, 0));
		s.mapping = texture_map(s.pattern, sphere_uv_map);
		return (s);
	}
	s.type = texture;
	s.mapping.uv_map = sphere_uv_map;
	// s.img = mlx_load_png(d.path);
	return(s);
}

char	*ret_str(char *str)
{
	char	*dup_str;

	if (!ft_strcmp(str, "<NULL>"))
		return(NULL);
	dup_str = ft_strdup(str);
	ft_free(ADD, dup_str);
	return(dup_str);
}

t_d_bonus	init_sphere(int n, char **elem)
{
	t_d_bonus	d;
	char		**spl;
	char		*str;

	if (n == 7 && elem[5])
		d.nb = conver_ratio_number(elem[5], SP);
	if (n == 7 && !equal(d.nb, 0) && !equal(d.nb, 1))
		print_error(SP);
	if (n == 7 && elem[6] && d.nb == 0)
		d.c = rgb_color(elem[6], 1, SP);
	else if (n == 7 && elem[6] && d.nb == 1)
	{
		str = ft_strdup(elem[6]);
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

	if (n != 5 && n != 7)
		print_error(SP);
	s = default_shape();
	s.m.specular = conver_ratio_number(elem[4], SP);
	s.obj = sp;
	o = parse_origine(elem[1], SP);
	s.raduis = conver_ratio_number(elem[2], SP) / 2;
	set_transform(&s, multiple_matrice( translation(o.x, o.y, o.z),
			rotation_y(M_PI + M_PI / 5)));
	s.m.color = rgb_color(elem[3], 1, SP);
	if (n == 5)
		return (s);
	d = init_sphere(n, elem);
	s.has_effects = true;
	if (d.nb == 0)
	{
		s.type = checkers;
		s.pattern = uv_checkers(s.raduis * 2 * M_PI, s.raduis * M_PI, s.m.color,
				d.c);
		s.mapping = texture_map(s.pattern, sphere_uv_map);
		return (s);
	}
	// s.mapimg = mlx_load_png("./earth.png");
	s.type = texture;
	s.mapping.uv_map = sphere_uv_map;
	// s.img = mlx_load_png(d.path);
	return (s);
}
