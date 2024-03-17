/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koseki.yusuke <koseki.yusuke@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 23:59:34 by koseki.yusu       #+#    #+#             */
/*   Updated: 2024/03/09 16:17:56 by koseki.yusu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//行数制限超えてるから調整する(共通部分を関数で逃せばいけそう.
// //paの実装-bの一番上をaの一番上にpushする
void	ft_swap_pa(t_node **stack_a, t_node **stack_b)
{
	t_node	*tmp_pusher;

	if (*stack_b == NULL || stack_b == NULL)
		return ;
	tmp_pusher = *stack_b;
	if ((*stack_b)->len > 1)
	{
		(*stack_b)->next->len = (*stack_b)->len;
		*stack_b = (*stack_b)->next;
		(*stack_b)->prev = (*stack_b)->prev->prev;
		(*stack_b)->prev->next = *stack_b;
		(*stack_b)->len--;
	}
	else
		*stack_b = NULL;
	if (*stack_a == NULL)
	{
		*stack_a = tmp_pusher;
		(*stack_a)->next = *stack_a;
		(*stack_a)->prev = *stack_a;
		(*stack_a)->len = 0;
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
	t_node *tmp_pusher;

	if (*stack_a == NULL || stack_a == NULL)
		return ;
	tmp_pusher = *stack_a;
	if ((*stack_a)->len > 1)
	{
		(*stack_a)->next->len = (*stack_a)->len;
		*stack_a = (*stack_a)->next;
		(*stack_a)->prev = (*stack_a)->prev->prev;
		(*stack_a)->prev->next = *stack_a;
		(*stack_a)->len--;
	}
	else
		*stack_a = NULL;
	if (*stack_b == NULL)
	{
		*stack_b = tmp_pusher;
		(*stack_b)->next = *stack_b;
		(*stack_b)->prev = *stack_b;
		(*stack_b)->len = 0;
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