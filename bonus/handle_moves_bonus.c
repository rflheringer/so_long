/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_moves_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheringe <rheringe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 19:04:37 by rheringe          #+#    #+#             */
/*   Updated: 2025/02/25 16:48:13 by rheringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	ft_handle_exit(t_game *game, int x, int y)
{
	if (game->map->matrix[game->player->y][game->player->x] != '0')
		mlx_image_to_window(game->mlx, game->image->ground_img,
			game->player->x * TILE_SIZE, game->player->y * TILE_SIZE);
	else if (game->map->matrix[game->player->y][game->player->x] != 'E')
		game->map->matrix[game->player->y][game->player->x] = '0';
	else
		mlx_image_to_window(game->mlx, game->image->exit_img,
			game->player->x * TILE_SIZE + 17, game->player->y * TILE_SIZE + 34);
	game->map->moves++;
	game->player->x += x;
	game->player->y += y;
}

void	ft_handle_final_exit(t_game *game)
{
	game->map->matrix[game->player->y][game->player->x] = '0';
	mlx_image_to_window(game->mlx,
		game->image->ground_img, game->player->x * TILE_SIZE,
		game->player->y * TILE_SIZE);
	game->map->moves++;
	ft_printf("Moves: %d\n", game->map->moves);
	ft_printf("You Won!");
	mlx_close_window(game->mlx);
}

void	ft_handle_common_move(t_game *game, int move_x, int move_y)
{
	char	*nb;
	char	*move;

	if (game->map->matrix[game->player->y][game->player->x] == 'C')
		game->map->matrix[game->player->y][game->player->x] = '0';
	else if (game->map->matrix[game->player->y][game->player->x] == 'E')
		mlx_image_to_window(game->mlx, game->image->exit_img,
			game->player->x * (TILE_SIZE -3),
			game->player->y * (TILE_SIZE - 6));
	game->map->moves++;
	game->player->x += move_x;
	game->player->y += move_y;
	nb = ft_itoa(game->map->moves);
	move = ft_strjoin("Moves: ", nb);
	mlx_image_to_window(game->mlx, game->image->rm_img,
		game->map->width * TILE_SIZE - 200, -22);
	mlx_put_string(game->mlx, move, game->map->width * TILE_SIZE - 133, 15);
	free(move);
	free(nb);
}

void	ft_handle_collectable(t_game *game, int move_x, int move_y)
{
	mlx_image_to_window(game->mlx, game->image->ground_img,
		(game->player->x + move_x) * TILE_SIZE,
		(game->player->y + move_y) * TILE_SIZE);
	game->map->coin--;
	game->map->matrix[game->player->y + move_y][game->player->x + move_x] = '0';
	if (game->map->coin == 0)
	{
		mlx_image_to_window(game->mlx, game->image->ground_img,
			game->map->y_exit * TILE_SIZE, game->map->x_exit * TILE_SIZE);
		mlx_image_to_window(game->mlx, game->image->exit_opn_img,
			game->map->y_exit * TILE_SIZE, game->map->x_exit * TILE_SIZE);
		game->map->matrix[game->map->x_exit][game->map->y_exit] = 'N';
	}
}

void	handle_exit_e(t_game *game)
{
	if (game->map->coin == 0)
	{
		mlx_image_to_window(game->mlx, game->image->exit_opn_img,
			game->map->y_exit * TILE_SIZE,
			game->map->x_exit * TILE_SIZE);
	}
	else
		mlx_image_to_window(game->mlx, game->image->exit_img,
			game->enemy->e_x * (TILE_SIZE),
			game->enemy->e_y * (TILE_SIZE));
}
