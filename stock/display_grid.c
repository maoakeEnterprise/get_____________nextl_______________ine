/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_grid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaillet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 19:20:48 by dgaillet          #+#    #+#             */
/*   Updated: 2025/09/03 10:19:16 by dgaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	display_grid(char **grid)
{
	int	i;
	int	len;

	len = 0;
	while (grid[0][len])
		len++;
	i = 0;
	while (grid[i])
	{
		write(1, grid[i], len);
		write(1, "\n", 1);
		i++;
	}
}
