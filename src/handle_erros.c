/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_erros.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheringe <rheringe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 13:42:02 by rheringe          #+#    #+#             */
/*   Updated: 2025/02/18 18:36:53 by rheringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	message_error(short error_code, t_game *game)
{
	if (error_code == EXIT_INVALID_FILE)
		ft_putstr_fd("Error\nInvalid File\n", STDERR_FILENO);
	if (error_code == EXIT_INVALID_EXTENTION)
		ft_putstr_fd("Error\nInvalid File Extention\n", STDERR_FILENO);
	if (error_code == EXIT_MAP_NOT_CLOSED)
		ft_putstr_fd("Error\nMap not closed\n", STDERR_FILENO);
	if (error_code == EXIT_INVALID_CHAR)
		ft_putstr_fd("Error\nInvalid Character\n", STDERR_FILENO);
	if (error_code == EXIT_MUST_BE_RECTANGULAR)
		ft_putstr_fd("Error\nMap must be rectangular\n", STDERR_FILENO);
	if (error_code == EXIT_LINE_SIZE)
		ft_putstr_fd("Error\nLines must have the same size\n", STDERR_FILENO);
	if (error_code == EXIT_TOO_SHORT)
		ft_putstr_fd("Error\nMap must be at least 15 tiles\n", STDERR_FILENO);
	if (error_code == EXIT_MISSING_E)
		ft_putstr_fd("Error\nMap must have one exit\n", STDERR_FILENO);
	if (error_code == EXIT_MISSING_P)
		ft_putstr_fd("Error\nMap must have one player\n", STDERR_FILENO);
	if (error_code == EXIT_MISSING_C)
		ft_putstr_fd("Error\nMap must have collectables\n", STDERR_FILENO);
	if (error_code == EXIT_NO_PATH)
		ft_putstr_fd("Error\nNo path to the exit\n", STDERR_FILENO);
	if (error_code < -3)
		free_and_close_error(game, error_code);
	free_file(game);
}

void	free_file(t_game *game)
{
	free(game);
	exit(1);
}

void	free_and_close_error(t_game *game, short error_code)
{
	ft_free(game->map.matrix, ft_ptrlen(game->map.matrix));
	if (error_code == EXIT_NO_PATH)
		ft_free(game->map.map_copy, ft_ptrlen(game->map.map_copy));
	free(game);
	exit(2);
}

void	ft_free(char **ptr_matrix, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		free(ptr_matrix[i]);
		i++;
	}
	free(ptr_matrix);
}
