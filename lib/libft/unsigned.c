/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykoseki <ykoseki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 01:10:39 by ykoseki           #+#    #+#             */
/*   Updated: 2023/07/13 21:43:29 by ykoseki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_unsigned_putnbr_fd(unsigned int n, int fd)
{
	unsigned int	div;
	unsigned int	mod;

	div = n / 10;
	mod = n % 10;
	if (n < 10)
		ft_putchar_fd(n + '0', fd);
	else
	{
		ft_putnbr_fd(div, fd);
		ft_putchar_fd(mod + '0', fd);
	}
}

static int	ft_digit(unsigned int n)
{
	unsigned int	digit;

	digit = 1;
	while (n >= 10)
	{
		n /= 10;
		digit++;
	}
	return (digit);
}

int	ft_unsigned(unsigned int n)
{
	ft_unsigned_putnbr_fd(n, 1);
	return (ft_digit(n));
}
