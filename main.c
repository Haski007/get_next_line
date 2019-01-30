/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 17:18:08 by pdemian           #+#    #+#             */
/*   Updated: 2019/01/29 18:21:30 by pdemian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		main(int ac, char **av)
{
	int				fd;
	char			*line;
	int				i;

	ac = 2;
	line = ft_strnew(1);
	i = 1;
	if (!(fd = open(av[1], O_RDONLY)))
		ft_putendl("It wasn't, kurwa, OPENED!!!");
	while (get_next_line(fd, &line) > 0)
	{
		printf("(%d)Ostatochnoe --------------|||||||||%s\n", i, line);
		i++;
	}
//	system("leaks -q seems_it_works");
	return (0);
}
