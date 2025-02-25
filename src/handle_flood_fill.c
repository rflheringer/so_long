/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_flood_fill.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheringe <rheringe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 19:06:20 by rheringe          #+#    #+#             */
/*   Updated: 2025/02/21 19:06:22 by rheringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	copy_map(t_game *game)
{
	int	i;
	int	j;
	int	line_length;

	game->map->map_copy = ft_calloc(1,
			(sizeof(char *) * (game->map->height + 1)));
	line_length = game->map->width + 1;
	i = -1;
	while (i++, game->map->matrix[i])
	{
		game->map->map_copy[i] = ft_calloc(1, (sizeof(char) * line_length));
		j = -1;
		while (j++, game->map->matrix[i][j])
			game->map->map_copy[i][j] = game->map->matrix[i][j];
		game->map->map_copy[i][j] = '\0';
	}
	game->map->map_copy[i] = NULL;
	flood_fill(game, game->player->x, game->player->y);
	verify_flood_fill(game);
}

void	flood_fill(t_game *game, int x, int y)
{
	if (x <= 0 || y <= 0 || x >= (game->map->width - 1)
		|| y >= (game->map->height - 1))
		return ;
	if (game->map->map_copy[y][x] == '1' || game->map->map_copy[y][x] == 'X')
		return ;
	if (game->map->map_copy[y][x] == '0' || game->map->map_copy[y][x] == 'C'
		|| game->map->map_copy[y][x] == 'E' || game->map->map_copy[y][x] == 'P'
			|| game->map->map_copy[y][x] == 'I')
	{
		game->map->map_copy[y][x] = 'X';
		flood_fill(game, x + 1, y);
		flood_fill(game, x - 1, y);
		flood_fill(game, x, y + 1);
		flood_fill(game, x, y - 1);
	}
}

void	verify_flood_fill(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (i++, game->map->map_copy[i])
	{
		j = -1;
		while (j++, game->map->map_copy[i][j])
		{
			if (game->map->map_copy[i][j] == 'E')
				message_error(EXIT_NO_PATH, game);
			if (game->map->map_copy[i][j] == 'C')
				message_error(EXIT_NO_PATH, game);
		}
	}
}
