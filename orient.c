/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orient.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghbal <aaghbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:58:38 by aaghbal           #+#    #+#             */
/*   Updated: 2023/10/07 18:10:47 by aaghbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	**orientaion_matrix(t_vector up, t_vector forw, t_vector right)
{
	double	**res;

	res = identity();
	res[0][0] = up.x;
	res[1][0] = up.y;
	res[2][0] = up.z;
	res[3][0] = 0;
	res[0][1] = forw.x;
	res[1][1] = forw.y;
	res[2][1] = forw.z;
	res[3][1] = 0;
	res[0][2] = right.x;
	res[1][2] = right.y;
	res[2][2] = right.z;
	res[3][2] = 0;
	res[0][3] = 0;
	res[1][3] = 0;
	res[2][3] = 0;
	res[3][3] = 1;
	return (res);
}

double	**orient(t_vector orie)
{
	t_vector	up;
	t_vector	forw;
	t_vector	right;

	up = normalize(orie);
	forw = normalize(cross_product(create_vector(0, 1, 0), up));
	right = cross_product(up, forw);
	if (equal(orie.x, 0) && equal(orie.z, 0))
	{
		if (orie.y > 0)
		{
			up = create_vector(0, 1, 0);
			right = create_vector(1, 0, 0);
			forw = create_vector(0, 0, 1);
		}
		else if (orie.y < 0)
		{
			up = create_vector(0, -1, 0);
			right = create_vector(-1, 0, 0);
			forw = create_vector(0, 0, -1);
		}
	}
	return (orientaion_matrix(right, up, forw));
}
