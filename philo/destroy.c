/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoudema <jgoudema@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 09:11:44 by jgoudema          #+#    #+#             */
/*   Updated: 2024/02/05 19:01:35 by jgoudema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	destroy(t_data *dt)
{
	int	i;

	i = 0;
	while (i < dt->nb_philo)
	{
		pthread_mutex_destroy(&dt->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&dt->write);
	pthread_mutex_destroy(&dt->death);
	pthread_mutex_destroy(&dt->meal);
	free(dt->forks);
}
