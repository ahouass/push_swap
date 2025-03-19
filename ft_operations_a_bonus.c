/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations_a_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouass <ahouass@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 15:05:09 by ahouass           #+#    #+#             */
/*   Updated: 2025/01/10 20:51:00 by ahouass          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_a_bonus(t_stack_node **lst)
{
	t_stack_node	*first;
	t_stack_node	*second;

	if (!lst || !(*lst) || !((*lst)->next))
		return ;
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
}

void	ft_rotate_a_bonus(t_stack_node **lst)
{
	t_stack_node	*first;
	t_stack_node	*last;

	if (!lst || !(*lst) || !((*lst)->next))
		return ;
	first = *lst;
	last = ft_lstlast(*lst);
	*lst = (*lst)->next;
	(*lst)->prev = NULL;
	last->next = first;
	first->next = NULL;
	first->prev = last;
}

void	ft_reverse_a_bonus(t_stack_node **lst)
{
	t_stack_node	*first;
	t_stack_node	*last;

	if (!lst || !(*lst) || !((*lst)->next))
		return ;
	first = *lst;
	last = ft_lstlast(*lst);
	if (last && last->prev)
	{
		last->prev->next = NULL;
		last->prev = NULL;
	}
	last->next = first;
	first->prev = last;
	*lst = last;
}

void	ft_push_a_bonus(t_stack_node **a, t_stack_node **b)
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
}
