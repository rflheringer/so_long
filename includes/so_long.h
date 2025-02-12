/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheringe <rheringe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 13:38:27 by rheringe          #+#    #+#             */
/*   Updated: 2025/02/12 18:56:05 by rheringe         ###   ########.fr       */
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
#define PLAYER_SPEED 5

# define EXIT_INVALID_FILE	-3
# define EXIT_INVALID_MAP 	-2
# define EXIT_INVALID_ARGS	-1
# define EXIT_SUCCESS	0
# define EXIT_FAILURE	1

typedef struct s_player
{
	int				x;
	int				y;
	mlx_texture_t	*p_text;
	mlx_image_t		*p_img;
	bool			up;
	bool			left;
	bool			right;
	bool			down;
	int				current_frame;
	int				frame_count;
	mlx_texture_t	*idle_frames_text[7];
	mlx_image_t		*idle_frames_img[7];
	mlx_texture_t	*current_frame_text;
	mlx_image_t		*current_frame_img;
	double			frame_time;
	double			frame_delay;
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
	mlx_texture_t	*exit_opn_text;
	mlx_image_t		*exit_opn_img;
	mlx_texture_t	*tnt_t;
	mlx_image_t		*tnt_img;
}t_image;

typedef struct s_map
{
	char	**matrix;
	int		width;
	int		height;
	int		coin;
	int		player;
	int		exit;
	int		moves;
	int		x_exit;
	int		y_exit;	
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
double	get_delta_time(void);
void 	main_loop(void *param);

//handle_errors functions
void	message_error(short error_code);
void	ft_clear_window(t_game *game);

//handle_map functions
void	validate_map(char *file, t_game *game);
void	verify_map(t_game *game);
void	load_mine(t_game *game);
void	set_exit_position(t_game *game, int i, int j);

//handle_render functions
void	fill_screen_with_terrain(t_game *game);

//handle_player functions
void    key_hook(mlx_key_data_t keydata, void *param);
void    init_idle_player(t_game *game);
void	move_player(t_game *game, int move_x, int move_y);
void    load_idle_animation_p(t_game *game);
void	update_idle_animation(t_game *game, double delta_time);
void	render_player(t_game *game);
void	set_player_position(t_game *game, int i, int j);

//handle_moves functions
void	ft_handle_common_move(t_game *game, int move_x, int move_y);
void	ft_handle_final_exit(t_game *game, int move_x, int move_y);
void	ft_handle_collectable(t_game *game, int move_x, int move_y);

#endif