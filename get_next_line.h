/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 18:10:12 by pdemian           #+#    #+#             */
/*   Updated: 2019/01/29 18:32:57 by pdemian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>

# define BUFF_SIZE 1

int			get_next_line(const int fd, char **line);

#endif
