/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteriier <mteriier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 08:22:33 by mteriier          #+#    #+#             */
/*   Updated: 2025/11/28 08:35:53 by mteriier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
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
	{
		tmp[i] = s[i];
		i++;
	}
	tmp[i] = 0;
	return (tmp);
}

char	*f_realloc(char *str, char c)
{
	char	*dup;
	size_t	lendup;

	dup = ft_strdup(str);
	if (!dup)
		return (free(str), NULL);
	lendup = ft_strlen(dup);
	free(str);
	str = malloc((lendup + 2) * sizeof(char));
	if (!str)
		return (the_big_free(dup));
	str = ft_strcpy(str, dup);
	free(dup);
	str[lendup] = c;
	str[lendup + 1] = 0;
	return (str);
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

void	move_buffer(char *buffer)
{
	size_t	i;

	i = 0;
	while (buffer[i + 1])
	{
		buffer[i] = buffer[i + 1];
		i++;
	}
	buffer[i] = 0;
}
