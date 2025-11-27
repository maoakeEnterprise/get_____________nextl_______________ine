/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteriier <mteriier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 12:54:58 by mteriier          #+#    #+#             */
/*   Updated: 2025/11/27 09:35:00 by mteriier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int truc;

int	main(int ac, char **av)
{
	int		fd;
	char	*line;
	int		i;

	(void)ac;
	fd = open(av[1], O_RDONLY);
	truc = 0;
	line = get_next_line(fd);
	i = 0;
	printf("%s", line);
	free(line);
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	truc = 1;
	line = get_next_line(-1);
	truc = 0;
	printf("%s", line);
	free(line);
	close(fd);
	fd = open(av[1], O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	printf("%s\n", line);
	line = get_next_line(fd);
	printf("%s\n", line);
	close(fd);
	return (0);
}
