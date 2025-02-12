/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheringe <rheringe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 11:57:15 by rheringe          #+#    #+#             */
/*   Updated: 2025/02/12 19:46:50 by rheringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_handle_common_move(t_game *game, int move_x, int move_y)
{
	game->map.moves++;
	game->player.x += move_x;
	game->player.y += move_y;
}

void	ft_handle_collectable(t_game *game, int move_x, int move_y)
{
	mlx_image_to_window(game->mlx, game->image.ground_img,
		(game->player.x + move_x)* TILE_SIZE, (game->player.y + move_y) * TILE_SIZE);
	game->map.coin--;
	game->map.matrix[game->player.y + move_y][game->player.x + move_x] = '0';
	if (game->map.coin == 0)
	{
		mlx_image_to_window(game->mlx, game->image.ground_img,
			game->map.y_exit * TILE_SIZE, game->map.x_exit * TILE_SIZE);
		mlx_image_to_window(game->mlx, game->image.exit_opn_img,
			game->map.y_exit * TILE_SIZE, game->map.x_exit * TILE_SIZE);
		game->map.matrix[game->map.x_exit][game->map.y_exit] = 'N';
	}
}

void	ft_handle_final_exit(t_game *game, int move_x, int move_y)
{
	game->map.moves++;
	game->player.x += move_x;
	game->player.y += move_y;
	ft_putstr_fd("Moves: ", 1);
	ft_printf("%d\n", game->map.moves);
	ft_putstr_fd("You won\n", 1);
	mlx_close_window(game->mlx);
}
