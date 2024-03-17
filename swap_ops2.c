/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_ops2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koseki.yusuke <koseki.yusuke@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 00:02:18 by koseki.yusu       #+#    #+#             */
/*   Updated: 2024/03/10 13:40:12 by koseki.yusu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_rr(t_node **stack_a, t_node **stack_b)
{
	ft_swap_ra(stack_a);
	ft_swap_rb(stack_b);
	ft_printf("%s\n", "rr");
}

//下を上に持っていく
// rraのスワップ
void	ft_swap_rra(t_node **stack_a)
{
	(*stack_a)->prev->len = (*stack_a)->len;
	(*stack_a) = (*stack_a)->prev;
	ft_printf("%s\n", "rra");
}

// rraのスワップ
void	ft_swap_rrb(t_node **stack_b)
{
	(*stack_b)->prev->len = (*stack_b)->len;
	*stack_b = (*stack_b)->prev;
	ft_printf("%s\n", "rrb");
}

void	ft_swap_rrr(t_node **stack_a, t_node **stack_b)
{
	ft_swap_rra(stack_a);
	ft_swap_rrb(stack_b);
	ft_printf("%s\n", "rrr");
}