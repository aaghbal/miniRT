/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_light.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghbal <aaghbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 11:54:07 by aaghbal           #+#    #+#             */
/*   Updated: 2023/10/09 20:31:35 by aaghbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_point	parse_origine(char *elem, int flag)
{
	t_point	p;
	char	**spl;
	double	x;
	double	y;
	double	z;

	spl = ft_split(elem, ',');
	if (!spl[0] || !spl[1] || !spl[2] || spl[3])
		print_error(flag);
	syntax_color(elem, flag);
	x = conver_ratio_number(spl[0], flag);
	y = conver_ratio_number(spl[1], flag);
	z = conver_ratio_number(spl[2], flag);
	p = create_point(x, y, z);
	free_doublep(spl);
	return (p);
}

t_vector	parse_vector(char *elem, int flag)
{
	t_vector	p;
	char		**spl;
	double		x;
	double		y;
	double		z;

	spl = ft_split(elem, ',');
	if (!spl[0] || !spl[1] || !spl[2] || spl[3])
		print_error(flag);
	syntax_color(elem, flag);
	x = conver_normal_number(spl[0], flag);
	y = conver_normal_number(spl[1], flag);
	z = conver_normal_number(spl[2], flag);
	p = create_vector(x, y, z);
	free_doublep(spl);
	return (p);
}

t_light	parsing_light(char **elem)
{
	double	ratio;
	t_color	c;
	t_light	l;

	if (!elem[0] || !elem[1] || !elem[2] || !elem[3] || elem[4])
		print_error(L);
	l.position = parse_origine(elem[1], L);
	ratio = conver_ratio_number(elem[2], L);
	c = rgb_color(elem[3], 1, L);
	l.intensity = mul_by_scaler(c, ratio);
	return (l);
}
