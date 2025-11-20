/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteriier <mteriier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 11:57:40 by mteriier          #+#    #+#             */
/*   Updated: 2025/11/20 15:43:56 by mteriier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	char	*tmp;
	size_t	i;

	i = 0;
	tmp = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!tmp)
		return (NULL);
	while (s[i])
		tmp[i] = s[i++];
	tmp[i] = 0;
	return (tmp);
}

char	*f_realloc(char *str, char *buff)
{
	char	*dup;
	size_t	len;
	size_t	lendup;

	dup = ft_strdup(str);
	if (!dup)
		return (NULL);
	lendup = ft_strlen(dup)
	len = ft_strlen(buff);
	free(str);
	str = malloc((len + lendup + 1) * sizeof(char));
	str = ft_strcpy(str, dup);
	str = ft_strcat(str, buff);
}

char	*ft_strcpy(char *dst, const char *src)
{
	size_t	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strcat(char *dst, const char *src)
{
	size_t	j;
	size_t	i;

	j = ft_strlen(dst);
	i = 0;
	while (src[i])
	{
		dst[j] = src[i];
		j++;
		i++;
	}
	dst[j] = 0;
	return (dst);
}
