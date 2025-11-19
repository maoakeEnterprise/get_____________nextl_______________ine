/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_gen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteriier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 11:31:59 by mteriier          #+#    #+#             */
/*   Updated: 2025/09/03 11:59:27 by mteriier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		line_strlen(char *buffer, int index);
int		size_file(char *name_file);
char	*init_buffer(int size, char *name_file);
int		len_big_tab(char *buffer);

char	*init_line(char *buffer, int index)
{
	int		size;
	char	*line;
	int		i;

	i = 0;
	size = line_strlen(buffer, index);
	line = malloc(sizeof (char) * (size + 1));
	if (!line)
		return (0);
	while (buffer[index] != '\n' && buffer[index])
	{
		line[i] = buffer[index];
		index++;
		i++;
	}
	line[i] = '\0';
	return (line);
}

void	full_big_grid(char *buffer, char **big_grid)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n' && buffer[i + 1])
		{
			big_grid[j] = init_line(buffer, i + 1);
			j++;
		}
		i++;
	}
	big_grid[j] = 0;
}

char	**init_big_grid(char *buffer)
{
	char	**big_grid;

	big_grid = malloc(sizeof(char *) * (len_big_tab(buffer) + 1));
	if (!big_grid)
		return (free(big_grid), NULL);
	full_big_grid(buffer, big_grid);
	return (big_grid);
}

char	*gen_tab_params(char *namefile)
{
	char	*tab;
	char	*buffer;
	int		size;

	size = size_file(namefile);
	if (size == 0)
		return (0);
	buffer = init_buffer(size, namefile);
	if (!buffer)
		return (0);
	tab = init_line(buffer, 0);
	if (!tab)
		return (0);
	free(buffer);
	return (tab);
}

char	**launch_gen(char *namefile)
{
	char	**big_grid;
	char	*buffer;
	int		size;
	int		i;

	i = 0;
	size = size_file(namefile);
	if (size == 0)
		return (0);
	buffer = init_buffer(size, namefile);
	if (!buffer)
		return (0);
	big_grid = init_big_grid(buffer);
	if (!big_grid)
		return (0);
	while (big_grid[i])
	{
		if (!big_grid)
			return (0);
		i++;
	}
	free(buffer);
	return (big_grid);
}
