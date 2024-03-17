/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koseki.yusuke <koseki.yusuke@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 23:58:02 by koseki.yusu       #+#    #+#             */
/*   Updated: 2024/03/10 14:41:48 by koseki.yusu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_lstlast_init(t_node *node)
{
	if (node == NULL)
		return (node);
	//今はargcより少ない場合が全部node->next != NULLで止めてるから, 初期化用ならnode->next != NULLだけで良さそう
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
	t_node *node;
	t_node *list_first_node;
	t_node *list_last_node;
	int i;
	// ft_lstnewで新しいnodeを生成する
	node = ft_nodenew(atoi(argv[1]));
	// listを作る
	i = 2;
	while (argv[i] != NULL)
	{
		ft_nodeadd_last_init(&node, atoi(argv[i]));
		i++;
	}
	// //最後のノードのnextがNULLになっている→m最初のノードにする
	list_first_node = node;
	list_last_node = ft_lstlast_init(node);
	list_last_node->next = list_first_node;
	list_first_node->prev = list_last_node;
	//文字列の場合も後で対応する.
	node->len = argc - 1;
	node->first_flag = 1;
	return (node);
}