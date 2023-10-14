/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houmanso <houmanso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 15:08:58 by aaghbal           #+#    #+#             */
/*   Updated: 2023/10/14 16:39:42 by houmanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void leaks(void)
{
	system("leaks miniRT");
}

int	main(int ac, char **av)
{
	atexit(leaks);
	if (ac == 2)
		read_file(av[1]);
	else
	{
		ft_putstr_fd("Error\nUsage: ./minirt FileName.rt\n", 2);
		exit(1);
	}
}
