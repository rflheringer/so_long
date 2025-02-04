/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheringe <rheringe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 13:56:51 by rheringe          #+#    #+#             */
/*   Updated: 2025/01/27 14:32:35 by rheringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_left_index(char const *s1, char const *set, int len);
static int	ft_r_index(char const *s1, char const *set, int len, int len_s1);

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*copy;
	int		len;
	int		i;
	int		j;
	int		len_s1;

	if (!(s1 || !set))
		return (NULL);
	len = ft_strlen(set);
	i = ft_left_index(s1, set, len);
	len_s1 = (ft_strlen(s1) - 1);
	len_s1 = ft_r_index(s1, set, len, len_s1);
	j = 0;
	if (i > len_s1)
		return (ft_strdup(""));
	copy = (char *)malloc(((len_s1 - i + 2) * sizeof(char)));
	if (!copy)
		return (NULL);
	while ((i + j) <= len_s1)
	{
		copy[j] = s1[i + j];
		j++;
	}
	copy[j] = '\0';
	return (copy);
}

static int	ft_left_index(char const *s1, char const *set, int len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i] && j < len)
	{
		if (s1[i] == set[j])
		{
			i++;
			j = 0;
		}
		else
			j++;
	}
	return (i);
}

static int	ft_r_index(char const *s1, char const *set, int len, int len_s1)
{
	int	j;

	j = 0;
	while (j < len)
	{
		if (s1[len_s1] == set[j])
		{
			len_s1--;
			j = 0;
		}
		else
			j++;
	}
	return (len_s1);
}
// int main ()
// {
// 	char const s1[100] = "lorem ipsum dolor sit amet";
// 	char const set[100] = "tel";
// 	printf ("%s\n" ,ft_strtrim(s1, set));
// 	return (0); 
// }