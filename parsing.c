/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghbal <aaghbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 17:45:38 by aaghbal           #+#    #+#             */
/*   Updated: 2023/10/02 19:24:46 by aaghbal          ###   ########.fr       */
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

void read_file(char *file)
{
	int		fd;
	char	*line;
	char	**spli;

	spli = NULL;
	if (!check_exten(file))
	{
		printf("Error extention!\n");
		exit(1);
	}
	fd = open(file, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		spli = ft_split(line, ' ');
		int i = 0;
		while (spli[i])
		{
			printf("%s\n", spli[i]);
			i++;
		}
		
	}
	
}
