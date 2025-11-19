/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteriier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 11:25:44 by mteriier          #+#    #+#             */
/*   Updated: 2025/11/05 13:34:59 by mteriier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

void	error_message(char *message);

int	line_strlen(char *buffer, int index)
{
	int	i;

	i = 0;
	while (buffer[index] != '\n' && buffer[index])
	{
		index++;
		i++;
	}
	return (i);
}

int	len_big_tab(char *buffer)
{
	int	i;
	int	count_line;

	i = 0;
	count_line = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			count_line++;
		i++;
	}
	return (count_line);
}

int	size_file(char *name_file)
{
	int		file;
	char	buffer[1];
	int		size;

	size = 1;
	file = open(name_file, O_RDONLY);
	if (file == -1)
		return (0);
	while (read(file, buffer, 1))
		size++;
	close(file);
	return (size);
}

void	full_buffer(char *buffer, char *name_file, int size)
{
	int	file;

	file = open(name_file, O_RDONLY);
	read(file, buffer, size);
	buffer[size - 1] = '\0';
	close(file);
}

char	*init_buffer(int size, char *name_file)
{
	char	*buffer;

	buffer = malloc(sizeof (char) * size);
	if (!buffer)
		return (0);
	full_buffer(buffer, name_file, size);
	return (buffer);
}
