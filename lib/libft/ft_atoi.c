/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykoseki <ykoseki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 17:29:25 by ykoseki           #+#    #+#             */
/*   Updated: 2024/06/30 16:44:42 by ykoseki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

// #include <string.h>

static int	check_overflow(long long num, int onedigit, int type)
{
	if (type == 1 && ((num > LLONG_MAX / 10) || (num == LLONG_MAX / 10
				&& onedigit > 7)))
		return (-1);
	if (type == -1 && ((-1 * num < LLONG_MIN / 10) || (-1 * num == LLONG_MIN
				/ 10 && onedigit > 8)))
		return (0);
	return (1);
}

long	ft_atoi(const char *str)
{
	int			type;
	long long	num;
	int			overflow;

	type = 1;
	num = 0;
	while (*str != '\0' && (*str == ' ' || *str == '\f' || *str == '\n'
			|| *str == '\r' || *str == '\t' || *str == '\v'))
		str++;
	if (*str != '\0' && (*str == '+' || *str == '-'))
	{
		if (*str == '-')
			type *= -1;
		str++;
	}
	while (*str != '\0' && *str >= '0' && *str <= '9')
	{
		overflow = check_overflow(num, *str - '0', type);
		if (overflow == -1 || overflow == 0)
			return (overflow);
		num = num * 10 + (*str - '0');
		str++;
	}
	return (type * num);
}
