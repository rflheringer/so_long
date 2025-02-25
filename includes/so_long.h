/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheringe <rheringe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 13:38:27 by rheringe          #+#    #+#             */
/*   Updated: 2025/02/24 17:08:38 by rheringe         ###   ########.fr       */
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


# define EXIT_MAP_NOT_CLOSED -12
# define EXIT_NO_PATH -11
# define EXIT_LINE_SIZE -10
# define EXIT_MISSING_C	-9
# define EXIT_MISSING_P	-8
# define EXIT_MISSING_E	-7
# define EXIT_TOO_SHORT	-6
# define EXIT_MUST_BE_RECTANGULAR	-5
# define EXIT_INVALID_CHAR	-4
# define EXIT_INVALID_EXTENTION	-3
# define EXIT_INVALID_FILE	-2
# define EXIT_SUCCESS	0

typedef struct s_enemy
{
	mlx_image_t		*e_curr_img;
	mlx_texture_t	*e_fr_text[6];
	mlx_image_t		*e_fr_img[6];
	int				e_curr_fr;
	int				e_fr_count;
	double			e_fr_time;
	double			e_fr_delay;
	int				e_x;
	int				e_y;
	double 			move_time;
    double 			move_delay; 
	int				exit;
}t_enemy;

typedef struct s_player
{
	int				x;
	int				y;
	bool			up;
	bool			left;
	bool			right;
	bool			down;
	int				current_frame;
	int				frame_count;
	mlx_texture_t	*idle_frames_text[6];
	mlx_image_t		*idle_frames_img[6];
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
	mlx_texture_t	*tnt_txt;
	mlx_image_t		*tnt_img;
	mlx_texture_t	*go_txt;
	mlx_image_t		*go_img;
	mlx_texture_t	*ph_txt;
	mlx_image_t		*ph_img;
	mlx_texture_t	*grassl_txt;
	mlx_image_t		*grassl_img;
	mlx_texture_t	*rm_txt;
	mlx_image_t		*rm_img;
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
	char	**map_copy;
}t_map;

typedef struct s_game
{
	void		*mlx;
	void		*window;
	char		*file;
	t_player	*player;
	t_map		*map;
	t_image		*image;
	t_enemy		*enemy;
	int			game_over_flag;
	int			enemy_flag;
}t_game;

//handle_inits
void	init_map(t_game *game);
int32_t	init_so_long(t_game *game);



void	init_images(t_game *game);
void	init_map(t_game *game);
int32_t init_so_long(t_game *game);
double	get_delta_time(void);
void 	main_loop(void *param);

//handle_errors functions
void	message_error(short error_code, t_game *game);
void	ft_clear_window(t_game *game);
void	free_file(t_game *game);
void	ft_move_enemie(t_game *game, int dx, int dy, t_enemy *enemie);

//handle_map functions
void	validate_map(char *file, t_game *game);
void	put_map(t_game *game);
void	verify_map(t_game *game);
bool	check_line_size(t_game *game);

void	load_mine(t_game *game);
void	set_exit_position(t_game *game, int i, int j);
int		is_closed(t_game *game, int i, int j);

//handle_render functions
void	fill_screen_with_terrain(t_game *game);
void 	put_wall(t_game *game, int i, int j);
void	put_ply(t_game *game, int i, int j);
void	put_ground(t_game *game, int i, int j);

//handle_player functions
void	ft_player(void *param);
void	update_idle_animation(t_game *game, double delta_time);
void	main_move(mlx_key_data_t keydata, void *param);
void	set_hooks(mlx_key_data_t keydata, t_game *game, double delta_time);
void	move_player(t_game *game, int move_x, int move_y);

//void    init_idle_player(t_game *game);
void    load_idle_animation_p(t_game *game);
void	render_player(t_game *game);
void	set_player_position(t_game *game, int i, int j);
void	main_move(mlx_key_data_t keydata, void *param);
double	get_delta_time_again(void);

//handle_moves functions
void	ft_handle_final_exit(t_game *game);

void	ft_handle_common_move(t_game *game, int move_x, int move_y);
void	ft_handle_collectable(t_game *game, int move_x, int move_y);

//handle_flood_fill
void	copy_map(t_game *game);
void	flood_fill(t_game *game, int x, int y);
void	verify_flood_fill(t_game *game);


//###########################################################################################################################

//handle_enemys function
void	load_enemy_images(t_game *game);
void	set_enemy_position(t_game *game, int i, int j);
void	ft_move_enemie(t_game *game, int dx, int dy, t_enemy *enemy);
void	update_enemy(t_game *game, double delta_time);
void	ft_handle_dead(t_game *game);

void	render_enemy(t_game *game);

int	ft_abs(int n);
void center_image_on_screen(t_game *game, mlx_image_t *img, int offset_x, int offset_y);
void	ft_free(char **ptr_matrix, int j);
void	free_and_close_error(t_game *game, short error_code);
void	delete_images_texture(t_game *game);
void	free_and_close(t_game *game);
void	free_animate_images(t_game *game);

void	init_images_again(t_game *game);
void	handle_exit_e(t_game *game);

#endif