/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheringe <rheringe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 13:29:28 by rheringe          #+#    #+#             */
/*   Updated: 2025/02/18 18:13:17 by rheringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int main	(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
		return (ft_putstr_fd("Error\nInvalid Args\n", STDERR_FILENO), 0);
	game = ft_calloc(1, sizeof(t_game));
	game->file = argv[1];
	init_map(game);
	validate_map(argv[1], game);
	init_so_long(game);
// 	if (game->mlx)
// 		mlx_terminate(game->mlx);
}
