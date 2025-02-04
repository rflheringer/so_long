/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheringe <rheringe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 17:13:06 by rheringe          #+#    #+#             */
/*   Updated: 2025/01/27 14:32:35 by rheringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	ptr1 = (unsigned char *)s1;
	ptr2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (i < n && ptr1[i] != '\0' && ptr2[i] != '\0')
	{
		if (ptr1[i] != ptr2[i])
			return (ptr1[i] - ptr2[i]);
		i++;
	}
	if (i < n && (ptr1[i] != '\0' || ptr2[i] != '\0'))
		return (ptr1[i] - ptr2[i]);
	return (0);
}

// int main ()
// {
// 	char text1[] = "any random thing";
// 	char text2[] = "ani random thing";
// 	int n;
// 	scanf ("%d" ,&n);
// 	printf("%d\n" ,ft_strncmp(text1, text2, n));
// 	return (0);
// }