/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelheringer <rafaelheringer@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 11:02:53 by rafaelherin       #+#    #+#             */
/*   Updated: 2025/02/11 17:25:15 by rafaelherin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"


void key_hook(mlx_key_data_t keydata, void *param)
{
    t_game  *game;

    game = param;
    if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
    {
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

void	move_player(t_game *game, int move_x, int move_y)
{
	ft_handle_common_move(game, move_x, move_y);
    mlx_image_to_window(game->mlx, game->player.idle_frames_img, game->player.x * TILE_SIZE, game->player.y * TILE_SIZE);
	ft_printf("Moves: %d\n", game->map.moves);
    ft_printf("Nova posição do jogador: (%d, %d)\n", game->player.x, game->player.y);
}

void	ft_handle_common_move(t_game *game, int move_x, int move_y)
{

	mlx_image_to_window(game->mlx, game->image.ground_img, game->player.x * TILE_SIZE, game->player.y * TILE_SIZE);
	//mlx_image_to_window(game->mlx, game->image.exit_img, game->player.x * TILE_SIZE + 12, game->player.y * TILE_SIZE + 12);
	game->map.moves++;
	game->player.x += move_x;
	game->player.y += move_y;
}
