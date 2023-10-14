/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_camera.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houmanso <houmanso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 12:28:39 by aaghbal           #+#    #+#             */
/*   Updated: 2023/10/14 14:38:56 by houmanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_point	add_to_point(t_point p1, t_point p2)
{
	t_point	p;

	p.x = p1.x + p2.x;
	p.y = p1.y + p2.y;
	p.z = p1.z + p2.z;
	return (p);
}

double	radiane(double deg)
{
	double	res;

	res = (deg / 180) * M_PI;
	return (res);
}

void	camera_set_transform(t_camera *c, double **m)
{
	c->trans = m;
	c->inverse = inverse_gauss(m);
	if (!c->inverse)
		c->inverse = identity();
}

t_camera	parsing_camera(char **elem)
{
	t_camera	c;
	t_point		from;
	t_vector	to;
	t_vector	up;
	double		deg;

	if (!elem[0] || !elem[1] || !elem[2] || !elem[3] || elem[4])
		print_error(C);
	up = create_vector(0, 1, 0);
	from = parse_origine(elem[1], C);
	to = parse_vector(elem[2], C);
	deg = conver_ratio_number(elem[3], C);
	if (deg < 0 || deg > 180)
		print_error(C);
	if (equal(to.x, 0) && equal(to.z, 0))
		to = create_vector(0, 0, 1);
	c = camera(WIDTH, HEIGHT, radiane(deg));
	c.trans = view_transformation(from, add_point_vector(from, to), up);
	camera_set_transform(&c, c.trans);
	return (c);
}
