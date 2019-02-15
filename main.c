/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 17:18:08 by pdemian           #+#    #+#             */
/*   Updated: 2019/02/02 19:42:48 by pdemian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		main(int ac, char **av)
{
	int				fd;
	char			*line;
	int				i;

	line = NULL;
	ac = 2;
	i = 1;
	if (!(fd = open(av[1], O_RDONLY)))
		ft_putendl("It wasn't, kurwa, OPENED!!!");
	while (get_next_line(fd, &line) > 0)
	{
		if(i < 10)
			printf(" [%d ] %s\n", i, line);
		else 
			printf(" [%d] %s\n", i, line);
		i++;
		free(line);
	}
	system("leaks -q seems_it_works");
	return (0);
}
