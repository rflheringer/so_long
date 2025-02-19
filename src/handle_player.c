/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheringe <rheringe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 11:02:53 by rafaelherin       #+#    #+#             */
/*   Updated: 2025/02/18 18:37:52 by rheringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_player(void *param)
{
	t_game	*game;
	double	delta_time;

	delta_time = get_delta_time();
	game = param;
	if (game->game_over_flag == 1)
		return ;
	update_idle_animation(game, delta_time);
	render_player(game);
	if (game->enemy.exit > 0
		&& ft_strnstr(game->file, "mov", ft_strlen(game->file)))
		update_enemy(game, delta_time);
	if (game->player.x == game->enemy.e_x
		&& game->player.y == game->enemy.e_y)
		ft_handle_dead(game);
}

void	update_idle_animation(t_game *game, double delta_time)
{
	game->player.frame_time += delta_time;
	if (game->player.frame_time >= game->player.frame_delay)
	{
		game->player.current_frame = (game->player.current_frame + 1) % game->player.frame_count;
		game->player.frame_time = 0;
	}
}

void	main_move(mlx_key_data_t keydata, void *param)
{
	t_game	*game;
	double	delta_time;

	game = param;
	delta_time = get_delta_time_again();
	if (game->game_over_flag == 1)
		return ;
	set_hooks(keydata, game, delta_time);
}

void	set_hooks(mlx_key_data_t keydata, t_game *game, double delta_time)
{
	if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
	{
		game->player.current_frame = 0;
		game->player.frame_time += delta_time;
		game->player.frame_delay = 0.1;
		if ((game->player.frame_time >= game->player.frame_delay
				&& keydata.action == MLX_REPEAT) || keydata.action == MLX_PRESS)
		{
			if (keydata.key == MLX_KEY_ESCAPE)
				mlx_close_window(game->mlx);
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
}

void	move_player(t_game *game, int move_x, int move_y)
{
	if (game->map.matrix[game->player.y + move_y][game->player.x + move_x] == '1')
		return ;
	if (game->map.matrix[game->player.y + move_y][game->player.x + move_x] == 'C')
		ft_handle_collectable(game, move_x, move_y);
	if (game->map.matrix[game->player.y + move_y][game->player.x + move_x] == 'N')
	{
		ft_handle_final_exit(game);
		return ;
	}
	ft_handle_common_move(game, move_x, move_y);
	render_player(game);
}
