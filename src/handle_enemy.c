/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_enemy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheringe <rheringe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 19:58:30 by rheringe          #+#    #+#             */
/*   Updated: 2025/02/12 23:54:17 by rheringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	load_enemy_images(t_game *game)
{
	game->enemy.e_fr_text[0] = mlx_load_png("assets/warrior_1.png");
	game->enemy.e_fr_img[0] = mlx_texture_to_image(game->mlx,
			game->enemy.e_fr_text[0]);
	game->enemy.e_fr_text[1] = mlx_load_png("assets/warrior_2.png");
	game->enemy.e_fr_img[1] = mlx_texture_to_image(game->mlx,
			game->enemy.e_fr_text[1]);
	game->enemy.e_fr_text[2] = mlx_load_png("assets/warrior_3.png");
	game->enemy.e_fr_img[2] = mlx_texture_to_image(game->mlx,
			game->enemy.e_fr_text[2]);
	game->enemy.e_fr_text[3] = mlx_load_png("assets/warrior_4.png");
	game->enemy.e_fr_img[3] = mlx_texture_to_image(game->mlx,
			game->enemy.e_fr_text[3]);
	game->enemy.e_fr_text[4] = mlx_load_png("assets/warrior_5.png");
	game->enemy.e_fr_img[4] = mlx_texture_to_image(game->mlx,
			game->enemy.e_fr_text[4]);
	game->enemy.e_fr_text[5] = mlx_load_png("assets/warrior_6.png");
	game->enemy.e_fr_img[5] = mlx_texture_to_image(game->mlx,
			game->enemy.e_fr_text[5]);
	game->enemy.e_curr_fr = 0;
	game->enemy.e_curr_img = game->enemy.e_fr_img[game->enemy.e_curr_fr];
	game->enemy.e_fr_count = 6;
	game->enemy.e_fr_delay = 0.3;
}

void	set_enemy_position(t_game *game, int i, int j)
{
	game->enemy.e_y = i;
	game->enemy.e_x = j;
}

void	ft_handle_dead(t_game *game, int move_x, int move_y)
{
	game->map.moves++;
	game->player.x += move_x;
	game->player.y += move_y;
	ft_putstr_fd("Moves: ", 1);
	ft_printf("%d\n", game->map.moves);
	ft_putstr_fd("You Died\n", 1);
	mlx_close_window(game->mlx);
}

void update_enemy(t_game *game, double delta_time) {
    game->enemy.move_time += delta_time;
	game->enemy.move_delay = 0.5;
    if (game->enemy.move_time >= game->enemy.move_delay) {
        int dx = game->player.x - game->enemy.e_x;
        int dy = game->player.y - game->enemy.e_y;
		mlx_delete_image(game->mlx, game->enemy.e_curr_img);
		game->enemy.e_curr_img = mlx_texture_to_image(game->mlx, game->enemy.e_fr_text[game->player.current_frame]);
        // Prioriza mover na direção com maior diferença
        if (abs(dx) > abs(dy)) {
            if (dx > 0)
                game->enemy.e_x += 1; // Move para a direita
            else
                game->enemy.e_x -= 1; // Move para a esquerda
        } else {
            if (dy > 0)
                game->enemy.e_y += 1; // Move para baixo
            else
                game->enemy.e_y -= 1; // Move para cima
        }

        game->enemy.move_time = 0; // Reseta o tempo acumulado
    }
}
