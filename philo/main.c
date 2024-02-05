/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoudema <jgoudema@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:07:54 by jgoudema          #+#    #+#             */
/*   Updated: 2024/02/05 19:01:50 by jgoudema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_start_thread(t_philo *ph)
{
	int		i;
	size_t	start;
	int		num;

	num = ph[0].dt->nb_philo;
	i = -1;
	while (++i < num)
	{
		ph[i].rf = ph[(i + 1) % num].lf;
		if (pthread_create(&ph[i].thread, NULL, ft_routine, &ph[i]))
		{
			destroy(ph[0].dt);
			free(ph);
			return (1);
		}
	}
	i = -1;
	start = get_time();
	ph[0].dt->start = start;
	while (++i < num)
		ph[i].last_meal = start;
	pthread_mutex_lock(&ph[0].dt->write);
	ph[0].dt->done = 1;
	pthread_mutex_unlock(&ph[0].dt->write);
	return (0);
}

int	ft_join_thread(t_philo *ph)
{
	int		i;
	int		num;
	t_data	*dt;

	num = ph[0].dt->nb_philo;
	i = -1;
	dt = ph[0].dt;
	while (++i < num)
	{
		if (pthread_join(ph[i].thread, NULL))
		{
			destroy(dt);
			free(ph);
			return (1);
		}
	}
	i = -1;
	while (++i < num)
		pthread_mutex_destroy(&dt->forks[i]);
	free(dt->forks);
	pthread_mutex_destroy(&dt->death);
	pthread_mutex_destroy(&dt->meal);
	pthread_mutex_destroy(&dt->write);
	free(ph);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_data		dt;
	t_philo		*ph;
	pthread_t	handler;

	if (argc == 5 || argc == 6)
	{
		if (!ft_init_data(&dt, argv, argc))
		{
			ft_putstr(2, "Error\nInvalid argument.\n");
			return (1);
		}
		ph = malloc((dt.nb_philo) * sizeof(t_philo));
		if (!ph)
			return (destroy(&dt), 1);
		ft_init_philo(ph, &dt);
		if (ft_start_thread(ph))
			return (1);
		pthread_create(&handler, NULL, ft_monitor, ph);
		if (ft_join_thread(ph))
			return (1);
		pthread_join(handler, NULL);
	}
	else
		ft_putstr(2, "Error\nWrong number of arguments.\n");
	return (0);
}
