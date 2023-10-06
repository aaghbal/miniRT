/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_camera.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghbal <aaghbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 12:28:39 by aaghbal           #+#    #+#             */
/*   Updated: 2023/10/06 12:32:08 by aaghbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_point	add_to_point(t_point p1, t_point p2)
{
	t_point p;

	p.x = p1.x + p2.x; 
	p.y = p1.y + p2.y; 
	p.z = p1.z + p2.z;
	return (p);
}
double radiane(double deg)
{
	double res;
	res = (deg / 180) * M_PI;
	return (res);
}

t_camera parsing_camera(char **elem)
{
	t_camera	c;
	t_point		from;
	t_vector		to;
	t_vector	up;
	double		deg;

	up = create_vector(0, 1, 0);
	from = parse_origine(elem[1]);
	to = parse_vector(elem[2]);
	deg = conver_range(elem[3]);
	if (equal(to.x, 0) && equal(to.z, 0))
		to = create_vector(0, 0, 1);
	c = camera(HEIGHT, WIDTH, radiane(deg));
	c.trans = view_transformation(from,add_point_vector(from, to), up);
	return(c);
}