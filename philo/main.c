/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoudema <jgoudema@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:07:54 by jgoudema          #+#    #+#             */
/*   Updated: 2024/02/04 16:09:30 by jgoudema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_start_thread(t_philo *ph)
{
	int		i;
	size_t	start;
	int		num;

	num = ph[0].dt->nb_philo;
	i = -1;
	while (++i < num)
	{
		ph[i].rf = ph[(i + 1) % num].lf;
		pthread_create(&ph[i].thread, NULL, ft_routine, &ph[i]);
	}
	i = -1;
	start = get_time();
	ph[0].dt->start = start;
	while (++i < num)
	{
		ph[i].last_meal = start;
	}
	ph[0].dt->done = 1;
}

void	ft_join_thread(t_philo *ph)
{
	int		i;
	int		num;
	t_data	*dt;

	num = ph[0].dt->nb_philo;
	i = -1;
	dt = ph[0].dt;
	while (++i < num)
		pthread_join(ph[i].thread, NULL);
	i = -1;
	while (++i < num)
		pthread_mutex_destroy(&dt->forks[i]);
	free(dt->forks);
	pthread_mutex_destroy(&dt->write);
	free(ph);
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
			return (1);
		ft_init_philo(ph, &dt);
		ft_start_thread(ph);
		pthread_create(&handler, NULL, ft_monitor, ph);
		ft_join_thread(ph);
		pthread_join(handler, NULL);
	}
	else
		ft_putstr(2, "Error\nWrong number of arguments.\n");
	return (0);
}
