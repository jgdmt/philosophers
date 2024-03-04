/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoudema <jgoudema@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 13:53:05 by jgoudema          #+#    #+#             */
/*   Updated: 2024/03/04 13:57:47 by jgoudema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static int	ft_check_arg(t_data *dt)
{
	if (dt->nb_philo <= 0 || dt->nb_philo > 200)
		return (0);
	else if (dt->time_die < 60)
		return (0);
	else if (dt->time_eat < 60)
		return (0);
	else if (dt->time_sleep < 60)
		return (0);
	else if (dt->must_eat == -2 || dt->must_eat == 0)
		return (0);
	return (1);
}

int	ft_init_data(t_data *dt, char **argv, int argc)
{
	dt->dead = 0;
	dt->done = 0;
	dt->start = 0;
	dt->nb_philo = ft_atoli(argv[1]);
	dt->time_die = ft_atoli(argv[2]);
	dt->time_eat = ft_atoli(argv[3]);
	dt->time_sleep = ft_atoli(argv[4]);
	dt->must_eat = -1;
	if (argc == 6)
		dt->must_eat = ft_atoli(argv[5]);
	if (!ft_check_arg(dt))
		return (0);
	return (1);
}
