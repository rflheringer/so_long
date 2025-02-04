/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheringe <rheringe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 13:38:27 by rheringe          #+#    #+#             */
/*   Updated: 2025/02/04 15:11:41 by rheringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define EXIT_INVALID_FILE	-3
# define EXIT_INVALID_MAP 	-2
# define EXIT_INVALID_ARGS	-1
# define EXIT_SUCCESS	0
# define EXIT_FAILURE	1
# define TILE_SIZE	100

typedef struct s_map
{
	char	**matrix;
	int		width;
	int		height;
	int		coin;
	int		player;
	int		exit;
}t_map;

typedef struct s_game
{
	t_map *map;
}t_game;

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../libs/includes/libft.h"
#include "../MLX42/include/MLX42/MLX42.h"

//handle_inits
void	init_map(t_map *map);
t_game	*init_game(t_map *map);

//handle_errors functions
void	message_error(short error_code);

//handle_map functions
void	validate_map(char *file, t_map *map);
void	verify_map(t_map *map);

//codan functions
int32_t init_window(t_game *game);


#endif