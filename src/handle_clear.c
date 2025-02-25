/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_clear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheringe <rheringe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 19:08:23 by rheringe          #+#    #+#             */
/*   Updated: 2025/02/24 15:30:47 by rheringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	delete_images(t_game *game)
{
	delete_images_texture(game);
	mlx_delete_image(game->mlx, game->image->ground_img);
	mlx_delete_image(game->mlx, game->image->wall_img);
	mlx_delete_image(game->mlx, game->image->wall_side_img);
	mlx_delete_image(game->mlx, game->image->exit_img);
	mlx_delete_image(game->mlx, game->image->exit_opn_img);
	mlx_delete_image(game->mlx, game->image->tnt_img);
	mlx_delete_image(game->mlx, game->image->go_img);
	mlx_delete_image(game->mlx, game->image->ph_img);
	mlx_delete_image(game->mlx, game->image->rm_img);
	mlx_delete_image(game->mlx, game->image->grassl_img);
	mlx_delete_image(game->mlx, game->player->current_frame_img);
	mlx_delete_image(game->mlx, game->enemy->e_curr_img);
	free_animate_images(game);
}

void	free_animate_images(t_game *game)
{
	int	i;

	i = 6;
	while (i--)
	{
		mlx_delete_texture(game->player->idle_frames_text[i]);
		mlx_delete_image(game->mlx, game->player->idle_frames_img[i]);
		mlx_delete_texture(game->enemy->e_fr_text[i]);
		mlx_delete_image(game->mlx, game->enemy->e_fr_img[i]);
	}
}

void	free_and_close(t_game *game)
{
	delete_images(game);
	mlx_terminate(game->mlx);
	ft_free(game->map->matrix, ft_ptrlen(game->map->matrix));
	ft_free(game->map->map_copy, ft_ptrlen(game->map->map_copy));
	free(game->player);
	free(game->map);
	free(game->enemy);
	free(game->image);
	free(game);
	exit(0);
}

void	delete_images_texture(t_game *game)
{
	mlx_delete_texture(game->image->ground_text);
	mlx_delete_texture(game->image->wall_text);
	mlx_delete_texture(game->image->wall_side_text);
	mlx_delete_texture(game->image->exit_text);
	mlx_delete_texture(game->image->exit_opn_text);
	mlx_delete_texture(game->image->tnt_txt);
	mlx_delete_texture(game->image->go_txt);
	mlx_delete_texture(game->image->ph_txt);
	mlx_delete_texture(game->image->rm_txt);
	mlx_delete_texture(game->image->grassl_txt);
}

void	center_image_on_screen(t_game *game, mlx_image_t *img,
	int offset_x, int offset_y)
{
	int	center_y;
	int	center_x;
	int	pos_x;
	int	pos_y;

	center_x = (game->map->width * TILE_SIZE) / 2;
	center_y = (game->map->height * TILE_SIZE) / 2;
	pos_x = center_x - (img->width / 2) + offset_x;
	pos_y = center_y - (img->height / 2) + offset_y;
	mlx_image_to_window(game->mlx, img, pos_x, pos_y);
}
