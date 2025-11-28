/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteriier <mteriier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 12:54:58 by mteriier          #+#    #+#             */
/*   Updated: 2025/11/28 10:03:35 by mteriier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int	main(int ac, char **av)
{
	int		fd;
	char	*line;
	int		i;

	(void)ac;
	fd = open(av[1], O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		//printf("%s", line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	close(fd);
	return (0);
}
