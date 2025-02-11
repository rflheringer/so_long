/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_render.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelheringer <rafaelheringer@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:35:25 by rheringe          #+#    #+#             */
/*   Updated: 2025/02/11 17:27:33 by rafaelherin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void fill_screen_with_terrain(t_game *game)
{
    int i;
	int j;

    i = -1;		
	while (i++, game->map.matrix[i])
	{
		j = -1;
		while (j++, game->map.matrix[i][j])
		{
			mlx_image_to_window(game->mlx, game->image.ground_img, j * TILE_SIZE, i * TILE_SIZE);
			if (game->map.matrix[i][j] == '1' && i == game->map.height - 1)
				mlx_image_to_window(game->mlx, game->image.wall_img, j * TILE_SIZE, i * TILE_SIZE);
			else if (game->map.matrix[i][j] == '1' && j != 0 && j != game->map.width - 1 && i != game->map.height - 1 && game->map.matrix[i + 1][j] != '1')
				mlx_image_to_window(game->mlx, game->image.wall_img, j * TILE_SIZE, i * TILE_SIZE);
			else if (game->map.matrix[i][j] == '1')
				mlx_image_to_window(game->mlx, game->image.wall_side_img, j * TILE_SIZE, i * TILE_SIZE);
			if (game->map.matrix[i][j] == 'P')
			{
				mlx_image_to_window(game->mlx, game->image.ground_img, j * (TILE_SIZE), i * (TILE_SIZE));
				mlx_image_to_window(game->mlx, game->player.idle_frames_img, j * (TILE_SIZE), i * (TILE_SIZE));
			}
			if (game->map.matrix[i][j] == 'E')
			{
				mlx_image_to_window(game->mlx, game->image.ground_img, j * TILE_SIZE, i * TILE_SIZE);
				mlx_image_to_window(game->mlx, game->image.exit_img, j * (TILE_SIZE - 3), i * (TILE_SIZE - 6));
			}
			if (game->map.matrix[i][j] == 'C')
			{
				mlx_image_to_window(game->mlx, game->image.tnt_img, j * TILE_SIZE, i * TILE_SIZE);
				mlx_image_to_window(game->mlx, game->image.tnt_img, j * (TILE_SIZE), i * (TILE_SIZE));
			}
		}
	}
}

	