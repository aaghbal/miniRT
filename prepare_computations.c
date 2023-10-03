/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_computations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghbal <aaghbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 11:51:09 by aaghbal           #+#    #+#             */
/*   Updated: 2023/10/03 16:27:16 by aaghbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_comps	prepare_computations(t_intersection i, t_ray ray)
{
	t_comps	com;

	com.inside = false;
	com.t = i.t;
	com.obj = i.sp;
	com.point = position(ray, com.t);
	com.eyev = negating_vect(ray.direction);
	if (i.sp.obj == sp)
		com.normalv = sphere_normal_at(&com.obj, com.point);
	else if (i.sp.obj == pl)
		com.normalv = plan_normal_at(&com.obj, com.point);
	else if (i.sp.obj == cy)
		com.normalv = cyl_normal_at(com.obj, com.point);
	else if (i.sp.obj == co)
		com.normalv = cone_normal_at(com.obj, com.point);
	else if (i.sp.obj == cu)
		com.normalv = cube_normal_at(com.obj, com.point);
	com.over_point = add_point_vector(com.point, scaler_vect(com.normalv,
				EPSILON));
	if (dot_product(com.normalv, com.eyev) < 0)
	{
		com.inside = true;
		com.normalv = negating_vect(com.normalv);
	}
	return (com);
}

t_color	shade_hit(t_word w, t_comps com, int n_obj)
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
		shadowed = is_shadowed(w, com.over_point, n_obj, w.l[i]);
		col = adding_color(col, lighting(com.obj.m, v.l, v, shadowed));
		i++;
	}
	return (col);
}
