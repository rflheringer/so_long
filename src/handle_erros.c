/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_erros.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheringe <rheringe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 13:42:02 by rheringe          #+#    #+#             */
/*   Updated: 2025/02/04 12:31:55 by rheringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	message_error(short error_code)
{
	if (error_code == EXIT_FAILURE)
		ft_putstr_fd("Error\n", STDERR_FILENO);
	if (error_code == EXIT_INVALID_ARGS)
		ft_putstr_fd("Error\nInvalid Args\n", STDERR_FILENO);
	if (error_code == EXIT_INVALID_FILE)
		ft_putstr_fd("Error\nInvalid File\n", STDERR_FILENO);
	if (error_code == EXIT_INVALID_MAP)
		ft_putstr_fd("Error\nInvalid Map\n", STDERR_FILENO);
	exit(error_code);
}


