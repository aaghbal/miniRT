/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houmanso <houmanso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 13:35:55 by aaghbal           #+#    #+#             */
/*   Updated: 2023/10/08 11:33:25 by houmanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	printf_color(t_color c)
{
	printf("%f  %f  %f\n", c.red, c.green, c.blue);
	puts("-------------------");
}

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
	double	factor;
	t_color	color;

	color = s.m.color;
	if (s.has_effects)
		color = checkers_at(s.mapping, v.point);
	v.effective_color = mul_color(color, light.intensity);
	v.lightv = normalize(sub_to_point(light.position, v.point));
	v.ambient = mul_color(v.effective_color,v.am_rati);
	if (shadowed)
		return (v.ambient);
	lihgt_dot_normal = dot_product(v.lightv, v.normalv);
	v.defuse = create_color(0, 0, 0);
	if (lihgt_dot_normal > 0)
		v.defuse = mul_by_scaler(v.effective_color,
				s.m.diffuse * lihgt_dot_normal);
	v.reflectv = reflect(negating_vect(v.lightv), v.normalv);
	reflect_dot_eye = dot_product(v.reflectv, v.eyev);
	if (reflect_dot_eye > 0)
	{
		factor = pow(reflect_dot_eye, s.m.shininess);
		v.specular = mul_by_scaler(mul_by_scaler(light.intensity, s.m.specular),
				factor);
	}
	else
		v.specular = create_color(0, 0, 0);
	return (adding_color(adding_color(v.ambient, v.defuse), v.specular));
}
