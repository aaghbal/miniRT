/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghbal <aaghbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 13:35:55 by aaghbal           #+#    #+#             */
/*   Updated: 2023/10/04 17:01:56 by aaghbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_light	point_light(t_point pos, t_color intensit)
{
	t_light	l;

	l.position = pos;
	l.intensity = intensit;
	return (l);
}

t_material	material(void)
{
	t_material	m;

	m.color = create_color(1, 1, 1);
	m.ambient = 0.1;
	m.diffuse = 0.9;
	m.specular = 0.9;
	m.shininess = 200.0;
	return (m);
}

t_color	lighting(t_material m, t_light light, t_var_light v, bool shadowed)
{
	double	lihgt_dot_normal;
	double	reflect_dot_eye;
	double	factor;

	v.effective_color = mul_color(m.color, light.intensity);
	v.lightv = normalize(sub_to_point(light.position, v.point));
	v.ambient = mul_by_scaler(v.effective_color, m.ambient);
	if (shadowed)
		return (v.ambient);
	lihgt_dot_normal = dot_product(v.lightv, v.normalv);
	v.defuse = create_color(0, 0, 0);
	if (lihgt_dot_normal >= 0)
		v.defuse = mul_by_scaler(mul_by_scaler(v.effective_color, m.diffuse),
				lihgt_dot_normal);
	v.reflectv = reflect(negating_vect(v.lightv), v.normalv);
	reflect_dot_eye = dot_product(v.reflectv, v.eyev);
	if (reflect_dot_eye > 0)
	{
		factor = pow(reflect_dot_eye, m.shininess);
		v.specular = mul_by_scaler(mul_by_scaler(light.intensity, m.specular),
				factor);
	}
	else
		v.specular = create_color(0, 0, 0);
	return (adding_color(adding_color(v.ambient, v.defuse), v.specular));
}
