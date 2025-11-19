/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaillet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 11:51:28 by dgaillet          #+#    #+#             */
/*   Updated: 2025/11/05 13:29:43 by mteriier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <stdlib.h>

int	check_params(char *params)
{
	int		line_nb_len;
	int		len;
	int		i;
	char	*temp;

	len = ft_strlen(params);
	line_nb_len = 0;
	temp = malloc((len + 1) * sizeof(char));
	if (!temp)
		return (free(temp), -1);
	while (ft_strlen(&params[line_nb_len]) > 3)
		line_nb_len++;
	i = 0;
	temp[0] = '\0';
	while (params[i + line_nb_len] && !ft_strstr(temp, params[i + line_nb_len])
		&& len >= (line_nb_len + i))
	{
		temp[i] = params[i + line_nb_len];
		i++;
		temp[i] = '\0';
	}
	if (params[i + line_nb_len] || !temp[0])
		return (free(temp), -1);
	return (free(temp), 0);
}

int	check_chars(char *params, char **map)
{
	int	i;
	int	j;

	if (!params || !params[0] || !map || !map[0])
		return (-1);
	while (ft_strlen(params) > 3)
		params++;
	if ((params[0] < 33 || params[0] > 126) || (params[1] < 33
			|| params[1] > 126) || (params[2] < 33 || params[2] > 126))
		return (-1);
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != params[0] && map[i][j] != params[1])
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_line_length(char **map)
{
	int	line_len;
	int	i;
	int	j;

	if (!map || !map [0] || !map[0][0])
		return (-1);
	i = 0;
	line_len = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
			j++;
		if (j == line_len || line_len == 0)
			line_len = j;
		else
			return (-1);
		i++;
	}
	return (0);
}

int	check_nb_line(char **map, char *params)
{
	int		nb;
	int		i;
	char	*nb_line;

	i = 0;
	nb_line = malloc((ft_strlen(params) - 2) * sizeof(char));
	if (!nb_line)
		return (free(nb_line), -1);
	while (ft_strlen(params) - i > 3)
	{
		nb_line[i] = params[i];
		i++;
	}
	nb_line[i] = '\0';
	nb = ft_atoi(nb_line);
	free(nb_line);
	i = 0;
	while (map[i])
		i++;
	if (nb != i)
		return (-1);
	return (0);
}

int	parsing(char **map, char *params)
{
	int	error;

	if (ft_strlen(params) < 4 || !params || !params[0])
		return (-1);
	error = 0;
	error = error + check_params(params);
	if (error >= 0)
		error = error + check_chars(params, map);
	if (error >= 0)
		error = error + check_line_length(map);
	if (error >= 0)
		error = error + check_nb_line(map, params);
	return (error);
}
