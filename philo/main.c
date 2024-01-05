/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoudema <jgoudema@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:07:54 by jgoudema          #+#    #+#             */
/*   Updated: 2024/01/05 15:08:10 by jgoudema         ###   ########.fr       */
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

int	ft_check_args(char **str)
{
	(void) str;
	return (0);
}

int	main(int argc, char *argv[])
{
	
	if (argc == 3 || argc == 4)
	{
		ft_check_args(argv);
	}
	else
		ft_putstr("Error\nWrong number of arguments.\n");
	return (0);
}
