/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghbal <aaghbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 10:43:42 by aaghbal           #+#    #+#             */
/*   Updated: 2023/10/02 13:10:19 by aaghbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_free	*new_addr(void *address)
{
	t_free	*new;

	new = malloc(sizeof(t_free));
	new->add = address;
	new->last = NULL;
	new->next = NULL;
	return (new);
}

void	add_addr(t_free **lst, t_free *new)
{
	if (lst != NULL)
	{
		if (*lst == NULL)
		{
			*lst = new;
			(*lst)->last = new;
		}
		else
		{
			(*lst)->last->next = new;
			(*lst)->last = new;
		}
	}
}

void	free_all(t_free *f)
{
	t_free	*tmp;

	while (f)
	{
		tmp = f;
		f = f->next;
		free (tmp->add);
		free (tmp);
	}
}
