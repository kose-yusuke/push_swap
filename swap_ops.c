/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koseki.yusuke <koseki.yusuke@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 00:00:08 by koseki.yusu       #+#    #+#             */
/*   Updated: 2024/03/10 13:40:08 by koseki.yusu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// saのスワップ
void	ft_swap_sa(t_node **stack_a)
{
	int	tmp_value;
	int	tmp_index;

	// t_node *list_first_node;
	// t_node *list_last_node;
	tmp_value = (*stack_a)->next->value;
	tmp_index = (*stack_a)->next->index;
	(*stack_a)->next->value = (*stack_a)->value;
	(*stack_a)->next->index = (*stack_a)->index;
	(*stack_a)->value = tmp_value;
	(*stack_a)->index = tmp_index;
	ft_printf("%s\n", "sa");
}

// stack_aと違って初期化できてないから変える必要はあるかも
void	ft_swap_sb(t_node **stack_b)
{
	int	tmp_value;
	int	tmp_index;

	// t_node *list_first_node;
	// t_node *list_last_node;
	tmp_value = (*stack_b)->next->value;
	tmp_index = (*stack_b)->next->index;
	(*stack_b)->next->value = (*stack_b)->value;
	(*stack_b)->next->index = (*stack_b)->index;
	(*stack_b)->value = tmp_value;
	(*stack_b)->index = tmp_index;
	ft_printf("%s\n", "sb");
}

void	ft_swap_ss(t_node **stack_a, t_node **stack_b)
{
	ft_swap_sa(stack_a);
	ft_swap_sb(stack_b);
	ft_printf("%s\n", "ss");
}

// raのスワップ
//上を下に
void	ft_swap_ra(t_node **stack_a)
{
	(*stack_a)->next->len = (*stack_a)->len;
	*stack_a = (*stack_a)->next;
	ft_printf("%s\n", "ra");
}

void	ft_swap_rb(t_node **stack_b)
{
	(*stack_b)->next->len = (*stack_b)->len;
	*stack_b = (*stack_b)->next;
	ft_printf("%s\n", "rb");
}