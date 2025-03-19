/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouass <ahouass@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:04:57 by ahouass           #+#    #+#             */
/*   Updated: 2025/01/10 12:33:32 by ahouass          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "get_next_line/get_next_line.h"
# include "ft_libft/libft.h"
# include <stdbool.h>

typedef struct s_stack_node
{
	int						value;
	int						index;
	struct s_stack_node		*next;
	struct s_stack_node		*prev;
}	t_stack_node;

// Linked list utilities
t_stack_node	*ft_lstnew(int data, int index);
int				ft_lstsize(t_stack_node *lst);
t_stack_node	*ft_lstlast(t_stack_node *lst);
void			ft_lstadd_back(t_stack_node **lst, t_stack_node *new);

// Stack operations
void			ft_swap_a(t_stack_node **lst, bool flag);
void			ft_swap_b(t_stack_node **lst, bool flag);
void			ft_swap_ab(t_stack_node **a, t_stack_node **b);
void			ft_push_a(t_stack_node **a, t_stack_node **b);
void			ft_push_b(t_stack_node **a, t_stack_node **b);
void			ft_rotate_a(t_stack_node **lst, bool flag);
void			ft_rotate_b(t_stack_node **lst, bool flag);
void			ft_rotate_ab(t_stack_node **a, t_stack_node **b);
void			ft_reverse_a(t_stack_node **lst, bool flag);
void			ft_reverse_b(t_stack_node **lst, bool flag);
void			ft_reverse_ab(t_stack_node **a, t_stack_node **b);

// Bonus stack operations
void			ft_swap_a_bonus(t_stack_node **lst);
void			ft_swap_b_bonus(t_stack_node **lst);
void			ft_swap_ab_bonus(t_stack_node **a, t_stack_node **b);
void			ft_push_a_bonus(t_stack_node **a, t_stack_node **b);
void			ft_push_b_bonus(t_stack_node **a, t_stack_node **b);
void			ft_rotate_a_bonus(t_stack_node **lst);
void			ft_rotate_b_bonus(t_stack_node **lst);
void			ft_rotate_ab_bonus(t_stack_node **a, t_stack_node **b);
void			ft_reverse_a_bonus(t_stack_node **lst);
void			ft_reverse_b_bonus(t_stack_node **lst);
void			ft_reverse_ab_bonus(t_stack_node **a, t_stack_node **b);

// Stack initialization and sorting
void			ft_stack_sort(t_stack_node **a, t_stack_node **b);
void			ft_stack_init(t_stack_node **a, int argc, char **argv);
void			ft_fill_stack(char **argv, t_stack_node **a);
void			ft_stack_free(t_stack_node *a);

// Error checking and utilities
void			ft_free_split(char **split);
int				ft_check_sort(t_stack_node *lst);
int				ft_check_min(t_stack_node *lst);
int				ft_check_max(t_stack_node *lst);
int				ft_located(t_stack_node *a, int value);
void			ft_increment_index(t_stack_node *lst, int value);
int				ft_get_index(t_stack_node *lst, int value);
void			ft_check_doubles(char **argv);
int				ft_count_words(char const *str, char c);
void			ft_exit_error(void);

#endif
