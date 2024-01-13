/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvaliyak <fvaliyak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 18:24:24 by fvaliyak          #+#    #+#             */
/*   Updated: 2022/11/04 19:57:59 by fvaliyak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *ls, const char *ss, size_t len)
{
	unsigned int	i;
	unsigned int	j;

	if (!ls && len == 0)
	{
		return (NULL);
	}
	if (ss[0] == '\0')
		return ((char *)ls);
	i = 0;
	while (ls[i] && i < len)
	{
		j = 0;
		if (ls[i] == ss[j])
		{
			while (i + j < len && ls[i + j] == ss[j])
			{
				j++;
				if (!ss[j])
					return ((char *)&ls[i]);
			}
		}
		i++;
	}
	return (0);
}
