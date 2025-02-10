/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_inits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheringe <rheringe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:12:18 by rheringe          #+#    #+#             */
/*   Updated: 2025/02/10 19:27:45 by rheringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_map(t_game *game)
{
	game->map.matrix = NULL;
	game->map.width = 0;
	game->map.height = 0;
	game->map.coin = 0;
	game->map.player = 0;
	game->map.exit = 0;
	game->map.moves = 0;
}

int32_t init_so_long(t_game *game)
{
    game->mlx = mlx_init(game->map.width * TILE_SIZE, game->map.height * TILE_SIZE, "so_long", true);
    if (!game->mlx)
		return (1);
	init_images(game);
	mlx_delete_texture(game->image.ground_text);
	mlx_resize_image(game->image.ground_img, TILE_SIZE, TILE_SIZE);
    fill_screen_with_terrain(game);
    mlx_loop(game->mlx);
    return (0);
}

void	init_images(t_game *game)
{
	game->image.ground_text = mlx_load_png("assets/sand.png");
	game->image.ground_img = mlx_texture_to_image(game->mlx, game->image.ground_text);
	mlx_resize_image(game->image.ground_img, TILE_SIZE, TILE_SIZE);
	game->image.wall_text = mlx_load_png("assets/wall_grass.png");
	game->image.wall_img = mlx_texture_to_image(game->mlx, game->image.wall_text);
	mlx_resize_image(game->image.wall_img, TILE_SIZE, TILE_SIZE);
	game->image.wall_side_text = mlx_load_png("assets/grass.png");
	game->image.wall_side_img = mlx_texture_to_image(game->mlx, game->image.wall_side_text);
	mlx_resize_image(game->image.wall_side_img, TILE_SIZE, TILE_SIZE);
	game->player.p_text = mlx_load_png("assets/goblin.png");
	game->player.p_img = mlx_texture_to_image(game->mlx, game->player.p_text);
	mlx_resize_image(game->player.p_img, 42, 42);
	game->image.exit_text = mlx_load_png("assets/mine_closed.png");
	game->image.exit_img = mlx_texture_to_image(game->mlx, game->image.exit_text);
	mlx_resize_image(game->image.exit_img, 76, 76);
}
