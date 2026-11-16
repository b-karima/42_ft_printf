/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkarima <kkarima@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 21:06:04 by kkarima           #+#    #+#             */
/*   Updated: 2026/11/17 00:24:30 by kkarima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nb)
{
	int	res;

	res = 0;
	if (nb == -2147483648)
	{
		return (ft_putstr("-2147483648"));
	}
	if (nb < 0)
	{
		nb = nb * -1;
		res += ft_putchar('-');
	}
	if (nb >= 10)
	{
		res += ft_putnbr (nb / 10);
	}
	res += ft_putchar (nb % 10 + '0');
	return (res);
}

int	ft_putnbr_u(unsigned int nb)
{
	int	res;

	res = 0;
	if (nb >= 10)
	{
		res += ft_putnbr (nb / 10);
	}
	res += ft_putchar (nb % 10 + '0');
	return (res);
}

int	ft_putnbr_hexa_low(unsigned long long nb)
{
	int		res;
	char	*base16;

	res = 0;
	base16 = "0123456789abcdef";
	if (nb >= 16)
	{
		res += ft_putnbr_hexa_low(nb / 16);
	}
	res += ft_putchar(base16[nb % 16]);
	return (res);
}

int	ft_putnbr_hexa_up(unsigned long long nb)
{
	int		res;
	char	*base16;

	res = 0;
	base16 = "0123456789ABCDEF";
	if (nb >= 16)
	{
		res += ft_putnbr_hexa_up(nb / 16);
	}
	res += ft_putchar(base16[nb % 16]);
	return (res);
}

int	ft_putnbr_pointer(unsigned long long nb)
{
	int	res;

	res = 0;
	if (nb == 0)
		return (ft_putstr("(nil)"));
	else
	{
		res += ft_putstr("0x");
		res += ft_putnbr_hexa_low(nb);
	}
	return (res);
}
