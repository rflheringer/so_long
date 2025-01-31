/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheringe <rheringe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:21:25 by rheringe          #+#    #+#             */
/*   Updated: 2025/01/31 18:15:09 by rheringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	verify_map(t_map *map)
{
	int i;
	int	j;

	i = 0;
	while (map->matrix[i] != NULL)
	{
		j = 0;
		while (map->matrix[i][j] != '\0' && map->matrix[i][j] != '\n')
		{
			if (map->matrix[i][j] == 67)
				map->coin++;
			if (map->matrix[i][j] == 69)
				map->exit++;
			if (map->matrix[i][j] == 80)
				map->player++;
			j++;
		}
		i++;
	}
	ft_printf("%d %d %d", map->coin, map->player, map->exit);
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
	map = malloc(sizeof(t_map));
	map->matrix = NULL;
	while (1)
	{
		map->matrix = my_realloc(map->matrix, sizeof(char *) * (i + 1));
		map->matrix[i] = get_next_line(fd);
		if (map->matrix[i] == NULL)
			break ;
		i++;
	}
	// for (int g = 0; g < 5; g++)
	// {
	// 	ft_printf("%s", map->matrix[g]);
	// }
	verify_map(map);
}
