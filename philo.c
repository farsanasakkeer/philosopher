/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: farsana <farsana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 16:56:55 by farsana           #+#    #+#             */
/*   Updated: 2024/01/13 11:51:10 by farsana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void printer(t_data *data, int time, int id, int flag)
{
	if (flag == 1 && !data->flag_death )
	{
		data->flag_death = 1;
		printf("%d %d died\n", time, id);
	}
	else if (flag == 2 && !data->flag_death )
	{
		printf("%d %d has taken a fork\n", time, id);
		printf("%d %d has taken a fork\n", time, id);
		printf("%d %d is eating\n", time, id);
	}
	else if (flag == 3 && !data->flag_death )
		printf("%d %d is thinking \n", time, id);
	else if (flag == 4 && !data->flag_death )
		printf("%d %d is sleeping \n", time, id);
}

void lock_stick(t_data *data, int left_fork, int right_fork, size_t start_time)
{
	if (left_fork % 2 != 0)
	{
		pthread_mutex_lock(&data->fork[left_fork]);
		pthread_mutex_lock(&data->fork[right_fork]);
	}
	else
	{
		pthread_mutex_lock(&data->fork[right_fork]);
		pthread_mutex_lock(&data->fork[left_fork]);
	}
	pthread_mutex_lock(&data->task[0]);
	printer(data, get_time() - start_time, left_fork, 2);//eating by (leftfork is philo no)
	pthread_mutex_unlock(&data->task[0]);

}

void	check_eats(t_phi *phi)
{
	pthread_mutex_lock(&phi->dt->task[2]);
	if (phi->n_eats)
		phi->n_eats -= 1;
	else
		ft_error(phi, 1);
	pthread_mutex_unlock(&phi->dt->task[2]);
}

void	check_death(t_phi *phi, size_t ta, size_t tb, size_t ts)
{
	t_data *data;

	data = phi->dt;
	if (ta - tb >= data->time_to_die)
	{
		pthread_mutex_lock(&data->task[0]);
		printer(data, (int)get_time() - ts, phi->id, 1);
		pthread_mutex_unlock(&data->task[0]);
		ft_error(phi, 2);//call error
	}
}

size_t	time_update(t_phi *phi, size_t ptime, size_t t, size_t ts)
{
	size_t	time;

	time = get_time();
	while (1)
	{
		usleep(100);
		if (check_death(phi, get_time(), t, ts), (get_time() - time) >= ptime)
			break ;
	}
	return (get_time() - time);
}

int	death_checker(t_data *data, size_t *d)
{
	pthread_mutex_lock(&data->task[1]);
	if (data->death)
	{
		pthread_mutex_unlock(&data->fork[d[0]]);
		pthread_mutex_unlock(&data->fork[d[1]]);
		pthread_mutex_unlock(&data->task[1]);
		return (1);
	}
	pthread_mutex_unlock(&data->task[1]);
	return (0);
}

void	ft_error(t_phi *phi, int flag)
{
	t_data	*data;

	data = phi->dt;
	pthread_mutex_lock(&data->task[1]);
	if (flag == 1)
		data->death = 1;
	else if (flag == 2)
		data->death = 1;
	pthread_mutex_unlock(&data->task[1]);
}

void	unlock_stick(t_data *data, int left_fork, int right_fork, size_t start)
{
	pthread_mutex_unlock(&data->fork[left_fork]);
	pthread_mutex_unlock(&data->fork[right_fork]);
	pthread_mutex_lock(&data->task[0]);
	printer(data, get_time() - start, left_fork, 4);
	pthread_mutex_unlock(&data->task[0]);
}

void	philoop(t_phi *phi_1, t_data *data, size_t *d)
{
	while (1)
	{
		d[0] = phi_1->id;
		d[1] = (phi_1->id + 1) % (data->no_of_phil);
		lock_stick(data, d[0], d[1], d[4]);//eat
		pthread_mutex_lock(&data->task[0]);
		if (data->flag) //no of eats
			check_eats(phi_1);
		pthread_mutex_unlock(&data->task[0]);
		check_death(phi_1, get_time(), d[3], d[4]);
		d[2] = time_update(phi_1, data->time_to_eat, d[3], d[4]);
		d[3] = get_time();
		if (death_checker(data, d))
			break ;
		unlock_stick(data, d[0], d[1], d[4]);
		d[2] = time_update(phi_1, data->time_to_sleep, d[3], d[4]);
		pthread_mutex_lock(&data->task[0]);
		printer(data, get_time() - d[4], phi_1->id, 3);
		pthread_mutex_unlock(&data->task[0]);
	}
}

void *philosopher(void *phi)
{
	size_t	d[5];
	t_phi	*phi_1;
	t_data	*data;
	
	d[3] = get_time();
	d[4] = d[3];
	phi_1 = (t_phi *)phi;
	data = phi_1->dt;
	philoop(phi_1,data,d);
	return (NULL);
}


int	main(int ac, char **av)
{
    // t_philo *philo;
    
    if (parsing(ac, av) == 0)
        exit (0);
    // philo = malloc (sizeof (t_philo) * ft_atoi(av[1]));
	init_check(ac, av);
}