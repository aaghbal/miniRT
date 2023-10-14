/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houmanso <houmanso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 12:43:54 by houmanso          #+#    #+#             */
/*   Updated: 2023/10/14 15:32:04 by houmanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	run_workers(t_d d)
{
	pthread_t	thr[4];
	t_tr		data[4];

	d.y_start = 0;
	while (d.i < 4)
	{
		data[d.i] = (t_tr){d.mlx, d.img, d.y_start, *d.w, *d.ca, *d.p};
		d.y_start += d.ca->height / 4;
		pthread_create(&thr[d.i], NULL, rotine, &(data[d.i]));
		d.i++;
	}
	d.i = 0;
	while (d.i < 4)
		pthread_join(thr[d.i++], NULL);
}
