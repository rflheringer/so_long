/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheringe <rheringe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 12:43:46 by rheringe          #+#    #+#             */
/*   Updated: 2025/01/27 14:32:35 by rheringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join_s;
	int		len_s1;
	int		len_s2;
	int		i;
	int		j;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	join_s = (char *)malloc(((len_s1 + len_s2 + 1) * sizeof(char)));
	if (!join_s)
		return (NULL);
	i = -1;
	while (++i < len_s1)
		join_s[i] = s1[i];
	j = 0;
	while ((j) < len_s2)
	{
		join_s[i] = s2[j];
		i++;
		j++;
	}
	join_s[i] = '\0';
	return (join_s);
}

// int main ()
// {
// 	char const s1[100] = "any random thing ";
// 	char const s2[100] = "42sp"
// 	printf("%s" ,ft(s1, s2));
// 	return (0);
// }