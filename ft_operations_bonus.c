/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouass <ahouass@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 15:05:09 by ahouass           #+#    #+#             */
/*   Updated: 2025/01/10 15:47:38 by ahouass          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_ab_bonus(t_stack_node **a, t_stack_node **b)
{
	ft_swap_a_bonus(a);
	ft_swap_b_bonus(b);
}

void	ft_rotate_ab_bonus(t_stack_node **a, t_stack_node **b)
{
	ft_rotate_a_bonus(a);
	ft_rotate_b_bonus(b);
}

void	ft_reverse_ab_bonus(t_stack_node **a, t_stack_node **b)
{
	ft_reverse_a_bonus(a);
	ft_reverse_b_bonus(b);
}
