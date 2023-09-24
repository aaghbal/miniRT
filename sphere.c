/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghbal <aaghbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 14:43:46 by aaghbal           #+#    #+#             */
/*   Updated: 2023/09/23 21:20:32 by aaghbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_sphere sphere()
{
	t_sphere s;

	s.trans = identity();
	s.m = material();
	return (s);
}

t_intersect *new_intersec(double min, t_sphere sp)
{
	t_intersect *new;

	new = malloc(sizeof(t_intersect));
	new->min = min;
	new->s = sp;
	new->next = NULL;
	return (new);
}

t_intersect	*last(t_intersect *lst)
{
	if (lst == NULL)
		return (lst);
	while (lst && lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	add_back(t_intersect **lst, t_intersect *new)
{
	t_intersect	*p;

	if (lst != NULL)
	{
		if (*lst == NULL)
			*lst = new;
		else
		{
			p = last(*lst);
			p->next = new;
		}
	}
}

void	add_front(t_intersect **lst, t_intersect *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}