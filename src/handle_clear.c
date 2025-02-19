/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_clear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheringe <rheringe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 18:41:14 by rheringe          #+#    #+#             */
/*   Updated: 2025/02/18 18:48:01 by rheringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	delete_images(t_game *game)
{
	mlx_delete_image(game->mlx, game->image.ground_img);
	mlx_delete_image(game->mlx, game->image.wall_img);
	mlx_delete_image(game->mlx, game->image.low_w_img);
	mlx_delete_image(game->mlx, game->image.exit_img);
	mlx_delete_image(game->mlx, game->image.final_exit_img);
	mlx_delete_image(game->mlx, game->image.collectable_img);
	mlx_delete_image(game->mlx, game->image.ribbon_img);
	mlx_delete_image(game->mlx, game->enemy.current_img);
	mlx_delete_image(game->mlx, game->player.current_frame_img);
	free_animate_images(game);
}

