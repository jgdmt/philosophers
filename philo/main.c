/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoudema <jgoudema@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:07:54 by jgoudema          #+#    #+#             */
/*   Updated: 2024/01/05 15:53:29 by jgoudema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		write(1, &str[i++], 1);
}

int	main(int argc, char *argv[])
{
	t_data	data;
	t_philo	philo;

	if (argc == 5 || argc == 6)
	{
		ft_init_data(&data, argv, argc);
		printf("%d, %d, %d, %d, %d\n", data.nb_philo, data.time_die, data.time_eat, data.time_sleep, data.must_eat);
	}
	else
		ft_putstr("Error\nWrong number of arguments.\n");
	return (0);
}
