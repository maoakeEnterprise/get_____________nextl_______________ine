/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaillet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 11:49:49 by dgaillet          #+#    #+#             */
/*   Updated: 2025/09/03 18:35:15 by dgaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "bsq.h"
#include "ft_string.h"

void	solve_map(char *params, char **big_grid, int i)
{
	int	*loc;

	loc = malloc (2 * sizeof(int));
	if (!loc)
		return (free(loc));
	if (parsing(big_grid, params) < 0)
	{
		write(2, "map error\n", 10);
		free_grid(big_grid);
		free(params);
		free(loc);
		return ;
	}
	while (ft_strlen(&params[i]) > 3)
		i++;
	loc = solver(big_grid, 0, &params[i], loc);
	if (loc && loc[0] >= 0 && loc[1] >= 0)
		write_greatest_square(big_grid, loc, &params[i]);
	display_grid(big_grid);
	free(loc);
	free_grid(big_grid);
	free(params);
}

void	solve_with_args(char *map_file)
{
	char	**big_grid;
	char	*params;

	params = gen_tab_params(map_file);
	if (!params || !params[0])
	{
		free(params);
		write(2, "map error\n", 10);
		return ;
	}
	big_grid = launch_gen(map_file);
	if (!params || !params[0] || !big_grid || !big_grid[0])
	{
		free(params);
		free_grid(big_grid);
		write(2, "map error\n", 10);
		return ;
	}
	solve_map(params, big_grid, 0);
}

void	solve_without_args(char *buffer)
{
	char	**big_grid;
	char	*params;

	params = init_line(buffer, 0);
	if (!params || !params[0])
	{
		free(params);
		free(buffer);
		write(2, "map error\n", 10);
		return ;
	}
	big_grid = init_big_grid(buffer);
	if (!params || !params[0] || !big_grid || !big_grid[0])
	{
		free(params);
		free(big_grid);
		free(buffer);
		write(2, "map error\n", 10);
		return ;
	}
	if (*buffer)
		free(buffer);
	solve_map(params, big_grid, 0);
}

int	main(int argc, char **argv)
{
	char	*buffer_no_args;

	if (argc < 2)
	{
		buffer_no_args = launch_no_arg();
		if (!buffer_no_args)
			return (free(buffer_no_args), 0);
		solve_without_args(buffer_no_args);
	}
	else
	{
		argv++;
		while (*argv)
		{
			solve_with_args(*argv);
			if (*(argv + 1))
				write(1, "\n", 1);
			argv++;
		}
	}
	return (0);
}
