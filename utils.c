/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykoseki <ykoseki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 00:04:02 by koseki.yusu       #+#    #+#             */
/*   Updated: 2024/06/30 16:44:30 by ykoseki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	max_digitsize(int argc, char **argv)
{
	int	d_tmp;
	int	i;
	int	tmp_nbr;

	d_tmp = 0;
	i = 1;
	tmp_nbr = 0;
	while (i < argc)
	{
		tmp_nbr = ft_atoi(argv[i]);
		if (digit_len(tmp_nbr) > d_tmp)
			d_tmp = tmp_nbr;
		i++;
	}
	return (d_tmp);
}

void	ft_free_stack(t_node **stack_a)
{
	t_node	*tmp;
	t_node	*tmp2;
	int		len;

	tmp = *stack_a;
	if (*stack_a)
		len = (*stack_a)->len;
	else
		len = 0;
	while (len)
	{
		tmp2 = tmp;
		if (len > 1)
			tmp = tmp->next;
		free(tmp2);
		len--;
	}
}

void	ft_free(char **str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}
