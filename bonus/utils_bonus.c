/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheringe <rheringe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 19:07:53 by rheringe          #+#    #+#             */
/*   Updated: 2025/02/25 16:53:26 by rheringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	load_idle_animation_p(t_game *game)
{
	game->player->idle_frames_text[0] = mlx_load_png("assets/goblin.png");
	game->player->idle_frames_img[0] = mlx_texture_to_image(game->mlx,
			game->player->idle_frames_text[0]);
	game->player->idle_frames_text[1] = mlx_load_png("assets/goblin_2.png");
	game->player->idle_frames_img[1] = mlx_texture_to_image(game->mlx,
			game->player->idle_frames_text[1]);
	game->player->idle_frames_text[2] = mlx_load_png("assets/goblin_4.png");
	game->player->idle_frames_img[2] = mlx_texture_to_image(game->mlx,
			game->player->idle_frames_text[2]);
	game->player->idle_frames_text[3] = mlx_load_png("assets/goblin_3.png");
	game->player->idle_frames_img[3] = mlx_texture_to_image(game->mlx,
			game->player->idle_frames_text[3]);
	game->player->idle_frames_text[4] = mlx_load_png("assets/goblin_5.png");
	game->player->idle_frames_img[4] = mlx_texture_to_image(game->mlx,
			game->player->idle_frames_text[4]);
	game->player->idle_frames_text[5] = mlx_load_png("assets/goblin_6.png");
	game->player->idle_frames_img[5] = mlx_texture_to_image(game->mlx,
			game->player->idle_frames_text[5]);
	game->player->current_frame_img = game->player->idle_frames_img[
		game->player->current_frame];
	game->player->frame_time = 0.0;
	game->player->frame_delay = 0.3;
	game->player->frame_count = 6;
}

void	set_player_position(t_game *game, int i, int j)
{
	game->map->player++;
	game->player->y = i;
	game->player->x = j;
}

void	render_player(t_game *game)
{
	if (game->player->current_frame_img)
		mlx_delete_image(game->mlx, game->player->current_frame_img);
	game->player->current_frame_img = mlx_texture_to_image(game->mlx,
			game->player->idle_frames_text[game->player->current_frame]);
	mlx_resize_image(game->player->current_frame_img, 64, 64);
	mlx_image_to_window(game->mlx, game->player->current_frame_img,
		game->player->x * TILE_SIZE, game->player->y * TILE_SIZE);
	if (game->enemy->enemy == 1)
	{
		if (game->enemy->e_curr_img)
			mlx_image_to_window(game->mlx, game->image->ground_img,
				game->enemy->e_x * TILE_SIZE, game->enemy->e_y * TILE_SIZE);
		game->enemy->e_curr_img = mlx_texture_to_image(game->mlx,
				game->enemy->e_fr_text[game->player->current_frame]);
		mlx_resize_image(game->enemy->e_curr_img, 64, 64);
		mlx_image_to_window(game->mlx, game->enemy->e_curr_img,
			game->enemy->e_x * TILE_SIZE, game->enemy->e_y * TILE_SIZE);
	}
}

double	get_delta_time_again(void)
{
	static double	last_time = 0;
	double			current_time;
	double			delta_time;

	current_time = mlx_get_time();
	delta_time = current_time - last_time;
	last_time = current_time;
	return (delta_time);
}

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}
