/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghbal <aaghbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 12:52:43 by aaghbal           #+#    #+#             */
/*   Updated: 2023/10/01 11:46:17 by aaghbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color	create_color(double r, double g, double b)
{
	t_color	col;

	col.red = r;
	col.green = g;
	col.blue = b;
	return (col);
}

t_color	adding_color(t_color c1, t_color c2)
{
	t_color	col;

	col.red = c1.red + c2.red;
	col.green = c1.green + c2.green;
	col.blue = c1.blue + c2.blue;
	return (col);
}

t_color	sub_color(t_color c1, t_color c2)
{
	t_color	col;

	col.red = c1.red - c2.red;
	col.green = c1.green - c2.green;
	col.blue = c1.blue - c2.blue;
	return (col);
}

t_color	mul_by_scaler(t_color c1, double s)
{
	t_color	col;

	col.red = c1.red * s;
	col.green = c1.green * s;
	col.blue = c1.blue * s;
	return (col);
}

t_color	mul_color(t_color c1, t_color c2)
{
	t_color	col;

	col.red = c1.red * c2.red;
	col.green = c1.green * c2.green;
	col.blue = c1.blue * c2.blue;
	return (col);
}
