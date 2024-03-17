/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykoseki <ykoseki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 01:10:34 by ykoseki           #+#    #+#             */
/*   Updated: 2023/07/13 21:45:26 by ykoseki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hexdigit_ptr(unsigned long long n)
{
	unsigned long long	digit;

	digit = 3;
	while (n >= 16)
	{
		n /= 16;
		digit++;
	}
	return (digit);
}

int	ft_pointer(unsigned long long n)
{
	unsigned long long	sho;
	unsigned long long	mod;
	char				*sixteen;

	sixteen = "0123456789abcdef";
	sho = n / 16;
	mod = n % 16;
	if (n < 16)
	{
		ft_putchar_fd('0', 1);
		ft_putchar_fd('x', 1);
		ft_putchar_fd(sixteen[mod], 1);
	}
	else
	{
		ft_pointer(sho);
		ft_putchar_fd(sixteen[mod], 1);
	}
	return (ft_hexdigit_ptr(n));
}
