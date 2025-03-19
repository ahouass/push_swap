/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouass <ahouass@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 15:05:09 by ahouass           #+#    #+#             */
/*   Updated: 2025/01/10 16:31:05 by ahouass          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_ab(t_stack_node **a, t_stack_node **b)
{
	ft_swap_a(a, false);
	ft_swap_b(b, false);
	ft_putstr_fd("ss\n", 1);
}

void	ft_rotate_ab(t_stack_node **a, t_stack_node **b)
{
	ft_rotate_a(a, false);
	ft_rotate_b(b, false);
	ft_putstr_fd("rr\n", 1);
}

void	ft_reverse_ab(t_stack_node **a, t_stack_node **b)
{
	ft_reverse_a(a, false);
	ft_reverse_b(b, false);
	ft_putstr_fd("rrr\n", 1);
}
