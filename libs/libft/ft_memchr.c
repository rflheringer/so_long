/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheringe <rheringe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 18:44:27 by rheringe          #+#    #+#             */
/*   Updated: 2025/01/27 14:32:35 by rheringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s)[i] == (unsigned char )c)
			return ((void *)((unsigned char *)&s[i]));
		i++;
	}
	return (0);
}

// int main ()
// {
// 	char text[100] = "any random thing here";
// 	char c;
// 	size_t i;

// 	scanf ("%c" ,&c);
// 	scanf ("%zd" ,&i);
// 	printf ("%s" ,(unsigned char *)ft_memchr(text, c, i));
// 	return (0);
// }