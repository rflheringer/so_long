/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_inits_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheringe <rheringe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 19:07:07 by rheringe          #+#    #+#             */
/*   Updated: 2025/02/25 15:44:06 by rheringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	init_map(t_game *game)
{
	game->map->matrix = NULL;
	game->map->width = 0;
	game->map->height = 0;
	game->map->coin = 0;
	game->map->player = 0;
	game->map->exit = 0;
	game->map->moves = 0;
	game->map->x_exit = 0;
	game->map->y_exit = 0;
}

int32_t	init_so_long(t_game *game)
{
	game->image = ft_calloc(1, sizeof(t_image));
	game->mlx = mlx_init(game->map->width * TILE_SIZE,
			game->map->height * TILE_SIZE, "so_long", false);
	init_images(game);
	fill_screen_with_terrain(game);
	mlx_key_hook(game->mlx, main_move, game);
	mlx_loop_hook(game->mlx, ft_player, game);
	mlx_loop(game->mlx);
	free_and_close(game);
	mlx_terminate(game->mlx);
	return (0);
}

void	init_images(t_game *game)
{
	load_idle_animation_p(game);
	load_mine(game);
	load_enemy_images(game);
	game->image->grassl_txt = mlx_load_png("assets/grass_left.png");
	game->image->grassl_img = mlx_texture_to_image(game->mlx,
			game->image->grassl_txt);
	mlx_resize_image(game->image->grassl_img, TILE_SIZE, TILE_SIZE);
	game->image->ground_text = mlx_load_png("assets/sand.png");
	game->image->ground_img = mlx_texture_to_image(game->mlx,
			game->image->ground_text);
	mlx_resize_image(game->image->ground_img, TILE_SIZE, TILE_SIZE);
	game->image->wall_text = mlx_load_png("assets/wall_grass.png");
	game->image->wall_img = mlx_texture_to_image(game->mlx,
			game->image->wall_text);
	mlx_resize_image(game->image->wall_img, TILE_SIZE, TILE_SIZE);
	game->image->wall_side_text = mlx_load_png("assets/grass.png");
	game->image->wall_side_img = mlx_texture_to_image(game->mlx,
			game->image->wall_side_text);
	mlx_resize_image(game->image->wall_side_img, TILE_SIZE, TILE_SIZE);
	game->image->tnt_txt = mlx_load_png("assets/tnt.png");
	game->image->tnt_img = mlx_texture_to_image(game->mlx,
			game->image->tnt_txt);
	mlx_resize_image(game->image->tnt_img, 30, 50);
	init_images_again(game);
}

double	get_delta_time(void)
{
	static double	last_time = 0;
	double			current_time;
	double			delta_time;

	current_time = mlx_get_time();
	delta_time = current_time - last_time;
	last_time = current_time;
	return (delta_time);
}

void	init_images_again(t_game *game)
{
	game->image->go_txt = mlx_load_png("assets/ribbon.png");
	game->image->go_img = mlx_texture_to_image(game->mlx, game->image->go_txt);
	mlx_resize_image(game->image->go_img, (game->map->width * TILE_SIZE / 2),
		(game->map->height * TILE_SIZE / 2));
	game->image->ph_txt = mlx_load_png("assets/you_died.png");
	game->image->ph_img = mlx_texture_to_image(game->mlx, game->image->ph_txt);
	mlx_resize_image(game->image->ph_img, ((game->map->width * TILE_SIZE / 8.5))
		* 2, (game->map->height * TILE_SIZE / 2));
	game->image->rm_txt = mlx_load_png("assets/move_ribbon.png");
	game->image->rm_img = mlx_texture_to_image(game->mlx, game->image->rm_txt);
	mlx_resize_image(game->image->rm_img, 200, 100);
}
