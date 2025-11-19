/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaillet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 17:28:27 by dgaillet          #+#    #+#             */
/*   Updated: 2025/11/05 13:29:58 by mteriier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_string.h"

/* INDEX : 0 : y of loc, 1 : x of loc, 2 : y to test, 3 : max_x */
int	test_square(char **map, int set[4], char *params)
{
	int	temp_x;
	int	next_max;

	if ((map[set[0] + set[2]] && map[set[0] + set[2]][set[1]] == params[1])
		|| !map[set[0] + set[2]] || set[2] > set[3])
		return (0);
	temp_x = 0;
	while (map[set[0] + set[2]][set[1] + temp_x] != params[1]
		&& map[set[0] + set[2]][set[1] + temp_x] && temp_x < set[3])
		temp_x++;
	set[2] += 1;
	set[3] = temp_x;
	next_max = test_square(map, set, params);
	set[2] -= 1;
	if (((set[2] + 1) * (set[2] + 1)) > next_max && set[2] < temp_x)
		return ((set[2] + 1) * (set[2] + 1));
	else
		return (next_max);
}

void	reset_settings(int settings[4])
{
	settings[2] = 0;
	settings[3] = 1000000000;
}

int	*solver(char **map, int max_size, char *params, int *greatest_loc)
{
	int	settings[4];

	greatest_loc[0] = -1;
	greatest_loc[1] = -1;
	settings[0] = 0;
	while (map[settings[0]])
	{
		settings[1] = 0;
		while (map[settings[0]][settings[1]])
		{
			reset_settings(settings);
			if (test_square(map, settings, params) > max_size)
			{
				reset_settings(settings);
				max_size = test_square(map, settings, params);
				greatest_loc[0] = settings[0];
				greatest_loc[1] = settings[1];
			}
			settings[1] += 1;
		}
		settings[0] += 1;
	}
	return (greatest_loc);
}

/* INDEX : 0 : y of loc, 1 : x of loc, 2 : y to test, 3 : max_x */
/* SIZE : 0 : y; 1 : x */
int	find_square(char **map, int set[4], int size[2], char *params)
{
	int	temp_x;
	int	next_max;

	if ((map[set[0] + set[2]] && map[set[0] + set[2]][set[1]] == params[1])
		|| !map[set[0] + set[2]])
		return (0);
	temp_x = 0;
	while (map[set[0] + set[2]][set[1] + temp_x] != params[1]
		&& map[set[0] + set[2]][set[1] + temp_x] && temp_x < set[3])
		temp_x++;
	set[2] += 1;
	set[3] = temp_x;
	next_max = find_square(map, set, size, params);
	set[2] -= 1;
	if (((set[2] + 1) * (set[2] + 1)) > next_max && temp_x > set[2])
	{
		size[0] = set[2];
		size[1] = set[2];
		return ((set[2] + 1) * (set[2] + 1));
	}
	else
		return (next_max);
}

void	write_greatest_square(char **map, int *loc, char *params)
{
	int	size[2];
	int	temp_x;
	int	settings[4];

	settings[0] = loc[0];
	settings[1] = loc[1];
	reset_settings(settings);
	find_square(map, settings, size, params);
	while (size[0] >= 0)
	{
		temp_x = 0;
		while (temp_x <= size[1])
		{
			map[loc[0] + size[0]][loc[1] + temp_x] = params[2];
			temp_x++;
		}
		size[0] -= 1;
	}
}
