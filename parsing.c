/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghbal <aaghbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 17:45:38 by aaghbal           #+#    #+#             */
/*   Updated: 2023/10/13 20:11:25 by aaghbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	init_word(t_word *w, t_d_pars p)
{
	w->s = malloc(sizeof(t_shape) * p.num_shap);
	w->l = malloc(sizeof(t_light) * p.num_ligh);
	ft_free(ADD, w->s);
	ft_free(ADD, w->l);
}

void	free_split(char **elem, char *line)
{
	free_doublep(elem);
	free(line);
}

void	ft_create_world(int fd, t_d_pars p)
{
	t_norm	n;

	n.i = 0;
	n.j = 0;
	init_word(&n.w, p);
	while (1)
	{
		n.line = get_next_line(fd);
		if (!n.line)
			break ;
		n.line = ft_strtrim(n.line, "\n");
		if (!*n.line)
			continue ;
		n.spl = ft_split(n.line, ' ');
		if (!ft_strcmp("A", n.spl[0]))
			n.w.ambiant = parsing_am_light(n.spl);
		else if (!ft_strcmp("L", n.spl[0]))
			n.w.l[n.j++] = parsing_light(n.spl);
		else if (!ft_strcmp("C", n.spl[0]))
			n.c = parsing_camera(n.spl);
		else
			n.w.s[n.i++] = check_ident_shap(n.spl, p);
		free_split(n.spl, n.line);
	}
	render(n.w, n.c, p);
}

void	read_file(char *file)
{
	int			fd;
	t_d_pars	p;

	if (!check_exten(file))
		print_error(EXTE);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		print_error(OP);
	p = data_shape(fd);
	close(fd);
	fd = open(file, O_RDONLY);
	p.mlx = mlx_init(WIDTH, HEIGHT, "miniRT", true);
	ft_create_world(fd, p);
	close(fd);
}
