/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghbal <aaghbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 13:35:55 by aaghbal           #+#    #+#             */
/*   Updated: 2023/09/16 14:10:58 by aaghbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_light point_light(t_tuple pos, t_tuple intensit)
{
	t_light l;

	l.intensity = intensit;
	l.position = pos;
	return (l);
}

// t_mater material()
// {
// 	t_mater m;
// 	return(m);
// }

unsigned char float_to_char(float n)
{
	if (n < 0)
		n = 0.0;
	else if (n > 1)
		n = 1.0;
	return ((unsigned char) ceil(n * 255));
}

unsigned int conv_color(float r, float g, float b)
{
	unsigned char rc;
	unsigned char gc;
	unsigned char bc;
	unsigned int final_color;
	
	final_color = 0;
	rc = float_to_char(r);
	gc = float_to_char(g);
	bc = float_to_char(b);
	final_color |= (rc << 24);
	final_color |= (gc << 16);
	final_color |= (bc << 8);
	final_color |= 255;
	return (final_color);
}

t_tuple lighting(t_mater m, t_light light, t_tuple point, t_tuple eyev, t_tuple normalv)
{
	t_tuple effective_color;
	t_tuple lightv;
	t_tuple ambient;
	t_tuple defuse;
	t_tuple specular;
	t_tuple reflectv;
	t_tuple res;
	double lihgt_dot_normal;
	double reflect_dot_eye;
	double factor = 0;
	
	effective_color = multip_to_point(m.color, light.intensity);
	lightv = normali(substraction(light.position , point));
	ambient = multip(effective_color, m.ambient);
	lihgt_dot_normal = dot(lightv, normalv);
	if (lihgt_dot_normal < 0)
	{
		defuse = create_tuple(0, 0, 0, 1);
		specular = create_tuple(0, 0, 0, 1);
	}
	else
		defuse = multip(multip(effective_color, m.diffuse), lihgt_dot_normal);
	reflectv = reflect(multip(lightv, -1), normalv);
	reflect_dot_eye = dot(reflectv, eyev);
	if (reflect_dot_eye > 0)
	{
		factor = pow(reflect_dot_eye, m.shininess);
		specular = multip(multip(light.intensity, m.specular), factor);
	}
	else
		specular = create_tuple(0, 0, 0, 1);
	t_tuple te1 = add(ambient, defuse);
	res = add(te1, specular);
	return (res);
}