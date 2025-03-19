/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouass <ahouass@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 14:37:43 by ahouass           #+#    #+#             */
/*   Updated: 2025/01/10 15:37:08 by ahouass          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_exit_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

int	ft_check_sort(t_stack_node *lst)
{
	if (!lst)
		return (1);
	while (lst->next)
	{
		if (lst->value > lst->next->value)
			return (0);
		lst = lst->next;
	}
	return (1);
}

int	ft_check_min(t_stack_node *lst)
{
	int	min;

	min = INT_MAX;
	while (lst)
	{
		if (lst->value < min)
			min = lst->value;
		lst = lst->next;
	}
	return (min);
}

int	ft_check_max(t_stack_node *lst)
{
	int	max;

	max = INT_MIN;
	while (lst)
	{
		if (lst->value > max)
			max = lst->value;
		lst = lst->next;
	}
	return (max);
}

int	ft_located(t_stack_node *a, int value)
{
	int	located;

	located = 0;
	while (a->value != value)
	{
		a = a->next;
		located++;
	}
	return (located);
}
