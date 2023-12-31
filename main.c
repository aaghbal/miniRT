/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houmanso <houmanso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 15:08:58 by aaghbal           #+#    #+#             */
/*   Updated: 2023/10/14 15:19:06 by houmanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	print_matrice(double **m)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			printf("%.5f  ", m[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
		read_file(av[1]);
	else
	{
		ft_putstr_fd("Error\nUsage: ./minirt FileName.rt\n", 2);
		exit(1);
	}
}
