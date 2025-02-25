/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_map_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheringe <rheringe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 19:07:18 by rheringe          #+#    #+#             */
/*   Updated: 2025/02/25 15:48:23 by rheringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	validate_map(char *file, t_game *game)
{
	char	*lines;
	char	*temp;
	char	*aux;
	int		fd;

	if (!(ft_strnstr(file, ".ber", ft_strlen(file))))
		message_error(EXIT_INVALID_EXTENTION, game);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		message_error(EXIT_INVALID_FILE, game);
	lines = ft_strdup("");
	while (1)
	{
		aux = get_next_line(fd);
		if (aux == NULL)
			break ;
		temp = ft_strjoin(lines, aux);
		free(aux);
		free(lines);
		lines = temp;
	}
	close(fd);
	game->map->matrix = ft_split(lines, '\n');
	free(lines);
	put_map(game);
}

void	put_map(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (i++, game->map->matrix[i] != NULL)
	{
		j = -1;
		while (j++, game->map->matrix[i][j] != '\0' &&
			game->map->matrix[i][j] != '\n')
		{
			if (!is_closed(game, i, j))
				message_error(EXIT_MAP_NOT_CLOSED, game);
			if (game->map->matrix[i][j] == 'C')
				game->map->coin++;
			if (game->map->matrix[i][j] == 'E')
				set_exit_position(game, i, j);
			if (game->map->matrix[i][j] == 'P')
				set_player_position(game, i, j);
			if (game->map->matrix[i][j] == 'K')
				set_enemy_position(game, i, j);
			if (!ft_strchr("01CEPK", game->map->matrix[i][j]))
				message_error(EXIT_INVALID_CHAR, game);
		}
	}
	verify_map(game);
}

void	verify_map(t_game *game)
{
	game->map->height = ft_ptrlen(game->map->matrix);
	game->map->width = ft_strlen(game->map->matrix[0]);
	if (!check_line_size(game))
		message_error(EXIT_LINE_SIZE, game);
	if (game->map->height == game->map->width)
		message_error(EXIT_MUST_BE_RECTANGULAR, game);
	if (game->map->height < 3 || game->map->width < 3)
		message_error(EXIT_TOO_SHORT, game);
	if ((game->map->height * game->map->width) < 15)
		message_error(EXIT_TOO_SHORT, game);
	if (game->map->exit != 1)
		message_error(EXIT_MISSING_E, game);
	if (game->map->player != 1)
		message_error(EXIT_MISSING_P, game);
	if (game->map->coin < 1)
		message_error(EXIT_MISSING_C, game);
	copy_map(game);
}

bool	check_line_size(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map->matrix[i] != NULL)
	{
		j = 0;
		while (game->map->matrix[i][j] != '\0')
			j++;
		if (j != game->map->width)
			return (false);
		i++;
	}
	return (true);
}

void	load_mine(t_game *game)
{
	game->image->exit_text = mlx_load_png("assets/mine_closed.png");
	game->image->exit_img = mlx_texture_to_image(game->mlx,
			game->image->exit_text);
	mlx_resize_image(game->image->exit_img, TILE_SIZE, TILE_SIZE);
	game->image->exit_opn_text = mlx_load_png("assets/mine_open.png");
	game->image->exit_opn_img = mlx_texture_to_image(game->mlx,
			game->image->exit_opn_text);
	mlx_resize_image(game->image->exit_opn_img, TILE_SIZE, TILE_SIZE);
}
