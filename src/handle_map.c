/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheringe <rheringe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:21:25 by rheringe          #+#    #+#             */
/*   Updated: 2025/02/12 23:21:42 by rheringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	verify_map(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (i++, game->map.matrix[i] != NULL)
	{
		j = -1;
		while (j++, game->map.matrix[i][j] != '\0' &&
			game->map.matrix[i][j] != '\n')
		{
			if (game->map.matrix[i][j] == 'C')
				game->map.coin++;
			if (game->map.matrix[i][j] == 'E')
				set_exit_position(game, i, j);
			if (game->map.matrix[i][j] == 'P')
				set_player_position(game, i, j);
			//BONUS//
			if (game->map.matrix[i][j] == 'K')
				set_enemy_position(game, i, j);
			//BONUS//
		}
	}
	if (game->map.exit != 1 || game->map.player != 1 || game->map.coin < 1)
		message_error(EXIT_INVALID_MAP);
	game->map.height = ft_ptrlen(game->map.matrix);
	game->map.width = ft_strlen(game->map.matrix[0]) - 1;
}

void	validate_map(char *file, t_game *game)
{
	int		fd;
	int		i;

	if (!(ft_strnstr(file, ".ber", ft_strlen(file))))
		message_error(EXIT_INVALID_FILE);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		message_error(EXIT_INVALID_FILE);
	i = 0;
	game->map.matrix = NULL;
	while (1)
	{
		game->map.matrix = my_realloc(game->map.matrix,
				sizeof(char *) * (i + 1));
		game->map.matrix[i] = get_next_line(fd);
		if (game->map.matrix[i] == NULL)
			break ;
		i++;
	}
	close(fd);
	verify_map(game);
}

void	load_mine(t_game *game)
{
	game->image.exit_text = mlx_load_png("assets/mine_closed.png");
	game->image.exit_img = mlx_texture_to_image(game->mlx,
			game->image.exit_text);
	mlx_resize_image(game->image.exit_img, TILE_SIZE, TILE_SIZE);
	game->image.exit_opn_text = mlx_load_png("assets/mine_open.png");
	game->image.exit_opn_img = mlx_texture_to_image(game->mlx,
			game->image.exit_opn_text);
	mlx_resize_image(game->image.exit_opn_img, TILE_SIZE, TILE_SIZE);
}

void	set_exit_position(t_game *game, int i, int j)
{
	game->map.exit++;
	game->map.x_exit = i;
	game->map.y_exit = j;
}
