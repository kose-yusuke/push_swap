/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykoseki <ykoseki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 14:13:58 by koseki.yusu       #+#    #+#             */
/*   Updated: 2024/03/17 09:37:26 by ykoseki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min_value(t_node **stack_a)
{
	t_node	*tmp;
	int		i;
	int		min_value;

	tmp = *stack_a;
	i = (*stack_a)->len;
	min_value = tmp->value;
	while (i)
	{
		if (min_value > tmp->value)
			min_value = tmp->value;
		i--;
		tmp = tmp->next;
	}
	return (min_value);
}

int	get_next_min_value(t_node **stack_a, int old_min)
{
	t_node	*tmp;
	int		i;
	int		min_value;
	int		count;

	tmp = *stack_a;
	i = (*stack_a)->len;
	count = 0;
	while (old_min >= tmp->value && count != i)
	{
		tmp = tmp->next;
		count++;
	}
	min_value = tmp->value;
	while (i)
	{
		if (min_value > tmp->value && old_min < tmp->value)
			min_value = tmp->value;
		i--;
		tmp = tmp->next;
	}
	return (min_value);
}

int	min_value_position(t_node **stack_a, int min)
{
	t_node	*tmp;
	int		i;
	int		j;
	int		min_value;

	i = (*stack_a)->len;
	j = 0;
	min_value = min;
	tmp = *stack_a;
	while (i)
	{
		if (tmp->value == min_value)
			return (j);
		i--;
		j++;
		tmp = tmp->next;
	}
	return (0);
}

int	ft_compress_value(t_node **stack_a)
{
	int	index;
	int	len;
	int	min;
	int	position;

	index = 0;
	len = (*stack_a)->len;
	min = get_min_value(stack_a);
	while (len)
	{
		position = min_value_position(stack_a, min);
		while (position)
		{
			(*stack_a)->next->len = (*stack_a)->len;
			*stack_a = (*stack_a)->next;
			position--;
		}
		(*stack_a)->index = index;
		index++;
		len--;
		min = get_next_min_value(stack_a, min);
	}
	while ((*stack_a)->first_flag == 0)
		*stack_a = (*stack_a)->next;
	return (1);
}
