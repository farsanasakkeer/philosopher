/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvaliyak <fvaliyak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 17:26:35 by fvaliyak          #+#    #+#             */
/*   Updated: 2022/11/04 19:55:55 by fvaliyak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libc.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*d;
	unsigned char	*p;

	d = (unsigned char *)dest;
	p = (unsigned char *)src;
	if (d == NULL && p == NULL)
		return (0);
	i = 0;
	if (d < p)
	{
		while (n > i)
		{
			d[i] = p[i];
			i++;
		}
	}
	else
	{
		while (n > i++)
		{
			d[n - i] = p[n - i];
		}
	}
	return (dest);
}
