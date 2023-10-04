/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_light.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghbal <aaghbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 11:54:07 by aaghbal           #+#    #+#             */
/*   Updated: 2023/10/04 14:50:12 by aaghbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_point	parse_origine(char *elem)
{
	t_point p;
	char	**spl;
	double	x;
	double	y;
	double	z;

	spl = ft_split(elem, ',');
	x = conver_range(spl[0]);
	y = conver_range(spl[1]);
	z = conver_range(spl[2]);
	p = create_point(x, y, z);
	free_doublep(spl);
	return(p);
}

t_vector	parse_vector(char *elem)
{
	t_vector p;
	char	**spl;
	double	x;
	double	y;
	double	z;

	spl = ft_split(elem, ',');
	x = conver_range(spl[0]);
	y = conver_range(spl[1]);
	z = conver_range(spl[2]);
	p = create_vector(x, y, z);
	free_doublep(spl);
	return(p);
}

t_color	parse_color(char *elem)
{
	t_color c;
	char	**spl;
	double	r;
	double	g;
	double	b;

	spl = ft_split(elem, ',');
	r = conver_range(spl[0]);
	g = conver_range(spl[1]);
	b = conver_range(spl[2]);
	c = create_color(r / 255, g / 255, b / 255);
	free_doublep(spl);
	return(c);
}

t_light	parsing_light(char	**elem)
{
	double	ratio;
	t_color	c;
	t_light	l;
	
	l.position = parse_origine(elem[1]);
	ratio = conver_range(elem[2]);
	c = parse_color(elem[3]);
	l.intensity = mul_by_scaler(c, ratio);
	return (l);
}