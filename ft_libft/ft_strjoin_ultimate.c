/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_ultimate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouass <ahouass@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:15:45 by ahouass           #+#    #+#             */
/*   Updated: 2025/01/10 12:28:33 by ahouass          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../push_swap.h"

static int	get_total_length(int argc, char **argv)
{
	int	i;
	int	length;

	i = 0;
	length = 0;
	while (i < argc - 1)
	{
		if (!argv[i][0])
		{
			ft_putstr_fd("Error\n", 2);
			exit(EXIT_FAILURE);
		}
		length += ft_strlen(argv[i]) + 1;
		i++;
	}
	return (length - 1);
}

static char	*concat_strings(int argc, char **argv, char *result)
{
	char	*temp;
	char	*new_result;
	int		i;

	i = 0;
	while (i < argc - 1)
	{
		if (ft_count_words(argv[i], ' ') == 0)
			ft_exit_error();
		temp = ft_strjoin(result, argv[i]);
		free(result);
		if (!temp)
			return (NULL);
		if (i < argc - 2)
		{
			new_result = ft_strjoin(temp, " ");
			free(temp);
			result = new_result;
		}
		else
			result = temp;
		i++;
	}
	return (result);
}

static char	*join_strings(int argc, char **argv, int length)
{
	char	*result;

	result = malloc(length + 1);
	if (!result)
		return (NULL);
	result[0] = '\0';
	return (concat_strings(argc, argv, result));
}

char	*ft_strjoin_ultimate(int argc, char **argv)
{
	int		length;

	length = get_total_length(argc, argv);
	return (join_strings(argc, argv, length));
}
