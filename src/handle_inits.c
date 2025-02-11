/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_inits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelheringer <rafaelheringer@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:12:18 by rheringe          #+#    #+#             */
/*   Updated: 2025/02/11 17:22:56 by rafaelherin      ###   ########.fr       */
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
    game->mlx = mlx_init(game->map.width * TILE_SIZE, game->map.height * TILE_SIZE, "so_long", false);
    if (!game->mlx)
		return (1);
	init_images(game);
	mlx_delete_texture(game->image.ground_text);
	mlx_resize_image(game->image.ground_img, TILE_SIZE, TILE_SIZE);
    fill_screen_with_terrain(game);
	mlx_key_hook(game->mlx, key_hook, game);
    mlx_loop(game->mlx);
    return (0);
}

void	init_images(t_game *game)
{
	//IDLE
	game->player.idle_frames_text = mlx_load_png("assets/goblin.png");
    game->player.idle_frames_img = mlx_texture_to_image(game->mlx, game->player.idle_frames_text);
	mlx_resize_image(game->player.idle_frames_img, 42, 42);
    // game->player.idle_frames_text[1] = mlx_load_png("assets/goblin_2.png");
    // game->player.idle_frames_img[1] = mlx_texture_to_image(game->mlx, game->player.idle_frames_text[1]);
	// mlx_resize_image(game->player.idle_frames_img[1], 42, 42);
    // game->player.idle_frames_text[2] = mlx_load_png("assets/goblin_3.png");
    // game->player.idle_frames_img[2] = mlx_texture_to_image(game->mlx, game->player.idle_frames_text[2]);
	// mlx_resize_image(game->player.idle_frames_img[2], 42, 42);
    // game->player.idle_frames_text[3] = mlx_load_png("assets/goblin_4.png");
    // game->player.idle_frames_img[3] = mlx_texture_to_image(game->mlx, game->player.idle_frames_text[3]);
	// mlx_resize_image(game->player.idle_frames_img[3], 42, 42);
    // game->player.idle_frames_text[4] = mlx_load_png("assets/goblin_5.png");
    // game->player.idle_frames_img[4] = mlx_texture_to_image(game->mlx, game->player.idle_frames_text[4]);
	// mlx_resize_image(game->player.idle_frames_img[4], 42, 42);
    // game->player.idle_frames_text[5] = mlx_load_png("assets/goblin_6.png");
    // game->player.idle_frames_img[5] = mlx_texture_to_image(game->mlx, game->player.idle_frames_text[5]);
	// mlx_resize_image(game->player.idle_frames_img[5], 42, 42);
    // game->player.idle_frames_text[6] = mlx_load_png("assets/goblin_7.png");
    // game->player.idle_frames_img[6] = mlx_texture_to_image(game->mlx, game->player.idle_frames_text[6]);
	// mlx_resize_image(game->player.idle_frames_img[6], 42, 42);
	//IDLE
	game->image.ground_text = mlx_load_png("assets/sand.png");
	game->image.ground_img = mlx_texture_to_image(game->mlx, game->image.ground_text);
	mlx_resize_image(game->image.ground_img, TILE_SIZE, TILE_SIZE);
	game->image.wall_text = mlx_load_png("assets/wall_grass.png");
	game->image.wall_img = mlx_texture_to_image(game->mlx, game->image.wall_text);
	mlx_resize_image(game->image.wall_img, TILE_SIZE, TILE_SIZE);
	game->image.wall_side_text = mlx_load_png("assets/grass.png");
	game->image.wall_side_img = mlx_texture_to_image(game->mlx, game->image.wall_side_text);
	mlx_resize_image(game->image.wall_side_img, TILE_SIZE, TILE_SIZE);
	game->image.exit_text = mlx_load_png("assets/mine_closed.png");
	game->image.exit_img = mlx_texture_to_image(game->mlx, game->image.exit_text);
	mlx_resize_image(game->image.exit_img, 76, 76);
	game->image.tnt_t = mlx_load_png("assets/tnt.png");
	game->image.tnt_img = mlx_texture_to_image(game->mlx, game->image.tnt_t);
	mlx_resize_image(game->image.tnt_img, 30, 50);
}

