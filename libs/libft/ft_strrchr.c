/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheringe <rheringe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 11:36:25 by rheringe          #+#    #+#             */
/*   Updated: 2025/01/27 14:32:35 by rheringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	i;
	int	j;
	int	x;

	j = -1;
	i = 0;
	x = ft_strlen(str);
	if ((unsigned char)c == '\0')
		return ((char *)str + x);
	while (str[i] != '\0')
	{
		if (str[i] == (unsigned char)c)
			j = i;
		i++;
	}
	if (j > -1)
		return ((char *)str + j);
	return (NULL);
}

// int main ()
// {
// 	char src[100];
// 	char c;
// 	fgets(src, 100, stdin);
// 	scanf("%c" ,&c);
// 	printf("%s\n" ,ft_strrchr(src, c));
// 	return (0);
// }