/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkarima <kkarima@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 18:22:09 by kkarima           #+#    #+#             */
/*   Updated: 2026/11/17 00:24:46 by kkarima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(const char *types, ...);
int		ft_convert_print(const char c, va_list args);
int		ft_putchar(const char c);
int		ft_putstr(const char *str);
int		ft_putnbr(int nb);
int		ft_putnbr_u(unsigned int nb);
int		ft_putnbr_hexa_low(unsigned long long nb);
int		ft_putnbr_hexa_up(unsigned long long nb);
int		ft_putnbr_pointer(unsigned long long nb);

#endif
