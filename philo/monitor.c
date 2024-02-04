/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoudema <jgoudema@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 16:08:10 by jgoudema          #+#    #+#             */
/*   Updated: 2024/02/04 16:08:40 by jgoudema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_check_death(t_philo ph)
{
	int	time;

	time = get_time() - ph.last_meal;
	if (time >= ph.dt->time_die)
	{
		ft_write_message(&ph, DIE);
		pthread_mutex_unlock(ph.rf);
		pthread_mutex_unlock(ph.lf);
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
		if (ph[i].nb_meal < ph[0].dt->must_eat)
			return (0);
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
	while (!dt->dead)
	{
		i = -1;
		while (++i < dt->nb_philo)
			if (ft_check_death(ph[i]) || ft_check_meals(ph))
				dt->dead = 1;
	}
	return (NULL);
}
