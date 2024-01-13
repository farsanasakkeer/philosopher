/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: farsana <farsana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 17:02:41 by farsana           #+#    #+#             */
/*   Updated: 2024/01/11 12:17:09 by farsana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <unistd.h>
# include <ctype.h>
# include <stddef.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdarg.h>
# include "libft/libft.h"

typedef struct common_data
{
    int				no_of_phil;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			no_of_eats;
	pthread_mutex_t	*fork;
	pthread_mutex_t	*task;
	int				death;
	int				flag;
	int				flag_death;
	
	


}	t_data;

typedef struct philo
{
	int			id;
	int			n_eats; //no_of_eats
	pthread_t	phi_t; //thread
	t_data		*dt; //common data
}	t_phi;

int 	parsing(int ac, char **av);
int		is_number(int n, char **arg);
int		ft_isdigit(int n);

int		ft_atoi1(const char *str);
void	init_data(int ac, char **av);
void	init_check(int ac, char **av);
void 	init_philo(t_phi *phi, t_data *data, int t);
size_t	get_time(void);


void	ft_error(t_phi *phi, int flag);
void	unlock_stick(t_data *data, int left_fork, int right_fork, size_t start);
int		death_checker(t_data *data, size_t *d);
size_t	time_update(t_phi *phi, size_t ptime, size_t t, size_t ts);
void	check_death(t_phi *phi, size_t ta, size_t tb, size_t ts);
void	check_eats(t_phi *phi);
void	lock_stick(t_data *data, int left_fork, int right_fork, size_t start_time);
void	printer(t_data *data, int time, int id, int flag);



void	philoop(t_phi *phi_1, t_data *data, size_t *d);

void 	*philosopher(void *phi);

#endif