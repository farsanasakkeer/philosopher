/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvaliyak <fvaliyak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 14:39:04 by fvaliyak          #+#    #+#             */
/*   Updated: 2022/11/04 19:55:19 by fvaliyak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int n)
{
	if (n >= 48 && n <= 57)
	{
		return (1);
	}
	if ((n >= 65 && n <= 90) || (n >= 97 && n <= 122))
	{
		return (1);
	}
	return (0);
}
