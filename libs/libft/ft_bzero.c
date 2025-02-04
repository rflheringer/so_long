/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheringe <rheringe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:03:53 by rheringe          #+#    #+#             */
/*   Updated: 2025/01/27 14:32:35 by rheringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*ptr;

	ptr = (char *)s;
	while (n-- > 0)
	{
		*ptr++ = 0;
	}
}

// int main ()
// {
// 	char text[100];
// 	int n;
// 	fgets(text, 11, stdin);
// 	scanf("%d" ,&n);
// 	ft_bzero(text, n);
// 	printf("%s\n" ,&text[n]);
// 	return (0);
// }