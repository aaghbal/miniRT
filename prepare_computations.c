/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_computations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghbal <aaghbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 11:51:09 by aaghbal           #+#    #+#             */
/*   Updated: 2023/10/02 12:47:27 by aaghbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_comps	prepare_computations(t_intersection i, t_ray ray, t_free **f)
{
	t_comps	com;

	com.inside = false;
	com.t = i.t;
	com.obj = i.sp;
	com.point = position(ray, com.t);
	com.eyev = negating_vect(ray.direction);
	if (i.sp.obj == sph)
		com.normalv = sphere_normal_at(&com.obj, com.point, f);
	else if (i.sp.obj == pla)
		com.normalv = plan_normal_at(&com.obj, com.point, f);
	else if (i.sp.obj == cyl)
		com.normalv = cyl_normal_at(com.obj, com.point, f);
	else if (i.sp.obj == con)
		com.normalv = cone_normal_at(com.obj, com.point, f);
	else if (i.sp.obj == cub)
		com.normalv = cube_normal_at(com.obj, com.point, f);
	else if (i.sp.obj == cub)
		com.normalv = cone_normal_at(com.obj, com.point, f);
	com.over_point = add_point_vector(com.point, scaler_vect(com.normalv,
				EPSILON));
	if (dot_product(com.normalv, com.eyev) < 0)
	{
		com.inside = true;
		com.normalv = negating_vect(com.normalv);
	}
	return (com);
}

t_color	shade_hit(t_word w, t_comps com, int n_obj, t_free **f)
{
	int			i;
	t_color		col;
	bool		shadowed;
	t_var_light	v;

	col = create_color(0, 0, 0);
	i = 0;
	v.eyev = com.eyev;
	v.normalv = com.normalv;
	v.point = com.point;
	while (i < 2)
	{
		v.l = w.l[i];
		shadowed = is_shadowed(w, com.over_point, n_obj, w.l[i], f);
		col = adding_color(col, lighting(com.obj.m, v.l, v, shadowed));
		i++;
	}
	return (col);
}
