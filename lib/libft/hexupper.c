/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexupper.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykoseki <ykoseki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 04:50:04 by ykoseki           #+#    #+#             */
/*   Updated: 2023/07/13 21:44:09 by ykoseki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hexdigit(unsigned int n)
{
	unsigned int	digit;

	digit = 1;
	while (n >= 16)
	{
		n /= 16;
		digit++;
	}
	return (digit);
}

int	ft_hexupper(unsigned int n)
{
	unsigned int	sho;
	unsigned int	mod;
	char			*sixteen;

	sixteen = "0123456789ABCDEF";
	sho = n / 16;
	mod = n % 16;
	if (n < 16)
	{
		ft_putchar_fd(sixteen[mod], 1);
	}
	else
	{
		ft_hexupper(sho);
		ft_putchar_fd(sixteen[mod], 1);
	}
	return (ft_hexdigit(n));
}
