/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheringe <rheringe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:21:25 by rheringe          #+#    #+#             */
/*   Updated: 2025/02/10 15:25:28 by rheringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	verify_map(t_game *game)
{
	int i;
	int	j;

	i = -1;
	while (i++, game->map.matrix[i] != NULL)
	{
		j = -1;
		while (j++, game->map.matrix[i][j] != '\0' && game->map.matrix[i][j] != '\n')
		{
			if (game->map.matrix[i][j] == 'C')
				game->map.coin++;
			if (game->map.matrix[i][j] == 'E')
				game->map.exit++;
			if (game->map.matrix[i][j] == 'P')
				game->map.player++;
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
		game->map.matrix = my_realloc(game->map.matrix, sizeof(char *) * (i + 1));
		game->map.matrix[i] = get_next_line(fd);
		if (game->map.matrix[i] == NULL)
			break ;
		i++;
	}
	close(fd);
	verify_map(game);
}
