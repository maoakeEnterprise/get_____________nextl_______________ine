/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteriier <mteriier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 08:22:04 by mteriier          #+#    #+#             */
/*   Updated: 2025/11/28 09:14:59 by mteriier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*the_big_free(char *s)
{
	free(s);
	return (NULL);
}

int	read_file(int fd, char *buffer)
{
	int	reader;

	reader = 1;
	reader = read(fd, buffer, BUFFER_SIZE);
	if (reader >= 0)
		buffer[reader] = 0;
	else
		buffer[0] = 0;
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
	if (reader == 0 && ft_strlen(line) == 0)
		return (the_big_free(line));
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
	static char	buffer[1024][BUFFER_SIZE + 1];
	char		*line;
	size_t		i;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
	{
		i = 0;
		if (fd > 0)
			buffer[fd][0] = 0;
		else
		{
			while (i < 1024)
			{
				buffer[i][0] = 0;
				i++;
			}
		}
		return (NULL);
	}
	line = get_the_line(fd, buffer[fd]);
	if (!line)
		return (NULL);
	return (line);
}
