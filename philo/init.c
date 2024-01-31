/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoudema <jgoudema@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:15:34 by jgoudema          #+#    #+#             */
/*   Updated: 2024/01/31 15:41:42 by jgoudema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// void	ft_clean(t_data *data)
// {
// 	int	i;

// 	i = 0;

// }

static int	ft_check_arg(t_data *data)
{
	if (data->nb_philo < 0)
		return (0);
	else if (data->time_die < 0)
		return (0);
	else if (data->time_eat < 0)
		return (0);
	else if (data->time_sleep < 0)
		return (0);
	else if (data->must_eat == -2)
		return (0);
	return (1);
}

void	ft_init_philo(t_data *data)
{
	int	i;

	i = 0;
	while (i <= data->nb_philo)
	{
		data->philo[i].nb = i + 1;
		if (i == data->nb_philo)
			data->philo[i].nb = 0;
		data->philo[i].last_meal = 0;
		data->philo[i].nb_meal = 0;
		data->philo[i].thread = 0;
		// pthread_create(&data->philo[i].thread, NULL, routine, data);
		i++;
	}
}

int	ft_init_data(t_data *data, char **argv, int argc)
{
	data->dead = 0;
	data->nb_philo = ft_atoli(argv[1]);
	data->time_die = ft_atoli(argv[2]);
	data->time_eat = ft_atoli(argv[3]);
	data->time_sleep = ft_atoli(argv[4]);
	data->must_eat = -1;
	if (argc == 6)
		data->must_eat = ft_atoli(argv[5]);
	if (!ft_check_arg(data))
		return (0);
	data->philo = malloc((data->nb_philo + 1) * sizeof(t_philo));
	if (!data->philo)
		return (0);
	ft_init_philo(data);
	return (1);
}

int	ft_init_mutex(t_data *data)
{
	if (pthread_mutex_init(&data->write_lock, NULL) != 0)
		return (0);
	if (pthread_mutex_init(&data->meal_lock, NULL) != 0)
	{
		pthread_mutex_destroy(&data->write_lock);
		return (0);
	}
	if (pthread_mutex_init(&data->death_lock, NULL) != 0)
	{
		pthread_mutex_destroy(&data->write_lock);
		pthread_mutex_destroy(&data->meal_lock);
		return (0);
	}
	return (1);
}
