/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoudema <jgoudema@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:15:34 by jgoudema          #+#    #+#             */
/*   Updated: 2024/02/01 20:15:14 by jgoudema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// void	ft_clean(t_data *data)
// {
// 	int	i;

// 	i = 0;

// }

static int	ft_check_arg(t_data *dt)
{
	if (dt->nb_philo < 0)
		return (0);
	else if (dt->time_die < 0)
		return (0);
	else if (dt->time_eat < 0)
		return (0);
	else if (dt->time_sleep < 0)
		return (0);
	else if (dt->must_eat == -2)
		return (0);
	return (1);
}

int	ft_init_philo(t_philo *ph, t_data *dt)
{
	int	i;

	i = 0;
	while (i < dt->nb_philo)
	{
		ph[i].nb = i + 1;
		if (i == dt->nb_philo)
			ph[i].nb = 0;
		ph[i].last_meal = 0;
		ph[i].nb_meal = 0;
		ph[i].dt = dt;
		ph[i].lf = &dt->forks[i];
		ph[i].rf = 0;
		ph[i].eating = 0;
		i++;
	}
	return (1);
}

int	ft_init_mutex(t_data *dt)
{
	int	i;

	i = 0;
	while (i < dt->nb_philo)
		if (pthread_mutex_init(&dt->forks[i++], NULL) != 0)
			return (0);
	if (pthread_mutex_init(&dt->write, NULL) != 0)
		return (0);
	// if (pthread_mutex_init(&dt->meal_lock, NULL) != 0)
	// {
	// 	pthread_mutex_destroy(&dt->write_lock);
	// 	return (0);
	// }
	// if (pthread_mutex_init(&dt->death_lock, NULL) != 0)
	// {
	// 	pthread_mutex_destroy(&dt->write_lock);
	// 	pthread_mutex_destroy(&dt->meal_lock);
	// 	return (0);
	// }
	return (1);
}

int	ft_init_data(t_data *dt, char **argv, int argc)
{
	dt->dead = 0;
	dt->done = 0;
	dt->nb_philo = ft_atoli(argv[1]);
	dt->time_die = ft_atoli(argv[2]);
	dt->time_eat = ft_atoli(argv[3]);
	dt->time_sleep = ft_atoli(argv[4]);
	dt->must_eat = -1;
	if (argc == 6)
		dt->must_eat = ft_atoli(argv[5]);
	dt->forks = malloc((dt->nb_philo) * sizeof(pthread_mutex_t));
	if (!dt->forks)
		return (0);
	if (!ft_check_arg(dt))
		return (0);
	if (!ft_init_mutex(dt))
		return (0);
	return (1);
}
