/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvaliyak <fvaliyak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 17:41:52 by fvaliyak          #+#    #+#             */
/*   Updated: 2022/11/04 19:26:54 by fvaliyak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static int	occ(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
		if (*(s++) != c)
			if (*s == c || !(*s))
				count++;
	return (count);
}

static char	*getword(const char *str, int start, int finish)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((finish - start + 1) * sizeof(char));
	while (start < finish)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	int		flag;
	char	**strs;

	if (!s)
		return (0);
	strs = malloc((occ(s, c) + 1) * sizeof(char *));
	if (!strs)
		return (0);
	i = -1;
	j = 0;
	flag = -1;
	while (++i <= ft_strlen(s))
	{
		if (s[i] != c && flag < 0)
			flag = i;
		else if ((s[i] == c || !s[i]) && flag >= 0)
		{
			strs[j++] = getword(s, flag, i);
			flag = -1;
		}
	}
	strs[j] = 0;
	return (strs);
}
