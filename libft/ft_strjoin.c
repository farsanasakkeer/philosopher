/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvaliyak <fvaliyak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 12:57:03 by fvaliyak          #+#    #+#             */
/*   Updated: 2022/11/04 19:59:00 by fvaliyak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size;
	char	*res;
	int		i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	size = 0;
	size += ft_strlen(s1);
	size += ft_strlen(s2);
	res = (char *)malloc(sizeof(char) * (size + 1));
	if (!res)
		return (NULL);
	res[size] = '\0';
	i = 0;
	j = 0;
	while (s1[i])
		res[j++] = s1[i++];
	i = 0;
	while (s2[i])
		res[j++] = s2[i++];
	return (res);
}
