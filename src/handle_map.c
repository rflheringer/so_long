/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheringe <rheringe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:21:25 by rheringe          #+#    #+#             */
/*   Updated: 2025/02/04 15:11:51 by rheringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	verify_map(t_map *map)
{
	int i;
	int	j;

	i = -1;
	while (i++, map->matrix[i] != NULL)
	{
		j = -1;
		while (j++, map->matrix[i][j] != '\0' && map->matrix[i][j] != '\n')
		{
			if (map->matrix[i][j] == 'C')
				map->coin++;
			if (map->matrix[i][j] == 'E')
				map->exit++;
			if (map->matrix[i][j] == 'P')
				map->player++;
		}
	}
	if (map->exit != 1 || map->player != 1 || map->coin < 1)
		message_error(EXIT_INVALID_MAP);
}

void	validate_map(char *file, t_map *map)
{
	int		fd;
	int		i;

	if (!(ft_strnstr(file, ".ber", ft_strlen(file))))
		message_error(EXIT_INVALID_FILE);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		message_error(EXIT_INVALID_FILE);
	i = 0;
	map->matrix = NULL;
	while (1)
	{
		map->matrix = my_realloc(map->matrix, sizeof(char *) * (i + 1));
		map->matrix[i] = get_next_line(fd);
		if (map->matrix[i] == NULL)
			break ;
		i++;
	}
	close(fd);
	verify_map(map);
}
