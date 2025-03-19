/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouass <ahouass@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 13:32:57 by ahouass           #+#    #+#             */
/*   Updated: 2024/11/10 11:50:41 by ahouass          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	void	*p;

	if (size != 0)
	{
		if (n > ((size_t) - 1) / size)
			return (NULL);
	}
	p = malloc(n * size);
	if (!p)
		return (0);
	ft_bzero(p, size * n);
	return (p);
}
