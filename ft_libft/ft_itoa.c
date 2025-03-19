/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouass <ahouass@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 09:40:27 by ahouass           #+#    #+#             */
/*   Updated: 2024/10/29 09:49:07 by ahouass          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_num_length(int n)
{
	int		l;
	long	num;

	l = 0;
	num = n;
	if (num == 0)
		return (1);
	if (num < 0)
	{
		num = -num;
		l++;
	}
	while (num > 0)
	{
		num = num / 10;
		l++;
	}
	return (l);
}

char	*ft_itoa(int n)
{
	int		i;
	long	num;
	int		size;
	char	*res;

	i = 0;
	size = ft_num_length(n);
	res = malloc(size + 1);
	if (!res)
		return (NULL);
	res[size--] = '\0';
	num = n;
	if (num < 0)
	{
		num = -num;
		res[i] = '-';
		i++;
	}
	while (size >= i)
	{
		res[size] = num % 10 + '0';
		num = num / 10;
		size--;
	}
	return (res);
}
