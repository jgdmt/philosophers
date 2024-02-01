/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoudema <jgoudema@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:07:54 by jgoudema          #+#    #+#             */
/*   Updated: 2024/02/01 15:57:17 by jgoudema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_putstr(int out, char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		write(out, &str[i++], 1);
}

void	ft_write_message(t_philo *philo, char *str)
{
	// if (!philo->data->dead)
	printf("%lu %d %s\n", get_time() % philo->data->start, philo->nb, str);
}

void	ft_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->lf);
	ft_write_message(philo, FORK);
	pthread_mutex_lock(philo->rf);
	ft_write_message(philo, FORK);
	ft_write_message(philo, EAT);
	philo->last_meal = get_time();
	ft_usleep(philo->data->time_eat);
	pthread_mutex_unlock(philo->lf);
	pthread_mutex_unlock(philo->rf);
}

void	ft_think_sleep(t_philo *philo)
{
	ft_write_message(philo, THINK);
	ft_write_message(philo, SLEEP);
	ft_usleep(philo->data->time_sleep);
}

void	*ft_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *) arg;
	if (philo->nb % 2)
		ft_usleep(philo->data->time_eat * 0.9 + 1);
	while (!philo->data->dead)
	{
		ft_eat(philo);
		ft_think_sleep(philo);
		pthread_exit(NULL);
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_data	data;
	t_philo	*philo;

	if (argc == 5 || argc == 6)
	{
		if (!ft_init_data(&data, argv, argc))
		{
			ft_putstr(2, "Error\nInvalid argument.\n");
			return (1);
		}
		philo = malloc((data.nb_philo) * sizeof(t_philo));
		if (!philo)
			return (1);
		ft_init_philo(philo, &data);
		data.start = get_time();
		int i = 0;
		while (i < data.nb_philo)
		{
			philo[i].rf = philo[(i + 1) % data.nb_philo].lf;
			pthread_create(&philo[i].thread, NULL, ft_routine, &philo[i]);
			i++;
		}
		i = 0;
		while (i < data.nb_philo)
		{
			pthread_join(philo[i].thread, NULL);
			i++;
		}
	}
	else
		ft_putstr(2, "Error\nWrong number of arguments.\n");
	return (0);
}
