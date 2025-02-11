/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_inits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelheringer <rafaelheringer@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:12:18 by rheringe          #+#    #+#             */
/*   Updated: 2025/02/11 18:32:45 by rafaelherin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void main_loop(void *param)
{
    t_game *game = (t_game *)param;
    double delta_time = get_delta_time();

    // Atualiza a animação de IDLE
    update_idle_animation(game, delta_time);

    // Renderiza o player
    render_player(game);
}


double get_delta_time(void) 
{
    static double last_time = 0;
    double current_time = mlx_get_time();
    double delta_time = current_time - last_time;
    last_time = current_time;
    return delta_time;
}


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
    mlx_loop_hook(game->mlx, main_loop, game);
    mlx_loop(game->mlx);
    return (0);
}

void	init_images(t_game *game)
{
	load_idle_animation_p(game);
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

