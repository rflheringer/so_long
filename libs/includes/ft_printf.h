/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheringe <rheringe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 10:39:20 by rheringe          #+#    #+#             */
/*   Updated: 2025/01/31 15:57:27 by rheringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

#include "libft.h"

typedef struct flags {
	unsigned int	u;
	int				d;
}	t_flags;

unsigned int	ft_putchar(int c);
unsigned int	ft_print_percent_sign(void);
unsigned int	ft_putnbr_base16(unsigned long n, char format, t_flags *flags);
unsigned int	ft_cap_type(const char *format, va_list args, t_flags *flags);
unsigned int	ft_decimal(unsigned int arg, t_flags *flags);
unsigned int	ft_ptr(void *ptr, t_flags *flags);
unsigned int	ft_putstr_count(char *s);
unsigned int	ft_putstr_aux(char *s);
void			ft_putnbr(int n, int fd);
void			ft_init_flags(t_flags *flags);
void			ft_putstr(char *s);
char			*ft_utoa(unsigned int n);
char			*ft_strchr(const char *str, int c);
char			*ft_itoa(int n);
int				ft_printf(const char *format, ...);
int				ft_count_n(long n);

#endif