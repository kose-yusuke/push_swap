/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykoseki <ykoseki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 00:04:21 by koseki.yusu       #+#    #+#             */
/*   Updated: 2024/03/17 10:10:33 by ykoseki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// 引数のうち最大の数取得
int	get_max(t_node **stack_a)
{
	t_node	*tmp;
	int		i;
	int		max;

	i = 0;
	max = (*stack_a)->index;
	tmp = *stack_a;
	while ((*stack_a)->len > i)
	{
		if (tmp->index > max)
			max = tmp->index;
		tmp = tmp->next;
		i++;
	}
	return (max);
}

// 2進数の最大桁取得
int	get_max_bit(t_node **stack_a)
{
	int	max;
	int	bit_digit;

	max = get_max(stack_a);
	bit_digit = 0;
	if (max == 0)
		return (1);
	while (max > 0)
	{
		bit_digit++;
		max >>= 1;
	}
	return (bit_digit);
}

void	radix_sort(t_node **stack_a, t_node **stack_b, int max_dgt)
{
	int	bit_digit;
	int	i;
	int	len;

	bit_digit = 0;
	while (max_dgt > bit_digit)
	{
		i = 0;
		len = (*stack_a)->len;
		while (len > i)
		{
			if (((*stack_a)->index >> bit_digit & 1) == 1)
				ft_swap_ra(stack_a);
			else
				ft_swap_pb(stack_a, stack_b);
			i++;
		}
		len = (*stack_b)->len;
		while (len > 0)
		{
			ft_swap_pa(stack_a, stack_b);
			len--;
		}
		bit_digit++;
	}
}

//バケツが2つある. 0のものをStackA, 1のものをStackBに分ける. を繰り返す