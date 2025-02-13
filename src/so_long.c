/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheringe <rheringe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 13:29:28 by rheringe          #+#    #+#             */
/*   Updated: 2025/02/12 20:26:13 by rheringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int main	(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
		message_error(EXIT_INVALID_ARGS);
	game = malloc(sizeof(t_game));
	init_map(game);
	validate_map(argv[1], game);
	init_so_long(game);
	//game->player.up = game->player.down = game->player.left = game->player.right = false;
    mlx_terminate(game->mlx);
}
