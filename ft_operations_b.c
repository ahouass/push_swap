/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouass <ahouass@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 15:05:09 by ahouass           #+#    #+#             */
/*   Updated: 2025/01/10 11:09:53 by ahouass          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_b(t_stack_node **lst, bool flag)
{
	t_stack_node	*first;
	t_stack_node	*second;

	first = *lst;
	second = (*lst)->next;
	if (second->next)
	{
		first->next = second->next;
		second->next->prev = first;
	}
	else
		first->next = NULL;
	second->next = first;
	second->prev = NULL;
	*lst = second;
	if (flag)
		ft_putstr_fd("sb\n", 1);
}

void	ft_rotate_b(t_stack_node **lst, bool flag)
{
	t_stack_node	*first;
	t_stack_node	*last;

	first = *lst;
	last = ft_lstlast(*lst);
	*lst = (*lst)->next;
	(*lst)->prev = NULL;
	last->next = first;
	first->next = NULL;
	first->prev = last;
	if (flag)
		ft_putstr_fd("rb\n", 1);
}

void	ft_reverse_b(t_stack_node **lst, bool flag)
{
	t_stack_node	*first;
	t_stack_node	*last;

	first = *lst;
	last = ft_lstlast(*lst);
	last->prev->next = NULL;
	last->prev = NULL;
	last->next = first;
	first->prev = last;
	*lst = last;
	if (flag)
		ft_putstr_fd("rrb\n", 1);
}

void	ft_push_b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*first_a;

	if (!a || !*a)
		return ;
	first_a = *a;
	*a = (*a)->next;
	if (*a)
		(*a)->prev = NULL;
	if (!*b)
	{
		*b = first_a;
		(*b)->next = NULL;
	}
	else
	{
		first_a->next = *b;
		(*b)->prev = first_a;
		*b = first_a;
	}
	ft_putstr_fd("pb\n", 1);
}
