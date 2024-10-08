/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoudema <jgoudema@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:07:48 by jgoudema          #+#    #+#             */
/*   Updated: 2024/02/05 19:02:09 by jgoudema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

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
	pthread_mutex_t	*forks;
	pthread_mutex_t	write;
	pthread_mutex_t	death;
	pthread_mutex_t	meal;
}	t_data;

typedef struct s_philo
{
	pthread_t		thread;
	int				nb;
	size_t			last_meal;
	int				nb_meal;
	pthread_mutex_t	*rf;
	pthread_mutex_t	*lf;
	t_data			*dt;
}	t_philo;

int			ft_init_data(t_data *dt, char **argv, int argc);
void		ft_init_philo(t_philo *philo, t_data *dt);
void		destroy(t_data *dt);

void		*ft_monitor(void *arg);
void		*ft_routine(void *arg);
int			ft_is_dead(t_data *dt);

long int	ft_atoli(const char *str);
void		ft_putstr(int out, char *str);
void		ft_write_message(t_philo *ph, char *str);
size_t		get_time(void);
void		ft_usleep(size_t msec);

#endif