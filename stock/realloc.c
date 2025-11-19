/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteriier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 16:23:02 by mteriier          #+#    #+#             */
/*   Updated: 2025/09/03 13:30:29 by dgaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ft_string.h"

char	*ft_strcpy(char	*dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(char	*src)
{
	char	*dup;

	dup = malloc(sizeof (char) * (ft_strlen(src) + 1));
	if (!dup)
		return (free(dup), NULL);
	dup = ft_strcpy(dup, src);
	return (dup);
}

char	*f_realloc(char *str, int size)
{
	char	*dup;

	dup = ft_strdup(str);
	if (!dup)
		return (free(dup), NULL);
	free(str);
	str = malloc(sizeof (char) * (size + 2));
	if (!str)
		return (free(str), NULL);
	str = ft_strcpy(str, dup);
	str[size + 1] = '\0';
	free(dup);
	return (str);
}

char	*launch_no_arg(void)
{
	char	*str;
	char	buf[1];
	int		i;

	i = 0;
	str = malloc (sizeof (char) * 1);
	if (!str)
		return (free(str), NULL);
	str[0] = '\0';
	while (read(0, buf, sizeof (buf)) > 0)
	{
		str = f_realloc(str, i);
		if (!str)
			return (free(str), NULL);
		str[i] = buf[0];
		i++;
	}
	if (i == 0)
		return (free(str), NULL);
	return (str);
}
