/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteriier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 13:21:31 by mteriier          #+#    #+#             */
/*   Updated: 2025/09/02 13:37:24 by mteriier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

void	free_grid(char **big_grid)
{
	int	i;

	i = 0;
	while (big_grid[i])
	{
		free(big_grid[i]);
		i++;
	}
	free(big_grid);
}
