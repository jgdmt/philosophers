/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoudema <jgoudema@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 16:09:08 by jgoudema          #+#    #+#             */
/*   Updated: 2024/02/05 19:02:14 by jgoudema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_eat(t_philo *ph)
{
	pthread_mutex_lock(ph->lf);
	ft_write_message(ph, FORK);
	if (ph->dt->nb_philo == 1)
	{
		pthread_mutex_unlock(ph->lf);
		ft_usleep(ph->dt->time_die);
		return ;
	}
	pthread_mutex_lock(ph->rf);
	ft_write_message(ph, FORK);
	pthread_mutex_lock(&ph[0].dt->meal);
	ph->last_meal = get_time();
	ph->nb_meal++;
	pthread_mutex_unlock(&ph[0].dt->meal);
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

int	ft_is_dead(t_data *dt)
{
	pthread_mutex_lock(&dt->death);
	if (dt->dead)
	{
		pthread_mutex_unlock(&dt->death);
		return (1);
	}
	pthread_mutex_unlock(&dt->death);
	return (0);
}

void	*ft_routine(void *arg)
{
	t_philo	*ph;

	ph = (t_philo *) arg;
	while (1)
	{
		pthread_mutex_lock(&ph->dt->write);
		if (ph->dt->done)
		{
			pthread_mutex_unlock(&ph->dt->write);
			break ;
		}
		pthread_mutex_unlock(&ph->dt->write);
	}
	if (!(ph->nb % 2))
		ft_usleep(ph->dt->time_eat * 0.5);
	while (1)
	{
		ft_eat(ph);
		ft_think_sleep(ph);
		if (ft_is_dead(ph->dt))
			return (0);
	}
	return (0);
}
