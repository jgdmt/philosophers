/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoudema <jgoudema@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 16:08:10 by jgoudema          #+#    #+#             */
/*   Updated: 2024/02/05 19:02:03 by jgoudema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_check_death(t_philo ph)
{
	int	time;

	pthread_mutex_lock(&ph.dt->meal);
	time = get_time() - ph.last_meal;
	pthread_mutex_unlock(&ph.dt->meal);
	if (time >= ph.dt->time_die)
	{
		ft_write_message(&ph, DIE);
		return (1);
	}
	return (0);
}

int	ft_check_meals(t_philo *ph)
{
	int	i;

	i = -1;
	if (ph[0].dt->must_eat == -1)
		return (0);
	while (++i < ph[0].dt->nb_philo)
	{
		pthread_mutex_lock(&ph[0].dt->meal);
		if (ph[i].nb_meal < ph[0].dt->must_eat)
		{
			pthread_mutex_unlock(&ph[0].dt->meal);
			return (0);
		}
		pthread_mutex_unlock(&ph[0].dt->meal);
	}
	return (1);
}

void	*ft_monitor(void *arg)
{
	t_philo	*ph;
	t_data	*dt;
	int		i;

	ph = (t_philo *) arg;
	dt = ph[0].dt;
	while (1)
	{
		i = -1;
		while (++i < dt->nb_philo)
		{
			if (ft_check_death(ph[i]) || ft_check_meals(ph))
			{
				pthread_mutex_lock(&dt->death);
				dt->dead = 1;
				pthread_mutex_unlock(&dt->death);
				return (NULL);
			}
		}
	}
	return (NULL);
}
