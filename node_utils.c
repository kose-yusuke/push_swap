/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykoseki <ykoseki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 23:58:02 by koseki.yusu       #+#    #+#             */
/*   Updated: 2024/06/30 16:43:30 by ykoseki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_lstlast_init(t_node *node)
{
	if (node == NULL)
		return (node);
	while (node->next != NULL)
		node = node->next;
	return (node);
}

t_node	*ft_nodenew(int value)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->first_flag = 0;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

// nodeの数が決まっているstack_aの初期化でしか使えない→初期化以後はprevで最後のnodeを指定する方針にする.
void	ft_nodeadd_last_init(t_node **node, int value)
{
	t_node	*new_node;
	t_node	*list_last_node;

	new_node = ft_nodenew(value);
	if (*node != NULL && node != NULL)
	{
		list_last_node = ft_lstlast_init(*node);
		list_last_node->next = new_node;
		new_node->prev = list_last_node;
	}
}

void	ft_nodedelone(t_node *node)
{
	if (node)
		free(node);
}

t_node	*init_list(char **argv, int argc)
{
	t_node	*node;
	t_node	*list_first_node;
	t_node	*list_last_node;
	int		i;

	node = ft_nodenew(ft_atoi(argv[1]));
	i = 2;
	while (argv[i] != NULL)
	{
		ft_nodeadd_last_init(&node, ft_atoi(argv[i]));
		i++;
	}
	list_first_node = node;
	list_last_node = ft_lstlast_init(node);
	list_last_node->next = list_first_node;
	list_first_node->prev = list_last_node;
	node->len = argc - 1;
	node->first_flag = 1;
	return (node);
}
