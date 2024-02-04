/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoudema <jgoudema@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 16:09:08 by jgoudema          #+#    #+#             */
/*   Updated: 2024/02/04 16:09:39 by jgoudema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_eat(t_philo *ph)
{
	pthread_mutex_lock(ph->lf);
	ft_write_message(ph, FORK);
	pthread_mutex_lock(ph->rf);
	ft_write_message(ph, FORK);
	ph->last_meal = get_time();
	ph->nb_meal++;
	ft_write_message(ph, EAT);
	ft_usleep(ph->dt->time_eat);
	pthread_mutex_unlock(ph->lf);
	pthread_mutex_unlock(ph->rf);
}

void	ft_think_sleep(t_philo *ph)
{
	ft_write_message(ph, SLEEP);
	ft_usleep(ph->dt->time_sleep);
	ft_write_message(ph, THINK);
}

void	*ft_routine(void *arg)
{
	t_philo	*ph;

	ph = (t_philo *) arg;
	while (!ph->dt->done)
		continue ;
	if (!(ph->nb % 2))
		ft_usleep(ph->dt->time_eat * 0.5);
	while (!ph->dt->dead)
	{
		ft_eat(ph);
		ft_think_sleep(ph);
	}
	return (0);
}
