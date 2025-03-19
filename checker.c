/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouass <ahouass@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 19:56:33 by ahouass           #+#    #+#             */
/*   Updated: 2025/01/10 16:54:47 by ahouass          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	handle_error(char *line)
{
	ft_putstr_fd("Error\n", 2);
	free(line);
	exit(EXIT_FAILURE);
}

void	execute_command(char *line, t_stack_node **a, t_stack_node **b)
{
	if (!ft_strcmp(line, "sa\n"))
		ft_swap_a_bonus(a);
	else if (!ft_strcmp(line, "sb\n"))
		ft_swap_b_bonus(b);
	else if (!ft_strcmp(line, "ss\n"))
		ft_swap_ab_bonus(a, b);
	else if (!ft_strcmp(line, "pa\n"))
		ft_push_a_bonus(b, a);
	else if (!ft_strcmp(line, "pb\n"))
		ft_push_b_bonus(a, b);
	else if (!ft_strcmp(line, "ra\n"))
		ft_rotate_a_bonus(a);
	else if (!ft_strcmp(line, "rb\n"))
		ft_rotate_b_bonus(b);
	else if (!ft_strcmp(line, "rr\n"))
		ft_rotate_ab_bonus(a, b);
	else if (!ft_strcmp(line, "rra\n"))
		ft_reverse_a_bonus(a);
	else if (!ft_strcmp(line, "rrb\n"))
		ft_reverse_b_bonus(b);
	else if (!ft_strcmp(line, "rrr\n"))
		ft_reverse_ab_bonus(a, b);
	else
		handle_error(line);
}

void	process_commands(t_stack_node **a, t_stack_node **b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		execute_command(line, a, b);
		free(line);
		line = get_next_line(0);
	}
}

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (argc <= 1)
		return (0);
	ft_stack_init(&a, argc, argv);
	process_commands(&a, &b);
	if (ft_check_sort(a) && ft_lstsize(b) == 0)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	ft_stack_free(a);
	ft_stack_free(b);
	return (0);
}
