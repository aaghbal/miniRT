/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_am_light.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghbal <aaghbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 09:47:21 by aaghbal           #+#    #+#             */
/*   Updated: 2023/10/03 14:44:10 by aaghbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_d_am	parsing_am_light(char **elem)
{
	t_d_am am;

	am.ratio = conver_range(elem[1]);
	if (am.ratio < 0 || am.ratio > 1)
	{
		printf("Error ratio in ambinat lighting\n");
		exit(1);
	}
	am.res = rang_rgb(elem[2]);
	// printf("here %f  %f  %f reatio %f\n", res[0], res[1], res[2],conver_range(elem[1]));
	return (am);
}

double	*rang_rgb(char *str)
{
	double *res;
	char **spl;
	
	spl = ft_split(str, ',');
	res = malloc(sizeof(double) * 3);
	ft_free(ADD, res);
	res[0] = conver_range(spl[0]);
	res[1] = conver_range(spl[1]);
	res[2] = conver_range(spl[2]);
	return (res);
}

double	ft_itod(char *str)
{
	int		i;
	int		n;
	double	res;

	i = ft_strlen(str);
	n = ft_atoi(str);
	res = (double)n / pow(10, i);
	return (res);
}


double	conver_range(char *rat)
{
	char **spl;
	int n1;
	double n2;
	double res;
	int		sing;
	
	n2 = 0;
	sing = 1;
	spl = ft_split(rat, '.');
	n1 = ft_atoi(spl[0]);
	if (rat[0] == '-' && n1 == 0)
		sing = -1;
	if (spl[1])
		n2 = ft_itod(spl[1]);
	res = ((double)n1 + n2) * sing;
	free_doublep(spl);
	return (res);
}

// void	ambiant_lighting(char **elem)
// {
	
// }