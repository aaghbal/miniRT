/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cube.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghbal <aaghbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 16:09:24 by aaghbal           #+#    #+#             */
/*   Updated: 2023/10/09 20:43:14 by aaghbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	ft_max(double n1, double n2, double n3)
{
	if (n1 > n2 && n1 > n3)
		return (n1);
	else if (n2 > n1 && n2 > n3)
		return (n2);
	else if (n3 > n1 && n3 > n2)
		return (n3);
	return (n1);
}

double	ft_min(double n1, double n2, double n3)
{
	if (n1 < n2 && n1 < n3)
		return (n1);
	else if (n2 < n1 && n2 < n3)
		return (n2);
	else if (n3 < n1 && n3 < n2)
		return (n3);
	return (n1);
}

t_cube	check_axis(double ori, double dire)
{
	t_cube	t;
	double	tmin_numerator;
	double	tmax_numerator;

	tmin_numerator = (-1 - ori);
	tmax_numerator = (1 - ori);
	if (fabs(dire) >= EPSILON)
	{
		t.min = tmin_numerator / dire;
		t.max = tmax_numerator / dire;
	}
	else
	{
		t.min = tmin_numerator * INFINITY;
		t.max = tmax_numerator * INFINITY;
	}
	if (t.min > t.max)
		ft_swap(&t.min, &t.max);
	return (t);
}

t_vector	cube_normal_at(t_shape s, t_point word_point)
{
	double	maxc;
	double	**inv;
	t_point	obj_p;

	(void)s;
	inv = s.ivers_tran;
	obj_p = mul_mat_point(inv, word_point);
	maxc = ft_max(fabs(obj_p.x), fabs(obj_p.y), fabs(obj_p.z));
	if (equal(maxc, fabs(obj_p.x)))
		return (create_vector(obj_p.x, 0, 0));
	if (equal(maxc, fabs(obj_p.y)))
		return (create_vector(0, obj_p.y, 0));
	return (create_vector(0, 0, obj_p.z));
}

t_intersect	*cube_intersect(t_shape s, t_ray ray)
{
	t_ray		r;
	t_cube		*res;
	t_cube		t;
	t_intersect	*xs;

	res = malloc(sizeof(t_cube) * 3);
	ft_free(ADD, res);
	r = transform(ray, inverse_gauss(s.tranform));
	res[0] = check_axis(r.origine.x, r.direction.x);
	res[1] = check_axis(r.origine.y, r.direction.y);
	res[2] = check_axis(r.origine.z, r.direction.z);
	t.min = ft_max(res[0].min, res[1].min, res[2].min);
	t.max = ft_min(res[0].max, res[1].max, res[2].max);
	if (t.min > t.max)
		return (new_intersec(0, s));
	xs = new_intersec(t.min, s);
	return (xs);
}
