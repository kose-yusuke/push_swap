/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort_helper.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykoseki <ykoseki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 10:04:11 by ykoseki           #+#    #+#             */
/*   Updated: 2024/03/17 10:05:50 by ykoseki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa_and_ra(t_node **a)
{
	ft_swap_sa(a);
	ft_swap_ra(a);
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
