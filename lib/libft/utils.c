/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koseki.yusuke <koseki.yusuke@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 03:45:43 by ykoseki           #+#    #+#             */
/*   Updated: 2023/11/24 03:33:50 by koseki.yusu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	len;

	if (s == NULL)
		return ;
	len = ft_strlen(s);
	while (len > 0)
	{
		ft_putchar_fd(*s, fd);
		s++;
		len--;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	int	div;
	int	mod;

	div = n / 10;
	mod = n % 10;
	if (n == -2147483648)
	{
		ft_putchar_fd('-', fd);
		ft_putchar_fd('2', fd);
		ft_putnbr_fd(147483648, fd);
	}
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n *= -1;
		ft_putnbr_fd(n, fd);
	}
	else if (n < 10)
		ft_putchar_fd(n + '0', fd);
	else
	{
		ft_putnbr_fd(div, fd);
		ft_putchar_fd(mod + '0', fd);
	}
}

int	digit_len(int n)
{
	int	digit;

	digit = 1;
	if (n == 0)
		return (digit);
	else if (n == -2147483648)
		return (11);
	else if (n < 0)
	{
		digit += 1;
		n *= -1;
	}
	while (n > 9)
	{
		n /= 10;
		digit++;
	}
	return (digit);
}
