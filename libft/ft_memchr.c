/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvaliyak <fvaliyak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 15:54:16 by fvaliyak          #+#    #+#             */
/*   Updated: 2022/11/04 19:54:51 by fvaliyak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t	i;
	char	*st;

	i = 0;
	st = (char *)str;
	while (i < n)
	{
		if (*(st + i) == (char)c)
			return ((void *)st + i);
		i++;
	}
	return (0);
}

/*#include<stdio.h>
#include <string.h>
int	main(void)
{
	char *r;                   //memchr
    char s[20]="abcdefghijk";
	char f = 'f';
    r = memchr(s,f,19);
    char *p;
    p = ft_memchr(s,f,19);
    printf("\n%s %s", r, p);


}*/

/*
void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned char	cs;
	size_t			i;

	ptr = (unsigned char*)s;
	cs = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (*(ptr + i) == cs)
		{
			return (ptr + i);
		}
		i++;
	}
	return (0);
}*/
