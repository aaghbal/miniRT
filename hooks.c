/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houmanso <houmanso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 12:43:33 by houmanso          #+#    #+#             */
/*   Updated: 2023/10/14 16:40:06 by houmanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	resize(int width, int height, void *v)
{
	t_d			*d;
	t_camera	c;

	d = v;
	mlx_delete_image(d->mlx, d->img);
	c = camera(width, height, d->ca->field_of_view);
	d->ca->width = width;
	d->ca->height = height;
	d->ca->half_width = c.half_width;
	d->ca->half_height = c.half_height;
	d->ca->pixel_size = c.pixel_size;
	d->img = mlx_new_image(d->mlx, width, height);
	mlx_image_to_window(d->mlx, d->img, 0, 0);
	run_workers(*d);
}

void	on_click(t_mlx_key_cbdata keydata, void *param)
{
	(void)param;
	if (keydata.key == MLX_KEY_ESCAPE)
	{
		ft_free(FREE, NULL);
		exit(0);
	}
}

void	ft_close(void *p)
{
	(void)p;
	ft_free(FREE, NULL);
	exit(0);
}
