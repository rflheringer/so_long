/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheringe <rheringe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:23:04 by rheringe          #+#    #+#             */
/*   Updated: 2025/01/31 15:50:21 by rheringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

//static int	ft_count_n(long n);

// static int	ft_count_n(long n)
// {
// 	int	count_index;

// 	count_index = 0;
// 	if (n == 0)
// 		return (1);
// 	while (n != 0)
// 	{
// 		n = n / 10;
// 		count_index ++;
// 	}
// 	return (count_index);
// }

char	*ft_itoa(int n)
{
	char	*new_s;
	int		count_index;
	int		sign;
	long	num;

	num = n;
	sign = 0;
	if (num < 0)
	{
		sign = 1;
		num = -num;
	}
	count_index = ft_count_n(num) + sign;
	new_s = (char *)malloc(((count_index + 1) * sizeof(char)));
	if (!new_s)
		return (NULL);
	new_s[count_index] = '\0';
	while (count_index > 0)
	{
		new_s[--count_index] = (num % 10) + '0';
		num = num / 10;
	}
	if (sign == 1)
		new_s[0] = '-';
	return (new_s);
}

// int main ()
// {
// 	int n = -1505;
// 	ft_itoa(n);
// 	return (0);
// }