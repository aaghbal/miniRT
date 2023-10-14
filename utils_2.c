/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghbal <aaghbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 10:18:26 by aaghbal           #+#    #+#             */
/*   Updated: 2023/10/09 20:30:26 by aaghbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	print_error(int flag)
{
	if (flag == A)
		ft_putstr_fd("Error\nCheck the {Ambiant lightning} syntax!\n", 2);
	if (flag == C)
		ft_putstr_fd("Error\nCheck the {Camera} syntax!\n", 2);
	if (flag == L)
		ft_putstr_fd("Error\nCheck the {Light} syntax!\n", 2);
	if (flag == SP)
		ft_putstr_fd("Error\nCheck the {Sphere} syntax!\n", 2);
	if (flag == PL)
		ft_putstr_fd("Error\nCheck the {Plane} syntax!\n", 2);
	if (flag == CY)
		ft_putstr_fd("Error\nCheck the {Cylinder} syntax!\n", 2);
	if (flag == CO)
		ft_putstr_fd("Error\nCheck the {Cone} syntax!\n", 2);
	if (flag == ERR_ID)
		ft_putstr_fd("Error\nShape not found\n", 2);
	if (flag == ERR_CAL)
		ft_putstr_fd("Error\nOne of the elements {A,C,L} is missing\n", 2);
	if (flag == EXTE)
		ft_putstr_fd("Error\nCheck file extention!\n", 2);
	if (flag == OP)
		ft_putstr_fd("Error\nFile unavailable\n", 2);
	ft_free(FREE, NULL);
	exit(1);
}

void	syntax_color(char *elem, int flag)
{
	int	i;
	int	sem_col;

	i = 0;
	sem_col = 0;
	while (elem[i])
	{
		if (elem[i] == '-')
			i++;
		if (elem[i] == ',')
			sem_col++;
		if ((elem[i] != ',' && elem[i] != '\n' && elem[i] != '.'
				&& !ft_isdigit(elem[i])) || (sem_col > 2))
			print_error(flag);
		i++;
	}
}

void	syntax_ratio(char *elem, int flag)
{
	int	i;
	int	sem_col;
	int	len;
	int	check_sing;

	i = 0;
	check_sing = 0;
	sem_col = 0;
	len = ft_strlen(elem);
	while (elem[i])
	{
		if ((elem[i] == '-' || elem[i] == '+'))
		{
			i++;
			check_sing++;
		}
		if (elem[i] == '.')
			sem_col++;
		if ((elem[i] != '.' && elem[i] != '\n' && !ft_isdigit(elem[i]))
			|| (sem_col > 1) || (elem[i] == '.' && (i == 0 || i == len - 1))
			|| check_sing > 1)
			print_error(flag);
		i++;
	}
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

bool	equal(double a, double b)
{
	if (fabs(a - b) < EPSILON)
		return (true);
	return (false);
}
