/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 18:19:18 by pdemian           #+#    #+#             */
/*   Updated: 2019/01/14 21:41:41 by pdemian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdlib.h>
#include <unistd.h>
#include "libft/libft.h"
#include <sys/types.h>
#include <sys/uio.h>
#include <fcntl.h>
#include <stdio.h>

# define BUFF_SIZE 31


# define CHECK(a) if (!a) return (-1);

int			get_next_line(const int fd, char **line);

#endif
