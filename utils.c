/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghbal <aaghbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 18:36:33 by aaghbal           #+#    #+#             */
/*   Updated: 2023/10/07 17:52:23 by aaghbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	conver_ratio_number(char *rat, int flag)
{
	char **spl;
	int n1;
	double n2;
	double res;
	int		sing;
	
	n2 = 0;
	sing = 1;
	syntax_ratio(rat, flag);
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

double	conver_color_number(char *rat, int flag)
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
	syntax_ratio(rat, flag);
	if (rat[0] == '-' && n1 == 0)
		sing = -1;
	if (spl[1])
		n2 = ft_itod(spl[1]);
	res = ((double)n1 + n2) * sing;
	if (res > 255 || res < 0)
		print_error(flag);
	free_doublep(spl);
	return (res);
}

t_color rgb_color(char *str, double ratio, int flag)
{
	double *res;
	char **spl;
	t_color c;

	syntax_color(str, flag);
	spl = ft_split(str, ',');
	if (!spl[0] || !spl[1] || !spl[2] || spl[3])
		print_error(flag);
	res = malloc(sizeof(double) * 3);
	ft_free(ADD, res);
	res[0] = conver_color_number(spl[0], flag);
	res[1] = conver_color_number(spl[1], flag);
	res[2] = conver_color_number(spl[2], flag);
	c.red = (res[0] / 255) * ratio;
	c.green = (res[1] / 255) * ratio;
	c.blue = (res[2] / 255) * ratio;
	return (c);
}

double	conver_normal_number(char *rat, int flag)
{
	char **spl;
	int n1;
	double n2;
	double res;
	int		sing;
	
	n2 = 0;
	sing = 1;
	syntax_ratio(rat, flag);
	spl = ft_split(rat, '.');
	n1 = ft_atoi(spl[0]);
	if (rat[0] == '-' && n1 == 0)
		sing = -1;
	if (spl[1])
		n2 = ft_itod(spl[1]);
	res = ((double)n1 + n2) * sing;
		if (res > 1 || res < -1)
		print_error(flag);
	free_doublep(spl);
	return (res);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t		i;

	i = 0;
	while (s1[i] == s2[i] && (s1[i] != '\0' && s1[i] != '\0'))
		i++;

	return (s1[i] - s2[i]);
}