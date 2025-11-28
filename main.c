/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteriier <mteriier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 12:54:58 by mteriier          #+#    #+#             */
/*   Updated: 2025/11/28 15:02:59 by mteriier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

char	*get_legit_line(char *filename, int nb_line)
{
	FILE		*fd;
	char	tmp[1000000];
	char	*line;
	int		i;

	i = 0;
	fd = fopen(filename, "r");
	while (i <= nb_line)
	{
		fgets(tmp, sizeof(tmp), fd);
		i++;
	}
	fclose(fd);
	i = 0;
	line = malloc((ft_strlen(tmp) + 1) * sizeof(char));
	line = ft_strcpy(line, tmp);
	return (line);
}

char	*get_the_line_to_test(char *filename, int nb_line)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(filename, O_RDONLY);
	while (i <= nb_line)
	{
		line = get_next_line(fd);
		i++;
	}
	close(fd);
	return (line);
}

int	CLASSIC_TEST(char *filename, int end)
{
	char	*line_legit;
	char	*line_test;
	int		i;

	i = 0;
	printf("TEST ON THIS FILE %s\n", filename);
	while (i < end)
	{
		//line_legit = get_legit_line(filename, i);
		line_test = get_the_line_to_test(filename, i);
		//printf("TEST[%d]  EXPECTED : |%s|\n", i, line_legit);
		printf("TEST[%d]  YOURS    : |%s|\n", i, line_test);
		//free(line_legit);
		free(line_test);
		i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	int		fd;
	char	*line;
	int		i;

	(void)ac;
	fd = open(av[1], O_RDONLY);
	while (i <= 0)
	{
		line = get_next_line(fd);
		printf("%s\n", line);
		free(line);
		i++;
	}
	close(fd);
	return (0);
}
