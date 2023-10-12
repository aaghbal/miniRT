/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houmanso <houmanso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 13:35:55 by aaghbal           #+#    #+#             */
/*   Updated: 2023/10/12 22:00:15 by houmanso         ###   ########.fr       */
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

t_color	lighting(t_shape s, t_light light, t_var_light v, bool shadowed)
{
	double	lihgt_dot_normal;
	double	reflect_dot_eye;
	double	fa;
	// t_point	p_beta;

	// if (s.has_effects && s.type == checkers)
	// 	s.m.color = checkers_at_shape(s.mapping, s, v.point);
	// else if (s.has_effects && s.type == texture)
	// {
	// 	p_beta = mul_mat_point(s.ivers_tran, v.point);
	// 	s.m.color = uv_texture_at(s, s.mapping.uv_map(p_beta));
	// }
	v.effect = mul_color(s.m.color, light.intensity);
	v.lightv = normalize(sub_to_point(light.position, v.point));
	v.ambient = mul_color(v.effect, v.am_rati);
	if (shadowed)
		return (v.ambient);
	lihgt_dot_normal = dot_product(v.lightv, v.normalv);
	v.defuse = create_color(0, 0, 0);
	if (lihgt_dot_normal > 0)
		v.defuse = mul_by_scaler(v.effect, s.m.diffuse * lihgt_dot_normal);
	v.reflectv = reflect(negating_vect(v.lightv), v.normalv);
	reflect_dot_eye = dot_product(v.reflectv, v.eyev);
	if (reflect_dot_eye > 0)
	{
		fa = pow(reflect_dot_eye, s.m.shininess);
		v.spc = mul_by_scaler(mul_by_scaler(light.intensity, s.m.specular), fa);
	}
	else
		v.spc = create_color(0, 0, 0);
	return (adding_color(adding_color(v.ambient, v.defuse), v.spc));
}
