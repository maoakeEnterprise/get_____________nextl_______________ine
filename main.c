/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteriier <mteriier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 12:54:58 by mteriier          #+#    #+#             */
/*   Updated: 2025/11/28 21:42:38 by mteriier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <string.h>
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
	i = 0;
	while (i <= nb_line)
	{
		line = get_next_line(fd);
		i++;
		if (i <= nb_line)
			free(line);
	}
	close(fd);
	return (line);
}

void	is_validate(char *test, char *legit)
{
	if (ft_strlen(legit) == 1 && !test)
	{
		printf("[OK]\n");
		return ;
	}
	if (strcmp(test, legit) == 0)
		printf("[OK]\n");
	else
		printf("[KO]\n");
}

void	CLASSIC_TEST(char *filename, int end)
{
	char	*line_legit;
	char	*line_test;
	int		i;

	i = 0;
	printf("\nCLASSIC TEST\n");
	printf("TEST ON THIS FILE %s\n", filename);
	while (i < end)
	{
		line_legit = get_legit_line(filename, i);
		line_test = get_the_line_to_test(filename, i);
		printf("TEST[%d]  EXPECTED : |%s", i, line_legit);
		printf("TEST[%d]  YOURS    : |%s", i, line_test);
		if (!line_test)
			printf("\n");
		printf("=======================================\n");
		printf("TEST[%d]", i);
		is_validate(line_test, line_legit);
		printf("=======================================\n");
		free(line_legit);
		free(line_test);
		i++;
	}
}

void	ERROR_TEST(char *filename)
{
	char	*line_legit;
	char	*line_test;
	int	fd;

	printf("\nERROR TEST\n");
	printf("TEST ON THIS FILE %s\n", filename);
	fd = open(filename, O_RDONLY);
	line_test = get_next_line(fd);
	free(line_test);
	line_test = get_next_line(fd);
	free(line_test);
	close(fd);
	fd = open(filename, O_RDONLY);
	line_test = get_next_line(fd);
	close(fd);
	line_legit = get_legit_line(filename, 0);
	printf("TEST[%d]  EXPECTED : |%s", 0, line_legit);
	printf("TEST[%d]  YOURS    : |%s", 0, line_test);
	printf("=======================================\n");
	printf("TEST[%d]", 0);
	is_validate(line_test, line_legit);
	printf("=======================================\n");
	free(line_legit);
	free(line_test);

}

int	main(int argc, char **argv)
{
	CLASSIC_TEST("filetest.txt", 30);
	ERROR_TEST("bible.txt");
	return (0);
}
