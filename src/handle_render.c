/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_render.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheringe <rheringe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 19:07:37 by rheringe          #+#    #+#             */
/*   Updated: 2025/02/24 15:32:04 by rheringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	fill_screen_with_terrain(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (i++, game->map->matrix[i])
	{
		j = -1;
		while (j++, game->map->matrix[i][j])
		{
			mlx_image_to_window(game->mlx, game->image->ground_img,
				j * TILE_SIZE, i * TILE_SIZE);
			if (game->map->matrix[i][j] == '1')
				put_wall(game, i, j);
			if (game->map->matrix[i][j] == 'P')
				put_ply(game, i, j);
			if (game->map->matrix[i][j] == 'E')
				put_ground(game, i, j);
			if (game->map->matrix[i][j] == 'C')
			{
				mlx_image_to_window(game->mlx, game->image->tnt_img,
					j * TILE_SIZE, i * TILE_SIZE);
			}
		}
	}
}

void	put_wall(t_game *game, int i, int j)
{
	if (game->map->matrix[i][j] == '1' && i == game->map->height - 1)
		mlx_image_to_window(game->mlx, game->image->wall_img,
			j * TILE_SIZE, i * TILE_SIZE);
	else if (game->map->matrix[i][j] == '1' &&
		j == 0 && i != game->map->height - 1)
		mlx_image_to_window(game->mlx, game->image->grassl_img,
			j * TILE_SIZE, i * TILE_SIZE);
	else if (game->map->matrix[i][j] == '1' && j != 0 &&
		j != game->map->width - 1 && i != game->map->height - 1
		&& game->map->matrix[i + 1][j] != '1')
		mlx_image_to_window(game->mlx, game->image->wall_img,
			j * TILE_SIZE, i * TILE_SIZE);
	else if (game->map->matrix[i][j] == '1')
		mlx_image_to_window(game->mlx, game->image->wall_side_img,
			j * TILE_SIZE, i * TILE_SIZE);
}

void	put_ply(t_game *game, int i, int j)
{
	mlx_image_to_window(game->mlx, game->image->ground_img,
		j * (TILE_SIZE), i * (TILE_SIZE));
	mlx_image_to_window(game->mlx, game->player->idle_frames_img[0],
		j * (TILE_SIZE), i * (TILE_SIZE));
}

void	put_ground(t_game *game, int i, int j)
{
	mlx_image_to_window(game->mlx, game->image->ground_img,
		j * TILE_SIZE, i * TILE_SIZE);
	mlx_image_to_window(game->mlx, game->image->exit_img,
		j * (TILE_SIZE - 3), i * (TILE_SIZE - 6));
}

void	set_exit_position(t_game *game, int i, int j)
{
	game->map->exit++;
	game->map->x_exit = i;
	game->map->y_exit = j;
}
