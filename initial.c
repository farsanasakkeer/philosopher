/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: farsana <farsana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 11:12:17 by farsana           #+#    #+#             */
/*   Updated: 2024/01/11 12:16:12 by farsana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, 0);
	return ((tv.tv_sec * 1000 + tv.tv_usec / 1000));
}

int	ft_atoi1(const char *str)
{
	int				count;
	unsigned int	sum;

	count = 1;
	sum = 0;
	while (*str == ' ' || *str == '\n' || *str == '\t' || *str == '\f'
		|| *str == '\r' || *str == '\v')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			count = -count;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		sum = sum * 10 + (*str - '0');
		str++;
		if (sum > 2147483647)
			return (-1);
	}
	while (*str)
		if (*str++ != 32)
			return (-1);
	return (sum * count);
}

void	threading(t_phi *phi, t_data *data)
{
    int	i;

	i = -1;
	while (++i < data->no_of_phil)
	{
		pthread_create (&phi[i].phi_t, NULL, philosopher, (void *)&phi[i]);
		usleep(500);
	}
	i = -1;
	while (++i < data->no_of_phil)
		pthread_join (phi[i].phi_t, NULL);
	i = -1;
	while (++i < 5)
		pthread_mutex_destroy(&data->task[i]);
	i = -1;
	while (++i < data->no_of_phil)
		pthread_mutex_destroy(&data->fork[i]);
	free (data->fork);
	free (data->task);
	free (data);
	free (phi);
	return ;
}

void init_philo(t_phi *phi, t_data *data, int t)
{
	int	i;
	
	i = -1;
	data->death = 0;
	while(++i < data->no_of_phil)
	{
		phi[i].id = i;
		phi[i].dt = data;
		if (t)
		{
			phi[i].n_eats = t;
			data->flag = 1;
		}
		else
			data->flag = 0;
	}
    threading(phi,data);
}

void	init_data(int ac, char **av)
{
	t_phi	*phi;
	t_data	*data;
	int		t;//no of eats
	int		i;
	
	phi = malloc(sizeof(t_phi) * ft_atoi1(av[1]));
	data = malloc(sizeof(t_data));
	data->no_of_phil = ft_atoi1( av[1]);
	data->time_to_die = ft_atoi1(av[2]);
	data->time_to_eat = ft_atoi1(av[3]);
	data->time_to_sleep = ft_atoi1(av[4]);
	data->flag_death = 0;
	if (ac == 6)
		t = ft_atoi1(av[5]);
	else
		t = 0;
	i = -1;
	data->task = malloc(sizeof(pthread_mutex_t) * 5);//5 tasks
	while (++i < 5)
		pthread_mutex_init(&data->task[i], NULL);//task init
	data->fork = malloc(sizeof(pthread_mutex_t) * data->no_of_phil);
	i = -1;
	while (++i < data->no_of_phil)
		pthread_mutex_init(&data->fork[i], NULL);//fork init
	init_philo(phi, data, t);
}

void	init_check(int ac, char **av)
{
	if (ft_atoi1(av[1]) > 200 || ft_atoi1(av[2]) < 60 || ft_atoi1(av[3]) < 60
		|| ft_atoi1(av[4]) < 60 || ft_atoi1(av[1]) < 1 )
		return ;
	else if (ft_atoi1(av[1]) == 1)
		printf("%d %d died \n", ft_atoi1(av[2]), 1);
	else if (ft_atoi1(av[ac - 1]) < 1 && ac == 6)
		return ;
	else
		init_data(ac, av);
}