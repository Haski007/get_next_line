/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 18:10:12 by pdemian           #+#    #+#             */
/*   Updated: 2019/01/13 03:15:17 by pdemian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_list			*fucking_lists(const int fd, t_list **file)
{
	t_list	*list;

	list = *file;
	while (list)
	{
		if ((int)list->content_size == fd)
			return (list);
		list = list->next;
	}
	list = ft_lstnew("\0", fd);
	ft_lstadd(file, list);
	list = *file;
	return (list);
}

static char		*obrz(char *s)
{
	int		i;
	char	*chlen;

	i = 0;
	if (s[i] == '\0' || s[i] == '\n')
		return (NULL);
	while (s[i] != '\n')
	{
		if (s[i] == '\0')
			return ("\0");
		i++;
	}
	chlen = ft_strnew(i);
	i = 0;
	while (s[i] != '\n' && s[i])
	{
		chlen[i] = s[i];
		i++;
	}
	return (chlen);
}

int			get_next_line(const int fd, char **line)
{
	int				ret;
	static	t_list	*tmp;
	char			buff[BUFF_SIZE + 1];
	t_list			*damn;
	char			*str;

	str = NULL;
	if (!line || fd < 0 || read(fd, buff, 0) < 0)
		return (-1);
	damn = fucking_lists(fd, &tmp);		
	while ((ret = read(fd, buff, BUFF_SIZE)))
	{
		buff[ret] = '\0';
		str = damn->content;
		CHECK((damn->content = ft_strjoin(str, buff)));
		// ft_putendl("-------");
		printf("--{%s}\n", damn->content);
		// if (str)
		// 	free(str);
		// ft_putendl("++++++");
		if ((strchr(buff, '\n')))
			break ;
	}
	if (ret < BUFF_SIZE && !ft_strlen(damn->content))
	{
		ft_strdel(damn->content);
		return(0);
	}
	free(*line);
	*line = obrz(damn->content);
	damn->content = ft_strchr(damn->content, '\n') + 1;
	return (1);
}
