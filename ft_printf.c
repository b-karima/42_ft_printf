/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkarima <kkarima@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 18:21:00 by kkarima           #+#    #+#             */
/*   Updated: 2026/11/17 00:24:59 by kkarima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_convert_print(const char c, va_list args)
{
	char	*str;

	if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (c == 's')
	{
		str = va_arg(args, char *);
		if (str == NULL)
			return (ft_putstr("(null)"));
		else
			return (ft_putstr(str));
	}
	else if (c == 'p')
		return (ft_putnbr_pointer((unsigned long long)va_arg(args, void *)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (c == 'u')
		return (ft_putnbr_u(va_arg(args, unsigned int)));
	else if (c == 'x')
		return (ft_putnbr_hexa_low(va_arg(args, unsigned int)));
	else if (c == 'X')
		return (ft_putnbr_hexa_up(va_arg(args, unsigned int)));
	else if (c == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *types, ...)
{
	va_list	args;
	int		i;
	int		ret;

	i = 0;
	ret = 0;
	if (!types)
		return (0);
	va_start(args, types);
	while (types[i])
	{
		while (types[i] != '%' && types[i])
		{
			ret += ft_putchar(types[i]);
			i++;
		}
		if (types[i] == '%')
		{
			ret += (ft_convert_print(types[i + 1], args));
			i += 2;
		}
	}
	va_end(args);
	return (ret);
}
