/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykoseki <ykoseki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 01:29:55 by koseki.yusu       #+#    #+#             */
/*   Updated: 2024/03/17 10:05:45 by ykoseki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	small_sort(t_node **stack_a, t_node **stack_b)
{
	if (is_sorted(stack_a))
		return (1);
	if ((*stack_a)->len == 2 && (*stack_a)->index > (*stack_a)->next->index)
	{
		ft_swap_sa(stack_a);
		return (1);
	}
	else if ((*stack_a)->len == 2
		&& (*stack_a)->index < (*stack_a)->next->index)
		return (1);
	else if ((*stack_a)->len == 3)
	{
		if (three_sort(stack_a))
			return (1);
	}
	else if ((*stack_a)->len == 4)
		four_sort(stack_a, stack_b);
	else if ((*stack_a)->len == 5)
		five_sort(stack_a, stack_b);
	return (1);
}

int	three_sort(t_node **a)
{
	if ((*a)->index < (*a)->next->index && (*a)->index < (*a)->next->next->index
		&& (*a)->next->index > (*a)->next->next->index)
		ft_sa_and_ra(a);
	else if ((*a)->index > (*a)->next->index
		&& (*a)->index < (*a)->next->next->index
		&& (*a)->next->index < (*a)->next->next->index)
		ft_swap_sa(a);
	else if ((*a)->index < (*a)->next->index
		&& (*a)->index > (*a)->next->next->index
		&& (*a)->next->index > (*a)->next->next->index)
		ft_swap_rra(a);
	else if ((*a)->index > (*a)->next->index
		&& (*a)->index > (*a)->next->next->index
		&& (*a)->next->index < (*a)->next->next->index)
		ft_swap_ra(a);
	else if ((*a)->index > (*a)->next->index
		&& (*a)->index > (*a)->next->next->index
		&& (*a)->next->index > (*a)->next->next->index)
	{
		ft_swap_sa(a);
		ft_swap_rra(a);
	}
	return (1);
}

int	four_sort(t_node **stack_a, t_node **stack_b)
{
	if (min_index_position(stack_a) == 1)
		ft_swap_sa(stack_a);
	else if (min_index_position(stack_a) == 2)
	{
		ft_swap_ra(stack_a);
		ft_swap_ra(stack_a);
	}
	else if (min_index_position(stack_a) == 3)
		ft_swap_rra(stack_a);
	if (is_sorted(stack_a))
		return (1);
	ft_swap_pb(stack_a, stack_b);
	three_sort(stack_a);
	ft_swap_pa(stack_a, stack_b);
	return (1);
}

int	five_sort(t_node **stack_a, t_node **stack_b)
{
	if (min_index_position(stack_a) == 1)
		ft_swap_sa(stack_a);
	else if (min_index_position(stack_a) == 2)
	{
		ft_swap_ra(stack_a);
		ft_swap_ra(stack_a);
	}
	else if (min_index_position(stack_a) == 3)
	{
		ft_swap_rra(stack_a);
		ft_swap_rra(stack_a);
	}
	else if (min_index_position(stack_a) == 4)
		ft_swap_rra(stack_a);
	if (is_sorted(stack_a))
		return (1);
	ft_swap_pb(stack_a, stack_b);
	four_sort(stack_a, stack_b);
	ft_swap_pa(stack_a, stack_b);
	return (1);
}
