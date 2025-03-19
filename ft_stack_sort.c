/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouass <ahouass@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 13:33:22 by ahouass           #+#    #+#             */
/*   Updated: 2025/01/10 17:15:42 by ahouass          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_max(t_stack_node **a, t_stack_node **b, int max)
{
	int	located;

	located = ft_located(*a, max);
	while ((*a)->value != max)
	{
		if (located < ft_lstsize(*a) / 2)
			ft_rotate_b(a, true);
		else
			ft_reverse_b(a, true);
	}
	ft_push_a(a, b);
	return ;
}

void	ft_push_min(t_stack_node **a, t_stack_node **b, int min)
{
	int	located;

	located = ft_located(*a, min);
	while ((*a)->value != min)
	{
		if (located < ft_lstsize(*a) / 2)
			ft_rotate_a(a, true);
		else
			ft_reverse_a(a, true);
	}
	ft_push_b(a, b);
	return ;
}

void	ft_push_range(t_stack_node **a, t_stack_node **b, int *start, int *end)
{
	if ((*a)->index >= *start && (*a)->index <= *end)
	{
		ft_push_b(a, b);
		(*start)++;
		(*end)++;
	}
	else if ((*a)->index > *end)
		ft_rotate_a(a, true);
	else if ((*a)->index < *start)
	{
		ft_push_b(a, b);
		ft_rotate_b(b, true);
		(*start)++;
		(*end)++;
	}
	return ;
}

void	ft_stack_sort_length(t_stack_node **a, t_stack_node **b, int length)
{
	if (length == 2)
	{
		if ((*a)->value > (*a)->next->value)
			ft_swap_a(a, true);
	}
	else if (length == 3)
	{
		if ((*a)->value > (*a)->next->value)
			ft_swap_a(a, true);
		if ((*a)->value > (*a)->next->next->value)
			ft_reverse_a(a, true);
		else if ((*a)->next->value > (*a)->next->next->value)
		{
			ft_reverse_a(a, true);
			ft_swap_a(a, true);
		}
	}
	else
	{
		while (ft_lstsize(*a) > 3)
			ft_push_min(a, b, ft_check_min(*a));
		ft_stack_sort(a, b);
		while (ft_lstsize(*b) > 0)
			ft_push_a(b, a);
	}
}

void	ft_stack_sort(t_stack_node **a, t_stack_node **b)
{
	int	range_start;
	int	range_end;
	int	length;

	range_start = 0;
	range_end = ft_lstsize(*a) * 0.05 + 10;
	length = ft_lstsize(*a);
	if (length > 1 && !ft_check_sort(*a))
	{
		if (length <= 5)
			ft_stack_sort_length(a, b, length);
		else
		{
			while (ft_lstsize(*a) > 0)
				ft_push_range(a, b, &range_start, &range_end);
			while (ft_lstsize(*b) > 0)
				ft_push_max(b, a, ft_check_max(*b));
		}
	}
}
