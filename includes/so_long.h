/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheringe <rheringe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 13:38:27 by rheringe          #+#    #+#             */
/*   Updated: 2025/02/10 19:10:31 by rheringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../libs/includes/libft.h"
#include "../MLX42/include/MLX42/MLX42.h"

#define TILE_SIZE 64 
#define SCREEN_WIDTH 640 
#define SCREEN_HEIGHT 480 

# define EXIT_INVALID_FILE	-3
# define EXIT_INVALID_MAP 	-2
# define EXIT_INVALID_ARGS	-1
# define EXIT_SUCCESS	0
# define EXIT_FAILURE	1

typedef struct s_player
{
	mlx_texture_t	*p_text;
	mlx_image_t		*p_img;
}t_player;

typedef struct s_image
{
	mlx_texture_t	*ground_text;
	mlx_image_t		*ground_img;
	mlx_texture_t	*wall_text;
	mlx_image_t		*wall_img;
	mlx_texture_t	*wall_side_text;
	mlx_image_t		*wall_side_img;	
	mlx_texture_t	*exit_text;
	mlx_image_t		*exit_img;
}t_image;

typedef struct s_map
{
	char		**matrix;
	int			width;
	int			height;
	int			coin;
	int			player;
	int			exit;
	int			moves;
}t_map;

typedef struct s_game
{
	void	*mlx;
	void	*window;
	t_player	player;
	t_map		map;
	t_image		image;
}t_game;

//handle_inits
void	init_images(t_game *game);
void	init_map(t_game *game);
int32_t init_so_long(t_game *game);

//handle_errors functions
void	message_error(short error_code);

//handle_map functions
void	validate_map(char *file, t_game *game);
void	verify_map(t_game *game);

//handle render
void	fill_screen_with_terrain(t_game *game);


#endif