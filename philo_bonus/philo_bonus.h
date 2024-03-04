/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoudema <jgoudema@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 17:13:32 by jgoudema          #+#    #+#             */
/*   Updated: 2024/03/04 13:58:55 by jgoudema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <pthread.h>
# include <semaphore.h>

# define FORK "has taken a fork"
# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define DIE "died"

typedef struct s_data
{
	int				dead;
	int				done;
	int				nb_philo;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				must_eat;
	size_t			start;
}	t_data;

typedef struct s_philo
{
	pthread_t		thread;
	int				nb;
	size_t			last_meal;
	int				nb_meal;
	t_data			*dt;
}	t_philo;

int			ft_init_data(t_data *dt, char **argv, int argc);

void		ft_putstr(int out, char *str);
long int	ft_atoli(const char *str);

#endif