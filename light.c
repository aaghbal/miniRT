/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghbal <aaghbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 13:35:55 by aaghbal           #+#    #+#             */
/*   Updated: 2023/09/29 10:11:34 by aaghbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_light point_light(t_point pos, t_color intensit)
{
	t_light l;

	l.position = pos;
	l.intensity = intensit;
	return (l);
}

t_material material(void)
{
	t_material m;

	m.color = create_color(1, 1, 1);
	m.ambient = 0.1;
	m.diffuse = 0.9;
	m.specular = 0.9;
	m.shininess = 200.0;
	return (m);
}

// t_mater material()
// {
// 	t_mater m;
// 	return(m);
// }


t_color lighting(t_material m, t_light light, t_point point, t_vector eyev, t_vector normalv, bool shadowed)
{
	t_color effective_color;
	t_vector lightv;
	t_color ambient;
	t_color defuse;
	t_color specular;
	t_vector reflectv;
	t_color res;
	double lihgt_dot_normal;
	double reflect_dot_eye;
	double factor = 0;
	effective_color = mul_color(m.color, light.intensity);
	lightv = normalize(sub_to_point(light.position , point));
	ambient = mul_by_scaler(effective_color, m.ambient);
	if(shadowed)
		return (ambient);
	lihgt_dot_normal = dot_product(lightv, normalv);
	if (lihgt_dot_normal < 0)
	{
		defuse = create_color(0, 0, 0);
		specular = create_color(0, 0, 0);
	}
	else
		defuse = mul_by_scaler(mul_by_scaler(effective_color, m.diffuse), lihgt_dot_normal);
	reflectv = reflect(negating_vect(lightv), normalv);
	reflect_dot_eye = dot_product(reflectv, eyev);
	if (reflect_dot_eye > 0)
	{
		factor = pow(reflect_dot_eye, m.shininess);
		specular = mul_by_scaler(mul_by_scaler(light.intensity, m.specular), factor);
	}
	else
		specular = create_color(0, 0, 0);
	t_color te1 = adding_color(ambient, defuse);
	res = adding_color(te1, specular);
	return (res);
}