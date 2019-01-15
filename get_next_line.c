/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 18:10:12 by pdemian           #+#    #+#             */
/*   Updated: 2019/01/15 23:01:15 by pdemian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char	*s2;
	size_t	i;

	i = 0;
	if (!(s2 = ft_strnew(n)))
		return (NULL);
	while (s1[i] && i < n)
	{
		s2[i] = s1[i];
		i++;
	}
	return (s2);
}

static int		line_copy(char **line, char *content, char c)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = *line;
	while (content[i] && content[i] != c)
		i++;
	if (!(*line = ft_strndup(content, i)))
		return (0);
	return (i);
}

static t_list			*give_my_list(const int fd, t_list **main)
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
/*
static char		*obrz(char *s)
{
	int		i;
	char	*result;

	i = 0;
	if (s[i] == '\0' || s[i] == '\n')
		return (NULL);
	while (s[i] != '\n')
	{
		if (s[i] == '\0')
			return (s);
		i++;
	}
	result = ft_strnew(i);
	i = 0;
	while (s[i] != '\n' && s[i])
	{
		result[i] = s[i];
		i++;
	}
	return (result);
}
*/

int			read_this_fucking_file(const int fd, char **str)
{
	int		ret;
	char	buff[BUFF_SIZE + 1];
	char	*tmp;

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

int			get_next_line(const int fd, char **line)
{
	int				ret;
	static	t_list	*please;
	t_list			*work;
	char			*tmp;

	if (!line || fd < 0)
		return (-1);
	work = give_my_list(fd, &please);
	tmp = work->content;
	ret = read_this_fucking_file(fd, &tmp);
	work->content = tmp;
	if (ret < BUFF_SIZE && !ft_strlen(tmp))
		return(0);
	ret = line_copy(line, work->content, '\n');
	tmp = work->content;
	work->content = ft_strdup(&((work->content)[ret + 1]));
	free(tmp);
	return (1);
}
