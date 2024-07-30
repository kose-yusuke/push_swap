/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykoseki <ykoseki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 23:59:34 by koseki.yusu       #+#    #+#             */
/*   Updated: 2024/03/17 09:56:46 by ykoseki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//行数制限超えてるから調整する(共通部分を関数で逃せばいけそう.
// //paの実装-bの一番上をaの一番上にpushする

void	ft_push_helper(t_node **stack)
{
	(*stack)->next->len = (*stack)->len;
	*stack = (*stack)->next;
	(*stack)->prev = (*stack)->prev->prev;
	(*stack)->prev->next = *stack;
	(*stack)->len--;
}

void	ft_push_helper2(t_node **stack)
{
	(*stack)->next = *stack;
	(*stack)->prev = *stack;
	(*stack)->len = 0;
}

void	ft_swap_pa(t_node **stack_a, t_node **stack_b)
{
	t_node	*tmp_pusher;

	if (*stack_b == NULL || stack_b == NULL)
		return ;
	tmp_pusher = *stack_b;
	if ((*stack_b)->len > 1)
		ft_push_helper(stack_b);
	else
		*stack_b = NULL;
	if (*stack_a == NULL)
	{
		*stack_a = tmp_pusher;
		ft_push_helper2(stack_a);
	}
	else
	{
		tmp_pusher->len = (*stack_a)->len;
		tmp_pusher->next = *stack_a;
		tmp_pusher->prev = (*stack_a)->prev;
		tmp_pusher->next->prev = tmp_pusher;
		tmp_pusher->prev->next = tmp_pusher;
		*stack_a = tmp_pusher;
	}
	(*stack_a)->len++;
	ft_printf("%s\n", "pa");
}

// //pbの実装-aの一番上をbの一番上にpushする
void	ft_swap_pb(t_node **stack_a, t_node **stack_b)
{
	t_node	*tmp_pusher;

	if (*stack_a == NULL || stack_a == NULL)
		return ;
	tmp_pusher = *stack_a;
	if ((*stack_a)->len > 1)
		ft_push_helper(stack_a);
	else
		*stack_a = NULL;
	if (*stack_b == NULL)
	{
		*stack_b = tmp_pusher;
		ft_push_helper2(stack_b);
	}
	else
	{
		tmp_pusher->len = (*stack_b)->len;
		tmp_pusher->next = *stack_b;
		tmp_pusher->prev = (*stack_b)->prev;
		tmp_pusher->next->prev = tmp_pusher;
		tmp_pusher->prev->next = tmp_pusher;
		*stack_b = tmp_pusher;
	}
	(*stack_b)->len++;
	ft_printf("%s\n", "pb");
}
