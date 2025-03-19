/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouass <ahouass@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 13:18:41 by ahouass           #+#    #+#             */
/*   Updated: 2025/01/09 22:24:44 by ahouass          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_put_error_and_exit(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

static int	ft_is_whitespace(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

static void	ft_check_digits(const char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str))
			ft_put_error_and_exit();
		str++;
	}
}

static int	ft_get_sign(const char **str)
{
	int	sign;

	sign = 1;
	if (**str == '-' || **str == '+')
	{
		if (**str == '-')
			sign = -1;
		(*str)++;
	}
	return (sign);
}

long	ft_atoi(const char *str)
{
	int		sign;
	long	res;

	if (!str)
		ft_put_error_and_exit();
	while (ft_is_whitespace(*str))
		str++;
	sign = ft_get_sign(&str);
	if (!ft_isdigit(*str))
		ft_put_error_and_exit();
	ft_check_digits(str);
	res = 0;
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		if ((res * sign) > INT_MAX || (res * sign) < INT_MIN)
			ft_put_error_and_exit();
		str++;
	}
	return (res * sign);
}
