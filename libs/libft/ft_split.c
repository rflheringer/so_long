/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheringe <rheringe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:25:21 by rheringe          #+#    #+#             */
/*   Updated: 2025/01/27 14:32:35 by rheringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_count_string(char const *s, char c);
static char	*ft_make_string(char const *str, int flag, int i);
static void	ft_free(char **str, int count);
static char	**ft_malloc_matrix(int len, int *i, int *j, int *start);

char	**ft_split(char const *s, char c)
{
	char	**matrix_string;
	int		i;
	int		j;
	int		start;

	matrix_string = ft_malloc_matrix((ft_count_string(s, c)), &i, &j, &start);
	if (!matrix_string)
		return (NULL);
	while (++i, s[i] != '\0')
	{
		if (s[i] != c && start == -1)
			start = i;
		else if (s[i] == c && start != -1)
		{
			matrix_string[j] = ft_make_string(s, start, i);
			if (!matrix_string[j])
				return (ft_free(matrix_string, j), NULL);
			j++;
			start = -1;
		}
	}
	if (start != -1)
		matrix_string[j++] = ft_make_string(s, start, i);
	matrix_string[j] = NULL;
	return (matrix_string);
}

static int	ft_count_string(char const *s, char c)
{
	int	count;
	int	flag;
	int	i;

	count = 0;
	flag = -1;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && flag < 0)
		{
			flag = 1;
			count++;
		}
		else if (s[i] == c)
			flag = -1;
		i++;
	}
	return (count);
}

static char	**ft_malloc_matrix(int len, int *i, int *j, int *start)
{
	char	**ptr;

	*i = -1;
	*j = 0;
	*start = -1;
	ptr = (char **)malloc((len + 1) * sizeof(char *));
	if (!ptr)
		return (NULL);
	return (ptr);
}

static char	*ft_make_string(char const *str, int flag, int i)
{
	char	*word;
	int		index;

	index = 0;
	word = malloc((i - flag + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (flag < i)
	{
		word[index] = str[flag];
		index++;
		flag++;
	}
	word[index] = '\0';
	return (word);
}

static void	ft_free(char **str, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(str[i]);
		i++;
	}
	free(str);
}
