/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghbal <aaghbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 10:43:42 by aaghbal           #+#    #+#             */
/*   Updated: 2023/10/03 09:45:13 by aaghbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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

void	ft_free(int flag, void *addr)
{
	static t_free	*f = NULL;
	if (flag == ADD)
		add_addr(&f, new_addr(addr));
	else if (flag == FREE)
		free_all(f);
}

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

void free_doublep(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	tab = NULL;
}