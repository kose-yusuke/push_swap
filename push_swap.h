/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykoseki <ykoseki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 19:41:59 by ykoseki           #+#    #+#             */
/*   Updated: 2024/03/17 10:11:00 by ykoseki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# include <stdio.h>
# include <stdlib.h>

typedef struct s_node
{
	int				value;
	int				index;
	int				len;
	int				first_flag;
	struct s_node	*prev;
	struct s_node	*next;
}					t_node;

t_node				*ft_lstlast_init(t_node *node);
t_node				*ft_nodenew(int value);
void				ft_nodeadd_last_init(t_node **node, int value);
void				ft_nodedelone(t_node *node);
t_node				*init_list(char **argv, int argc);
void				ft_swap_pa(t_node **stack_a, t_node **stack_b);
void				ft_swap_pb(t_node **stack_a, t_node **stack_b);
int					digit_len(int n);
int					max_digitsize(int argc, char **argv);
void				ft_swap_sa(t_node **stack_a);
void				ft_swap_sb(t_node **stack_b);
void				ft_swap_ss(t_node **stack_a, t_node **stack_b);
void				ft_swap_ra(t_node **stack_a);
void				ft_swap_rb(t_node **stack_b);
void				ft_swap_rr(t_node **stack_a, t_node **stack_b);
void				ft_swap_rra(t_node **stack_a);
void				ft_swap_rrb(t_node **stack_b);
void				ft_swap_rrr(t_node **stack_a, t_node **stack_b);
int					error_message(void);
bool				is_sorted(t_node **stack_a);
int					small_sort(t_node **stack_a, t_node **stack_b);
int					three_sort(t_node **a);
int					get_min_index(t_node **stack_a);
int					min_index_position(t_node **stack_a);
int					four_sort(t_node **stack_a, t_node **stack_b);
int					five_sort(t_node **stack_a, t_node **stack_b);
int					print_list(t_node **stack_a);
int					get_max(t_node **stack_a);
int					get_max_bit(t_node **stack_a);
void				radix_sort(t_node **stack_a, t_node **stack_b, int max_dgt);
int					ft_error_handling(int argc, char **argv);
int					ft_isunique(int argc, char **argv, char *str, int index);
int					ft_isint(char *argv);
void				ft_free_stack(t_node **stack_a);
void				ft_free(char **str);
int					ft_compress_value(t_node **stack_a);
void				ft_push_helper(t_node **stack);
void				ft_push_helper2(t_node **stack);
void				ft_sa_and_ra(t_node **a);

#endif
