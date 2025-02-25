/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_flood_fill_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheringe <rheringe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 19:06:20 by rheringe          #+#    #+#             */
/*   Updated: 2025/02/25 15:44:02 by rheringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	copy_map(t_game *game)
{
	int	i;
	int	j;
	int	line_length;

	game->map->map_copy = ft_calloc(1,
			(sizeof(char *) * (game->map->height + 1)));
	line_length = game->map->width + 1;
	i = 0;
	while (game->map->matrix[i])
	{
		game->map->map_copy[i] = malloc(sizeof(char) * line_length);
		j = 0;
		while (game->map->matrix[i][j])
		{
			game->map->map_copy[i][j] = game->map->matrix[i][j];
			j++;
		}
		game->map->map_copy[i][j] = '\0';
		i++;
	}
	game->map->map_copy[i] = NULL;
	flood_fill(game, game->player->x, game->player->y);
	verify_flood_fill(game);
}

void	flood_fill(t_game *game, int x, int y)
{
	if (x <= 0 || y <= 0 || x >= (game->map->height - 1)
		|| y >= (game->map->width - 1))
		return ;
	if (game->map->map_copy[x][y] == '1')
		return ;
	if (game->map->map_copy[x][y] == '0' || game->map->map_copy[x][y] == 'C'
		|| game->map->map_copy[x][y] == 'E' || game->map->map_copy[x][y] == 'P')
	{
		game->map->map_copy[x][y] = 'X';
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
