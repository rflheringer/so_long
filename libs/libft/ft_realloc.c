/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheringe <rheringe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 16:43:22 by rheringe          #+#    #+#             */
/*   Updated: 2025/02/04 12:25:37 by rheringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*my_realloc(void *ptr, size_t new_size)
{
    void *new_ptr;

	if (ptr == NULL)
		return malloc(new_size);
    if (new_size == 0)
    {
        free(ptr);
        return (NULL);
    }
    new_ptr = malloc(new_size);
	if (new_ptr == NULL)
		return NULL;
	ft_memcpy(new_ptr, ptr, new_size);
	free(ptr);
    return (new_ptr);
}