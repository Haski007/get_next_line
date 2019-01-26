/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 18:10:12 by pdemian           #+#    #+#             */
/*   Updated: 2019/01/26 20:03:40 by pdemian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_list		*give_my_list(const int fd, t_list **main)
{
	t_list	*list;

	list = *main;
	while (list)
	{
		if ((int)list->content_size == fd)
			return (list);
		list = list->next;
	}
	list = ft_lstnew("\0", fd);
	ft_lstadd(main, list);
	return (list);
}

static int			line_copy(char **line, char *from_list)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	tmp = *line;
	while (from_list[i] && from_list[i] != '\n')
		i++;
	if (!(tmp = ft_strnew(i)))
		return (0);
	while (from_list[j] && j < i)
	{
		tmp[j] = from_list[j];
		j++;
	}
	if (!(*line = tmp))
		return (0);
	return (i);
}

int					read_this_fucking_file(const int fd, char **str)
{
	int		ret;
	char	buff[BUFF_SIZE + 1];
	char	*tmp;

	if ((read(fd, buff, 0) < 0))
		return (-1);
	while ((ret = read(fd, buff, BUFF_SIZE)))
	{
		buff[ret] = '\0';
		tmp = *str;
		*str = ft_strjoin(tmp, buff);
		free(tmp);
		if (ft_strchr(buff, '\n'))
			return (ret);
	}
	return (0);
}

int					get_next_line(const int fd, char **line)
{
	int				ret;
	static	t_list	*please;
	t_list			*work;
	char			*tmp;

	if (line == NULL || fd < 0)
		return (-1);
	work = give_my_list(fd, &please);
	tmp = work->content;
	if ((ret = read_this_fucking_file(fd, &tmp)) < 0)
		return (-1);
	work->content = tmp;
	if (ret < BUFF_SIZE && !ft_strlen(tmp))
		return (0);
	ret = line_copy(line, work->content);
	tmp = work->content;
	if (tmp[ret] != '\0')
	{
		work->content = ft_strdup(ft_strchr(tmp, '\n'));
		free(tmp);
	}
	else
		tmp[0] = '\0';
	return (1);
}
