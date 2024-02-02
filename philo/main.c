/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoudema <jgoudema@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:07:54 by jgoudema          #+#    #+#             */
/*   Updated: 2024/02/02 15:16:42 by jgoudema         ###   ########.fr       */
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

void	ft_write_message(t_philo *ph, char *str)
{
	pthread_mutex_lock(&ph[0].dt->write);
	if (!ph[0].dt->dead)
		printf("%lu %d %s\n", get_time() % ph->dt->start, ph->nb, str);
	pthread_mutex_unlock(&ph[0].dt->write);
}

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
	if (ph->nb % 2)
		ft_usleep(ph->dt->time_eat * 0.5);
	while (!ph->dt->dead)
	{
		ft_eat(ph);
		ft_think_sleep(ph);
	}
	return (0);
}

void	*ft_monitor(void *arg)
{
	t_philo	*ph;
	t_data	*dt;
	int		tmp;
	int		i;

	ph = (t_philo *) arg;
	dt = ph[0].dt;
	while (!dt->dead)
	{
		i = 0;
		tmp = 0;
		if (dt->must_eat > -1)
			tmp = 2;
		while (i < dt->nb_philo)
		{
			if (get_time() - ph[i].last_meal > (size_t) dt->time_die)// && !ph[i].eating)
			{
				tmp = 1;
				ft_write_message(&ph[i], DIE);
				dt->dead = tmp;
				pthread_mutex_unlock(ph[i].rf);
				pthread_mutex_unlock(ph[i].lf);
				break ;
			}
			else if (dt->must_eat > -1 && ph[i].nb_meal < dt->must_eat)
				tmp = 0;
			i++;
		}
		dt->dead = tmp;
	}
	i = 0;
	while (i < dt->nb_philo)
		pthread_mutex_destroy(&dt->forks[i++]);
	free(dt->forks);
	return (NULL);
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
		dt.start = get_time();
		int i = 0;
		while (i < dt.nb_philo)
		{
			ph[i].rf = ph[(i + 1) % dt.nb_philo].lf;
			ph[i].last_meal = dt.start;
			pthread_create(&ph[i].thread, NULL, ft_routine, &ph[i]);
			i++;
		}
		pthread_create(&handler, NULL, ft_monitor, ph);
		dt.done = 1;
		i = 0;
		while (i < dt.nb_philo)
		{
			pthread_join(ph[i].thread, NULL);
			i++;
		}
	}
	else
		ft_putstr(2, "Error\nWrong number of arguments.\n");
	return (0);
}
