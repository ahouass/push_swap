/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouass <ahouass@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 09:39:19 by ahouass           #+#    #+#             */
/*   Updated: 2025/01/06 21:26:31 by ahouass          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*ft_lstnew(int data, int index)
{
	t_stack_node	*new_list;

	new_list = malloc(sizeof(t_stack_node));
	if (!new_list)
		return (NULL);
	new_list->value = data;
	new_list->index = index;
	new_list->next = NULL;
	new_list->prev = NULL;
	return (new_list);
}
