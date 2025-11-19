/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteriier <mteriier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 11:56:16 by mteriier          #+#    #+#             */
/*   Updated: 2025/11/19 21:15:13 by mteriier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_file(int fd, int)
{
	char	*buffer;
	int	reader;

	reader = read(fd, buffer, 5000);
	if (reader < 0)
		return (NULL);
	if (!buffer)
		return (free(buffer), NULL);
	buffer[reader]
	return (buffer);
}
