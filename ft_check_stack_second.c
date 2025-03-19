/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_stack_second.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouass <ahouass@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 14:37:43 by ahouass           #+#    #+#             */
/*   Updated: 2025/01/10 11:39:50 by ahouass          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_increment_index(t_stack_node *lst, int value)
{
	while (lst)
	{
		if (lst->value > value)
			lst->index++;
		lst = lst->next;
	}
}

int	ft_get_index(t_stack_node *lst, int value)
{
	int	min_index;

	min_index = 500;
	while (lst)
	{
		if (lst->value > value && lst->index < min_index)
		{
			min_index = lst->index;
		}
		lst = lst->next;
	}
	return (min_index);
}

void	ft_check_doubles(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = i + 1;
		while (argv[j])
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				ft_exit_error();
			j++;
		}
		i++;
	}
}
