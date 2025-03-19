/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouass <ahouass@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 21:34:50 by ahouass           #+#    #+#             */
/*   Updated: 2025/01/10 15:29:16 by ahouass          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_fill_stack(char **argv, t_stack_node **a)
{
	int	i;
	int	max;
	int	index;
	int	tmp_index;

	i = 0;
	index = 0;
	max = ft_atoi(argv[i]);
	while (argv[i])
	{
		if (ft_atoi(argv[i]) < max)
		{
			tmp_index = ft_get_index(*a, ft_atoi(argv[i]));
			ft_lstadd_back(a, ft_lstnew(ft_atoi(argv[i]), tmp_index));
			ft_increment_index(*a, ft_atoi(argv[i]));
			index++;
		}
		else
		{
			ft_lstadd_back(a, ft_lstnew(ft_atoi(argv[i]), index));
			max = ft_atoi(argv[i]);
			index++;
		}
		i++;
	}
}

void	ft_free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	ft_stack_init(t_stack_node **a, int argc, char **argv)
{
	char	*str;
	char	**new_argv;

	str = NULL;
	if (argc == 1)
		return ;
	else
		str = ft_strjoin_ultimate(argc, argv + 1);
	new_argv = ft_split(str, ' ');
	if (!new_argv)
		ft_exit_error();
	free(str);
	ft_check_doubles(new_argv);
	ft_fill_stack(new_argv, a);
	ft_free_split(new_argv);
}

void	ft_stack_free(t_stack_node *a)
{
	t_stack_node	*tmp;

	while (a)
	{
		tmp = a;
		a = a->next;
		free(tmp);
	}
}
