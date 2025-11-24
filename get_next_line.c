/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteriier <mteriier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 11:56:16 by mteriier          #+#    #+#             */
/*   Updated: 2025/11/24 14:33:14 by mteriier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	read_file(int fd, char *buffer)
{
	int	reader;

	reader = 1;
	reader = read(fd, buffer, BUFFER_SIZE);
	if (reader >= 0)
		buffer[reader] = 0;
	return (reader);
}

char	*fill_line(char *buffer, char *line, int fd)
{
	int	reader;

	reader = 1;
	while (buffer[0] != '\n' && reader > 0)
	{
		if (ft_strlen(buffer))
		{
			line = f_realloc(line, buffer[0]);
			if (!line)
				return (NULL);
			move_buffer(buffer);
		}
		else
			reader = read_file(fd, buffer);
	}
	if (reader == 0)
	{
		free(line);
		return (NULL);
	}
	return (line);
}

char	*get_the_line(int fd, char *buffer)
{
	char	*line;

	line = malloc (1 * sizeof(char));
	if (!line)
		return (NULL);
	line[0] = 0;
	line = fill_line(buffer, line, fd);
	if (!line)
		return (NULL);
	if (buffer[0] == '\n')
	{
		line = f_realloc(line, '\n');
		if (!line)
			return (NULL);
		move_buffer(buffer);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (!buffer)
	{
		buffer = malloc ((BUFFER_SIZE + 1) * sizeof(char));
		if (!buffer)
			return (NULL);
		buffer[0] = 0;
	}
	line = get_the_line(fd, buffer);
	if (!line)
		return (free(buffer), NULL);
	return (line);
}
