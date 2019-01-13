/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 20:26:13 by pdemian           #+#    #+#             */
/*   Updated: 2018/10/27 20:33:41 by pdemian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dup;
	size_t	len;
	size_t	i;

	len = 0;
	while (s1[len])
		len++;
	if (!(dup = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	dup[len] = '\0';
	i = 0;
	while (s1[i])
	{
		dup[i] = s1[i];
		i++;
	}
	return (dup);
}
