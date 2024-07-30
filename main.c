/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykoseki <ykoseki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 18:07:55 by ykoseki           #+#    #+#             */
/*   Updated: 2024/06/30 17:12:08 by ykoseki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// sortされてるかチェックする関数
bool	is_sorted(t_node **stack_a)
{
	int		i;
	t_node	*tmp;

	if (stack_a == NULL || *stack_a == NULL || (*stack_a)->len == 1)
		return (true);
	tmp = *stack_a;
	i = (*stack_a)->len - 1;
	while (i)
	{
		if (tmp->index > tmp->next->index)
			return (false);
		tmp = tmp->next;
		i--;
	}
	return (true);
}

// デバッグ用
int	print_list(t_node **stack_a)
{
	int	i;

	i = (*stack_a)->len;
	while (i > 0)
	{
		ft_printf("%d", (*stack_a)->value);
		i--;
		*stack_a = (*stack_a)->next;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;

	if (argc == 1)
		return (-1);
	if (!ft_error_handling(argc, argv))
		return (-1);
	stack_a = init_list(argv, argc);
	stack_b = NULL;
	ft_compress_value(&stack_a);
	if (is_sorted(&stack_a))
	{
		ft_free_stack(&stack_a);
		ft_free_stack(&stack_b);
		return (1);
	}
	if (argc > 2 && argc < 7)
		small_sort(&stack_a, &stack_b);
	else if (argc > 6)
		radix_sort(&stack_a, &stack_b, get_max_bit(&stack_a));
	ft_free_stack(&stack_a);
	ft_free_stack(&stack_b);
	return (1);
}
