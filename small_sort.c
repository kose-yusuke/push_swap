/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koseki.yusuke <koseki.yusuke@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 01:29:55 by koseki.yusu       #+#    #+#             */
/*   Updated: 2024/03/10 13:44:40 by koseki.yusu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// sortしてたら返さなきゃいけないけど, stackbにもう何もないことも確認する？
int	small_sort(t_node **stack_a, t_node **stack_b)
{
	//すでにソートされてないかチェック
	if (is_sorted(stack_a))
		return (1);
	// 2個の時
	if ((*stack_a)->len == 2 && (*stack_a)->index > (*stack_a)->next->index)
	{
		ft_swap_sa(stack_a);
		return (1);
		// return (print_list(stack_a));
	}
	else if ((*stack_a)->len == 2
		&& (*stack_a)->index < (*stack_a)->next->index)
		// return (print_list(stack_a));
		return (1);
	// 3個の時
	if ((*stack_a)->len == 3)
	{
		if (three_sort(stack_a))
			// return(print_list(&stack_a));
			return (1);
	}
	// 5個以下の時
	if ((*stack_a)->len == 4)
	{
		four_sort(stack_a, stack_b);
		// return(print_list(&stack_a));
		return (1);
	}
	if ((*stack_a)->len == 5)
	{
		five_sort(stack_a, stack_b);
		// return(print_list(&stack_a));
		return (1);
	}
	return (1);
}

// aをsortするのかbをソートするのか分岐できるようにしないと後々まずそう or bの分複製するか
int	three_sort(t_node **a)
{
	if ((*a)->index < (*a)->next->index && (*a)->index < (*a)->next->next->index
		&& (*a)->next->index > (*a)->next->next->index)
	{
		ft_swap_sa(a);
		ft_swap_ra(a);
	}
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

int	get_min_index(t_node **stack_a)
{
	t_node	*tmp;
	int		i;
	int		min_index;

	tmp = *stack_a;
	i = (*stack_a)->len;
	min_index = tmp->index;
	while (i)
	{
		if (min_index > tmp->index)
			min_index = tmp->index;
		i--;
		tmp = tmp->next;
	}
	return (min_index);
}

int	min_index_position(t_node **stack_a)
{
	t_node	*tmp;
	int		i;
	int		j;
	int		min_index;

	i = (*stack_a)->len;
	j = 0;
	min_index = get_min_index(stack_a);
	tmp = *stack_a;
	while (i)
	{
		if (tmp->index == min_index)
			return (j);
		i--;
		j++;
		tmp = tmp->next;
	}
	return (0);
}

int	four_sort(t_node **stack_a, t_node **stack_b)
{
	// print_list(stack_a);
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
