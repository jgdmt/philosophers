/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoudema <jgoudema@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 11:39:04 by jgoudema          #+#    #+#             */
/*   Updated: 2024/02/04 16:07:47 by jgoudema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long int	ft_atoli(const char *str)
{
	long int	num;
	int			i;

	num = 0;
	i = 0;
	if (str[i] == '-')
		return (-2);
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + (str[i++] - 48);
		if (i > 11)
			return (-2);
	}
	if (str[i] != 0 || num > 2147483647)
		return (-2);
	return (num);
}

size_t	get_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		ft_putstr(2, "Error\ngettimeofday() error.\n");
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	ft_usleep(size_t msec)
{
	size_t	start;

	start = get_time();
	while ((get_time() - start) < msec)
		usleep(500);
}

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
		printf("%lu %d %s\n", get_time() - ph[0].dt->start, ph->nb, str);
	pthread_mutex_unlock(&ph[0].dt->write);
}
