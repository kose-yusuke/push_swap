/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koseki.yusuke <koseki.yusuke@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 00:04:21 by koseki.yusu       #+#    #+#             */
/*   Updated: 2024/03/10 13:39:51 by koseki.yusu      ###   ########.fr       */
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

// マイナスの場合がよくわからない
//基数ソートの実装
void	radix_sort(t_node **stack_a, t_node **stack_b)
{
	int	bit_digit;
	int	max_bit_digit;
	int	i;
	int	len;

	bit_digit = 0;
	max_bit_digit = get_max_bit(stack_a);
	while (max_bit_digit > bit_digit)
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