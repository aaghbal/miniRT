/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houmanso <houmanso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 15:08:58 by aaghbal           #+#    #+#             */
/*   Updated: 2023/10/08 11:32:26 by houmanso         ###   ########.fr       */
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

t_shape	*create_shape(void)
{
	t_shape	*s;

	s = malloc(sizeof(t_shape) * 5);
	s[0] = default_shape();
	s[0].m.color = create_color(1, 0.9, 0.9);
	s[0].m.specular = 0.0;
	s[0].obj = pl;
	 /////////////////////////////////////////
	s[1] = default_shape();
	s[1].closed = true;
	s[1].min = 0;
	s[1].max = 3;
	s[1].m.color = create_color(1, 1, 0);
	s[1].obj = cy;

	/////////////////////////////////////////
	s[2] = default_shape();
	s[2].tranform = multiple_matrice(translation(1.5, 0.5, -2) ,scaling(0.5, 0.5, 0.5));
	s[2].tranform = multiple_matrice(s[2].tranform, rotation_x(M_PI/2));
	s[2].tranform = multiple_matrice(s[2].tranform, rotation_y(0.87266));
	s[2].closed = true;
	s[2].min = -2;
	s[2].max = 2;
	s[2].m.color = create_color(0.5, 1, 0.1);
	s[2].obj = cy;
	/////////////////////////
	s[3] = default_shape();
	s[3].closed = true;
	s[3].tranform = multiple_matrice(translation(-1.5, 0.33, -0.75) ,scaling(0.33, 0.33, 0.33));
	s[3].m.color = create_color(1, 0.8, 0.1);
	s[3].min = -2;
	s[3].max = 1;
	s[3].obj = cy;

	/////////////////////////
	s[4] = default_shape();
	s[4].tranform = multiple_matrice(translation(0, 4, 0) ,scaling(1, 1, 1));
	s[4].m.color = create_color(1, 0, 0);
	s[4].obj = sp;
	return (s);
}
int	main(int ac, char **av)
{
	if (ac == 2)
		read_file(av[1]);
}