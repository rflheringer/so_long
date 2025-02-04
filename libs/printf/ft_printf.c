/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheringe <rheringe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 10:58:46 by rheringe          #+#    #+#             */
/*   Updated: 2025/02/04 11:37:47 by rheringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_printf(const char *format, ...)
{
	unsigned int	count_chars;
	va_list			args;
	t_flags			flags;

	va_start(args, format);
	count_chars = 0;
	if (!format)
	{
		ft_putstr("(nil)");
		return (5);
	}
	while (*format)
	{
		if (*format == '%')
		{
			ft_init_flags(&flags);
			format++;
			count_chars += ft_cap_type(format, args, &flags);
		}
		else
			count_chars += ft_putchar(*format);
		format++;
	}
	va_end(args);
	return (count_chars);
}

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		write (1, &s[i++], 1);
}

unsigned int	ft_putchar(int c)
{
	return ((write(1, &c, 1)));
}

void	ft_init_flags(t_flags *flags)
{
	flags->u = 0;
	flags->d = 0;
}
