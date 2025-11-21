/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteriier <mteriier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 11:56:16 by mteriier          #+#    #+#             */
/*   Updated: 2025/11/21 14:54:03 by mteriier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	read_file(int fd, char *buffer)
{
	int	reader;

	reader = 1;
	reader = read(fd, buffer, BUFFER_SIZE);
	buffer[reader] = 0;
	return (reader);
}

void	big_free(char *buffer)
{
	free(buffer);
}

char	*get_line(int fd, char *buffer)
{
	char	*line;
	size_t	i;
	int	reader;

	i =0;
	line = malloc (1 * sizeof(char));
	if (!line)
		return (NULL);
	line[0] = 0;
	reader = 1;
	while (buffer[0] != '\n' && reader > 0)
	{
		if (ft_strlen(buffer))
		{
			line = f_realloc(line, buffer[0]);
			if (!line)
				return (free(buffer), NULL);
			move_buffer(buffer);
		}
		else
			reader = read_file(fd, buffer);	
	}
	if (buffer[0] == '\n')
	{
		line = f_realloc(line, '\n');
		if (!line)
			return (free(buffer), NULL);
		move_buffer(buffer);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char	*line;


	if (fd < 0)
		return (NULL);
	if (!buffer)
	{
		buffer = malloc ((BUFFER_SIZE + 1) * sizeof(char));
		if (!buffer)
			return (NULL);
		buffer[0] = 0;
	}
	if (!buffer)
		return (NULL);
	line = get_line(fd, buffer);
	if (!line)
		return (NULL);
	return (line);
}
