/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheringe <rheringe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 14:07:57 by rheringe          #+#    #+#             */
/*   Updated: 2025/01/27 14:32:35 by rheringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	int		i;
	char	*ptr;

	ptr = (char *)str;
	i = 0;
	while (n-- > 0)
	{
		ptr[i] = (char)c;
		i++;
	}
	return (ptr);
}

// int main ()
// {
// 	char text[100];
// 	char c;
// 	int n;

// 	fgets(text, 100, stdin);
// 	scanf(" %c" ,&c);
// 	scanf("%d" ,&n);
// 	ft_memset(text, c, n);
// 	printf("%s\n" ,text);
// 	return (0);
// }