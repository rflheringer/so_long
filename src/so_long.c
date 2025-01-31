/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheringe <rheringe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 13:29:28 by rheringe          #+#    #+#             */
/*   Updated: 2025/01/31 17:57:19 by rheringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int main	(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
		message_error(EXIT_INVALID_ARGS);
	game = malloc(sizeof(t_game));
	//init_map(map);
	validate_map(argv[1], game->map);
}
