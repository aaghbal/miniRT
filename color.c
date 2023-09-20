/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghbal <aaghbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 12:52:43 by aaghbal           #+#    #+#             */
/*   Updated: 2023/09/20 13:25:24 by aaghbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color create_color(double r, double g, double b)
{
	t_color col;

	col.red = r;
	col.green = g;
	col.blue = b;
	return(col);
}

t_color adding_color(t_color c1, t_color c2)
{
	t_color col;

	col.red = c1.red + c2.red;
	col.green = c1.green + c2.green;
	col.blue = c1.blue + c2.blue;
	return (col);
}

t_color sub_color(t_color c1, t_color c2)
{
	t_color col;

	col.red = c1.red - c2.red;
	col.green = c1.green - c2.green;
	col.blue = c1.blue - c2.blue;
	return (col);
}

t_color mul_by_scaler(t_color c1, double s)
{
	t_color col;

	col.red = c1.red * s;
	col.green = c1.green * s;
	col.blue = c1.blue * s;
	return (col);
}

t_color mul_color(t_color c1, t_color c2)
{
	t_color col;

	col.red = c1.red * c2.red;
	col.green = c1.green * c2.green;
	col.blue = c1.blue * c2.blue;
	return (col);
}
unsigned char float_to_char(float n)
{
	if (n < 0)
		n = 0.0;
	else if (n > 1)
		n = 1.0;
	return ((unsigned char) ceil(n * 255));
}

unsigned int conv_color(double r, double g, double b)
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