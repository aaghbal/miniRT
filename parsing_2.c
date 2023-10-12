/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houmanso <houmanso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 18:54:38 by aaghbal           #+#    #+#             */
/*   Updated: 2023/10/11 14:22:16 by houmanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	check_exten(char *argv)
{
	int		i;
	int		j;
	int		len;
	char	*tab;

	tab = ".rt";
	j = 0;
	len = ft_strlen(argv);
	i = len - 3;
	while (argv[i] != '\0')
	{
		if (argv[i] != tab[j])
			return (0);
		i++;
		j++;
	}
	return (1);
}

t_shape	check_ident_shap(char **elem, t_d_pars p)
{
	t_shape	s;
	int		n;

	n = count_elem(elem);
	s = default_shape();
	if (!ft_strcmp("sp", elem[0]))
		s = parsing_sphere(elem, n);
	else if (!ft_strcmp("pl", elem[0]))
		s = parsing_plan(elem, n);
	else if (!ft_strcmp("cy", elem[0]))
		s = parsing_cyl(elem, n);
	else if (!ft_strcmp("co", elem[0]))
		s = parsing_cone(elem, n);
	s.mlx = p.mlx;
	return (s);
}

char	*ft_strcpy(char *str)
{
	int		i;
	char	*res;
	int		n;

	n = ft_strlen(str) + 1;
	i = 0;
	res = malloc(sizeof(char) * n);
	ft_free(ADD, res);
	while (str[i])
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

void	check_element(char *line)
{
	if (!ft_strcmp("A", line)
		|| !ft_strcmp("L", line)
		|| !ft_strcmp("C", line)
		|| !ft_strcmp("sp", line)
		|| !ft_strcmp("pl", line)
		|| !ft_strcmp("cy", line)
		|| !ft_strcmp("co", line))
		return ;
	else
		print_error(ERR_ID);
}

int	count_shape(char *line)
{
	check_element(line);
	if (!ft_strcmp("sp", line)
		|| !ft_strcmp("pl", line)
		|| !ft_strcmp("cy", line)
		|| !ft_strcmp("co", line))
		return (1);
	return (0);
}
