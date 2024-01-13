/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvaliyak <fvaliyak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 13:04:55 by fvaliyak          #+#    #+#             */
/*   Updated: 2022/11/04 19:58:13 by fvaliyak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	sub_find(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i++] == c)
			return (1);
	}
	return (0);
}

int	finda(char const *s1, char const *set)
{
	int	a;

	a = 0;
	while (s1[a])
	{
		if (sub_find(s1[a++], set) == 0)
			break ;
	}
	return (a);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		a;
	int		b;
	char	*str;
	int		i;

	if (!s1)
		return (0);
	a = finda(s1, set);
	if (a != 0)
		a--;
	b = ft_strlen(s1);
	while (b-- > a)
	{
		if (sub_find(s1[b], set) == 0)
			break ;
	}
	str = (char *)malloc(sizeof(char) * (b - a + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (b >= a)
		str[i++] = s1[a++];
	str[i] = '\0';
	return (str);
}
