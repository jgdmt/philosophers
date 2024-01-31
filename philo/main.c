/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoudema <jgoudema@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:07:54 by jgoudema          #+#    #+#             */
/*   Updated: 2024/01/31 13:36:54 by jgoudema         ###   ########.fr       */
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

// void	ft_write_message(t_philo philo, char *str)
// {
// 	printf("%d %d %s\n", time, philo.nb, str);
// }

void	*thread_1(void *arg)
{
	(void) arg;
	printf("Philo is eating\n");
	pthread_exit(EXIT_SUCCESS);
}

int	ft_start(t_data *data)
{
	while (!data->dead)
	{
		return (0);
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	// pthread_t thread1;

	// printf("Before\n");
	// pthread_create(&thread1, NULL, thread_1, NULL);
	// pthread_join(thread1, NULL);
	// printf("After\n");

	t_data	data;

	if (argc == 5 || argc == 6)
	{
			if (!ft_init_data(&data, argv, argc))
			{
				ft_putstr(2, "Error\nInvalid argument.\n");
				return (1);
			}
		printf("%d, %d, %d, %d, %d\n", data.nb_philo, data.time_die, data.time_eat, data.time_sleep, data.must_eat);
		int i=0;
		while (data.philo[i].nb > 0)
			printf("ID %d\n", data.philo[i++].nb);
		// ft_start(&data);
	}
	else
		ft_putstr(2, "Error\nWrong number of arguments.\n");
	return (0);
}
