/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheringe <rheringe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 11:02:53 by rafaelherin       #+#    #+#             */
/*   Updated: 2025/02/12 23:32:44 by rheringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	load_idle_animation_p(t_game *game)
{
	game->player.idle_frames_text[0] = mlx_load_png("assets/goblin.png");
	game->player.idle_frames_img[0] = mlx_texture_to_image(game->mlx,game->player.idle_frames_text[0]);
	game->player.idle_frames_text[1] = mlx_load_png("assets/goblin_2.png");
	game->player.idle_frames_img[1] = mlx_texture_to_image(game->mlx, game->player.idle_frames_text[1]);
	game->player.idle_frames_text[2] = mlx_load_png("assets/goblin_4.png");
	game->player.idle_frames_img[2] = mlx_texture_to_image(game->mlx, game->player.idle_frames_text[2]);
	game->player.idle_frames_text[3] = mlx_load_png("assets/goblin_3.png");
	game->player.idle_frames_img[3] = mlx_texture_to_image(game->mlx, game->player.idle_frames_text[3]);
	game->player.idle_frames_text[4] = mlx_load_png("assets/goblin_5.png");
	game->player.idle_frames_img[4] = mlx_texture_to_image(game->mlx, game->player.idle_frames_text[4]);
	game->player.idle_frames_text[5] = mlx_load_png("assets/goblin_6.png");
	game->player.idle_frames_img[5] = mlx_texture_to_image(game->mlx, game->player.idle_frames_text[5]);
	game->player.current_frame_img = game->player.idle_frames_img[game->player.current_frame];
	game->player.current_frame = 0;
	game->player.frame_count = 6;
	game->player.frame_delay = 0.1;
}

void key_hook(mlx_key_data_t keydata, void *param)
{
    t_game  *game;

    game = param;
    if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
    {
		if (keydata.key == MLX_KEY_ESCAPE)
			ft_clear_window(game->mlx);
        if (keydata.key == MLX_KEY_RIGHT || keydata.key == MLX_KEY_D)
            move_player(game, 1, 0);
        if (keydata.key == MLX_KEY_LEFT || keydata.key == MLX_KEY_A)
            move_player(game, -1, 0);
         if (keydata.key == MLX_KEY_UP || keydata.key == MLX_KEY_W)
            move_player(game, 0, -1);
         if (keydata.key == MLX_KEY_DOWN || keydata.key == MLX_KEY_S)
            move_player(game, 0, 1);
    }
}

void move_player(t_game *game, int move_x, int move_y)
{
	if (game->map.matrix[game->player.y + move_y][game->player.x + move_x] == '1')
		return ;
	if (game->map.matrix[game->player.y + move_y][game->player.x + move_x] == 'C')
		ft_handle_collectable(game, move_x, move_y);
	if (game->map.matrix[game->player.y + move_y][game->player.x + move_x] == 'N')
	{
		ft_handle_final_exit(game, move_x, move_y);
		return ;
	}
	if (game->map.matrix[game->player.y + move_y][game->player.x + move_x] == 'K')
	{
		ft_handle_dead(game, move_x, move_y);
		return ;
	}
    ft_handle_common_move(game, move_x, move_y);
    render_player(game);
}

void update_idle_animation(t_game *game, double delta_time)
{
    game->player.frame_time += delta_time;

    if (game->player.frame_time >= game->player.frame_delay)
    {
        game->player.current_frame = (game->player.current_frame + 1) % game->player.frame_count;
        game->player.frame_time = 0;
    }
}	

void	set_player_position(t_game *game, int i, int j)
{
	game->map.player++;
	game->player.y = j;
	game->player.x = i;
}

void render_player(t_game *game)
{
    if (game->player.current_frame_img)
        mlx_delete_image(game->mlx, game->player.current_frame_img);
    game->player.current_frame_img = mlx_texture_to_image(game->mlx, game->player.idle_frames_text[game->player.current_frame]);
    mlx_resize_image(game->player.current_frame_img, 64, 64);
    mlx_image_to_window(game->mlx, game->player.current_frame_img, game->player.x * TILE_SIZE, game->player.y * TILE_SIZE);
	if (game->enemy.e_curr_img)
        mlx_image_to_window(game->mlx, game->image.ground_img, game->enemy.e_x * TILE_SIZE, game->enemy.e_y * TILE_SIZE);
    game->enemy.e_curr_img = mlx_texture_to_image(game->mlx, game->enemy.e_fr_text[game->player.current_frame]);
    mlx_resize_image(game->enemy.e_curr_img, 64, 64);
    mlx_image_to_window(game->mlx, game->enemy.e_curr_img, game->enemy.e_x * TILE_SIZE, game->enemy.e_y * TILE_SIZE);
}
