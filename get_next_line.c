/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 18:10:12 by pdemian           #+#    #+#             */
/*   Updated: 2019/01/14 23:11:53 by pdemian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

int			get_next_line(const int fd, char **line)
{
	int				ret;
	static	char	*tmp;
	char			buff[BUFF_SIZE + 1];
	char			*str;
//	static int				i = 0;

	if (!line || fd < 0 || read(fd, buff, 0) < 0)
		return (-1);
	tmp = (tmp) ? tmp : ft_strnew(1);
	str = ft_strdup(tmp);
	ft_strdel(&tmp);
	while ((ret = read(fd, buff, BUFF_SIZE)))
	{
		buff[ret] = '\0';
/*		printf("--------------------------------------------%d\n", ++i);
		system("leaks seems_it_works");
		printf("LLLLLLLLLLLLLLLLLLLLLLLLL%s\n", str);
*/		str = ft_strjoin(str, buff);
		// ft_putendl("-------");
//		printf("--{%s}\n", damn->content);
		// if (str)
		// 	free(str);
//		ft_putendl("++++++");
		if ((strchr(buff, '\n')))
			break ;
	}
	if (ret < BUFF_SIZE && !ft_strlen(str))
		return(0);
	free(*line);
	*line = (str[0] == '\n') ? ft_strnew(1) :  obrz(str);
	tmp = ft_strdup(ft_strchr(str, '\n'));
	ft_strdel(&str);
	return (1);
}
