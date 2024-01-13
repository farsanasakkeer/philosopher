/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvaliyak <fvaliyak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 15:35:14 by fvaliyak          #+#    #+#             */
/*   Updated: 2022/11/04 19:59:56 by fvaliyak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *p, int c)
{
	char	*s;
	int		i;

	i = 0;
	s = NULL;
	while (p[i])
	{
		if (p[i] == (char)c)
		{
			s = ((char *)p + i);
		}
		i++;
	}
	if (c == '\0')
		return ((char *)p + i);
	return (s);
}
