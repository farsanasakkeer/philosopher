/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: farsana <farsana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 15:23:23 by farsana           #+#    #+#             */
/*   Updated: 2023/12/07 11:11:24 by farsana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


int	ft_isdigit(int n)
{
	if ((n >= 48 && n <= 57) || n == ' ' || n == '+' \
	|| n == '-' || (n >= '\t' && n <= '\r'))
	{
		return (1);
	}
	return (0);
}

int	is_number(int n, char **arg)
{
	int	i;

	while (n > 1)
	{
		i = 0;
		while (arg[n - 1][i] == ' ' \
		|| (arg[n - 1][i] >= '\t' && arg[n - 1][i] <= '\r'))
		{
			i++;
		}
		while (arg[n - 1][i] && ft_isdigit(arg[n - 1][i]) == 1)
		{
			i++;
		}
		if (arg[n - 1][i] && ft_isdigit(arg[n - 1][i]) == 0)
			return (0);
		n--;
	}
	return (1);
}



int parsing(int ac, char **av)
{
  int i;

  i = 1;
  if (ac > 6 || ac < 5)
	{
		printf("invalid number of arguments\n");
		return (0);//error
	}
  if (is_number(ac, av) == 0)
    return (0);//error
  return (1);
}
