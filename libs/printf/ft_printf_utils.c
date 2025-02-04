/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheringe <rheringe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 10:54:59 by rheringe          #+#    #+#             */
/*   Updated: 2025/01/31 15:50:38 by rheringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

unsigned int	ft_cap_type(const char *format, va_list args, t_flags *flags)
{
	if (*format == 'd' || *format == 'i')
	{	
		flags->d = 1;
		return (ft_decimal(va_arg(args, int), flags));
	}
	if (*format == 'c')
		(ft_putchar(va_arg(args, int)));
	if (*format == 's')
		return (ft_putstr_count(va_arg(args, char *)));
	if (*format == 'x' || *format == 'X')
		return (ft_putnbr_base16(va_arg(args, unsigned int), *format, flags));
	if (*format == 'u')
	{	
		flags->u = 1;
		return (ft_decimal(va_arg(args, unsigned int), flags));
	}
	if (*format == 'p')
		return (ft_ptr(va_arg(args, void *), flags));
	if (*format == '%')
		ft_print_percent_sign();
	return (1);
}

unsigned int	ft_decimal(unsigned int arg, t_flags *flags)
{
	char				*convert_to_alpha;
	unsigned int		len;

	len = 0;
	if (flags->u)
		convert_to_alpha = ft_utoa(arg);
	else
		convert_to_alpha = ft_itoa(arg);
	ft_putstr_count(convert_to_alpha);
	len += ft_strlen(convert_to_alpha);
	free(convert_to_alpha);
	return (len);
}

char	*ft_utoa(unsigned int n)
{
	unsigned int		temp_n;
	char				*str;
	int					len;

	temp_n = n;
	len = 0;
	if (n == 0)
		len++;
	while (temp_n > 0)
	{
		temp_n /= 10;
		len++;
	}
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len--)
	{
		str[len] = n % 10 + '0';
		n /= 10;
	}
	return (str);
}

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

int	ft_count_n(long n)
{
	int	count_index;

	count_index = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		count_index ++;
	}
	return (count_index);
}
