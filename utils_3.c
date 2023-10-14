/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houmanso <houmanso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 20:29:27 by aaghbal           #+#    #+#             */
/*   Updated: 2023/10/13 22:23:19 by houmanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	count_elem(char **elem)
{
	int	i;

	i = 0;
	while (elem[i])
		i++;
	return (i);
}

void	_err(char *msg)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(msg, 2);
	ft_free(FREE, NULL);
	exit(1);
}
