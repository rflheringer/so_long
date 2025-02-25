/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_enemy_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheringe <rheringe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 19:06:36 by rheringe          #+#    #+#             */
/*   Updated: 2025/02/25 15:43:55 by rheringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	load_enemy_images(t_game *game)
{
	game->enemy->e_fr_text[0] = mlx_load_png("assets/warrior_1.png");
	game->enemy->e_fr_img[0] = mlx_texture_to_image(game->mlx,
			game->enemy->e_fr_text[0]);
	game->enemy->e_fr_text[1] = mlx_load_png("assets/warrior_2.png");
	game->enemy->e_fr_img[1] = mlx_texture_to_image(game->mlx,
			game->enemy->e_fr_text[1]);
	game->enemy->e_fr_text[2] = mlx_load_png("assets/warrior_3.png");
	game->enemy->e_fr_img[2] = mlx_texture_to_image(game->mlx,
			game->enemy->e_fr_text[2]);
	game->enemy->e_fr_text[3] = mlx_load_png("assets/warrior_4.png");
	game->enemy->e_fr_img[3] = mlx_texture_to_image(game->mlx,
			game->enemy->e_fr_text[3]);
	game->enemy->e_fr_text[4] = mlx_load_png("assets/warrior_5.png");
	game->enemy->e_fr_img[4] = mlx_texture_to_image(game->mlx,
			game->enemy->e_fr_text[4]);
	game->enemy->e_fr_text[5] = mlx_load_png("assets/warrior_6.png");
	game->enemy->e_fr_img[5] = mlx_texture_to_image(game->mlx,
			game->enemy->e_fr_text[5]);
	game->enemy->e_curr_fr = 0;
	game->enemy->e_curr_img = game->enemy->e_fr_img[game->enemy->e_curr_fr];
	game->enemy->e_fr_count = 6;
	game->enemy->e_fr_delay = 0.3;
}

void	ft_handle_dead(t_game *game)
{
	game->map->moves++;
	mlx_image_to_window(game->mlx, game->image->ground_img,
		game->player->x * TILE_SIZE, game->player->y * TILE_SIZE);
	if (game->map->matrix[game->player->y][game->player->x] != 'E')
		game->map->matrix[game->player->y][game->player->x] = '0';
	center_image_on_screen(game, game->image->exit_img, 0, 0);
	center_image_on_screen(game, game->image->go_img, 0, 0);
	center_image_on_screen(game, game->image->ph_img, 0, 0);
	game->game_over_flag = 1;
	ft_printf("Game Over\n");
}

void	set_enemy_position(t_game *game, int i, int j)
{
	game->enemy->exit = 1;
	game->enemy->enemy = 1;
	game->enemy->e_y = i;
	game->enemy->e_x = j;
	game->game_over_flag = 0;
}	

void	ft_move_enemie(t_game *game, int dx, int dy, t_enemy *enemy)
{
	if (game->map->matrix[enemy->e_y][enemy->e_x] == 'C')
	{
		mlx_image_to_window(game->mlx, game->image->tnt_img,
			game->enemy->e_x * (TILE_SIZE), game->enemy->e_y * (TILE_SIZE));
	}
	if (game->map->matrix[enemy->e_y][enemy->e_x] == 'E' ||
		game->map->matrix[enemy->e_y][enemy->e_x] == 'N')
		handle_exit_e(game);
	if ((game->map->matrix[enemy->e_y][enemy->e_x + 1] != '1'
		|| game->map->matrix[enemy->e_y][enemy->e_x - 1] != '1') &&
			ft_abs(dx) > ft_abs(dy))
	{
		if (dx > 0 && game->map->matrix[enemy->e_y][enemy->e_x + 1] != '1')
			game->enemy->e_x += 1;
		else if (game->map->matrix[enemy->e_y][enemy->e_x - 1] != '1')
			game->enemy->e_x -= 1;
	}
	else if ((game->map->matrix[enemy->e_y + 1][enemy->e_x] != '1'
		|| game->map->matrix[enemy->e_y - 1][enemy->e_x] != '1'))
	{
		if (dy > 0 && game->map->matrix[enemy->e_y + 1][enemy->e_x] != '1')
			game->enemy->e_y += 1;
		else if (game->map->matrix[enemy->e_y - 1][enemy->e_x] != '1')
			game->enemy->e_y -= 1;
	}
}

void	update_enemy(t_game *game, double delta_time)
{
	int	dx;
	int	dy;

	game->enemy->move_time += delta_time;
	game->enemy->move_delay = 0.3;
	if (game->enemy->move_time >= game->enemy->move_delay)
	{
		dx = game->player->x - game->enemy->e_x;
		dy = game->player->y - game->enemy->e_y;
		mlx_delete_image(game->mlx, game->enemy->e_curr_img);
		game->enemy->e_curr_img = mlx_texture_to_image(game->mlx,
				game->enemy->e_fr_text[game->player->current_frame]);
		ft_move_enemie(game, dx, dy, game->enemy);
		game->enemy->move_time = 0;
	}
}
