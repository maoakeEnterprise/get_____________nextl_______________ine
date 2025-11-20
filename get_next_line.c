/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteriier <mteriier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 11:56:16 by mteriier          #+#    #+#             */
/*   Updated: 2025/11/20 16:12:13 by mteriier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_file(int fd, char *buffer)
{
	int	reader;
	char	*big_buffer;
	size_t	i;

	reader = read(fd, buffer, BUFFER_SIZE);
	if (reader < 0 || !buffer)
		return (NULL);
	buffer[reader] = 0;
	i = 0;
	big_buffer = malloc(1 * sizeof(char));
	if (!big_buffer)
		return (NULL);
	big_buffer[0] = 0;
	while (reader > 0)
	{
		big_buffer = f_realloc(big_buffer, buffer);
		reader = read(fd, buffer, BUFFER_SIZE);
		buffer[reader] = 0;
	}
	return (big_buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;

	if (!buffer)
		buffer = malloc((BUFFER_SIZE + 1) * sizeof (char));
	if (!buffer)
		return (NULL);
	if (fd == -1)
		return (NULL);
	buffer = read_file(fd, buffer);
	return (buffer);
}
