/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_am_light.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghbal <aaghbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 09:47:21 by aaghbal           #+#    #+#             */
/*   Updated: 2023/10/07 15:45:21 by aaghbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color	parsing_am_light(char **elem)
{
	t_color	c;
	double	ratio;

	if (!elem[0] || !elem[1] || !elem[2] || elem[3])
		print_error(A);
	ratio = conver_ratio_number(elem[1], A);
	if (ratio < 0 || ratio > 1)
		print_error(A);
	c = rgb_color(elem[2], ratio, A);
	return (mul_by_scaler(c, ratio));
}
