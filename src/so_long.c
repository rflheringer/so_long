/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheringe <rheringe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 19:07:45 by rheringe          #+#    #+#             */
/*   Updated: 2025/02/25 15:23:37 by rheringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
		return (ft_putstr_fd("Error\nInvalid Args\n", STDERR_FILENO), 0);
	game = ft_calloc(1, sizeof(t_game));
	game->player = ft_calloc(1, sizeof(t_player));
	game->map = ft_calloc(1, sizeof(t_map));
	init_map(game);
	validate_map(argv[1], game);
	init_so_long(game);
	return (0);
}
