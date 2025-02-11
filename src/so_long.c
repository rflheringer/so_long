/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelheringer <rafaelheringer@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 13:29:28 by rheringe          #+#    #+#             */
/*   Updated: 2025/02/11 17:28:56 by rafaelherin      ###   ########.fr       */
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
	game->player.up = game->player.down = game->player.left = game->player.right = false;
    mlx_terminate(game->mlx);
}
