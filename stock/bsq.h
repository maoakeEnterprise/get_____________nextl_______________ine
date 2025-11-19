/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaillet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 15:31:15 by dgaillet          #+#    #+#             */
/*   Updated: 2025/09/03 18:00:14 by dgaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

char	*gen_tab_params(char *namefile);
void	display_grid(char **grid);
char	**launch_gen(char *namefile);
int		*solver(char **map, int max_size, char *params, int *greatest_loc);
void	write_greatest_square(char **map, int *loc, char *params);
int		parsing(char **map, char *params);
char	**init_big_grid(char *buffer);
char	*init_line(char *buffer, int index);
char	*launch_no_arg(void);
void	free_grid(char **big_grid);

#endif
