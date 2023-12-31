/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghbal <aaghbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 14:26:36 by aaghbal           #+#    #+#             */
/*   Updated: 2023/10/09 19:13:29 by aaghbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	c;
	size_t	i;
	char	*p;

	i = 0;
	if (!s1 || !set)
		return (NULL);
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	c = ft_strlen(s1);
	while (c != 0 && ft_strchr(set, s1[c]))
		c--;
	p = ft_substr(s1, i, c - i + 1);
	free((char *)s1);
	return (p);
}
