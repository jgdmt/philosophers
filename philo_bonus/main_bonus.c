/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoudema <jgoudema@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 17:12:52 by jgoudema          #+#    #+#             */
/*   Updated: 2024/03/04 13:58:06 by jgoudema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int argc, char *argv[])
{
	t_data	dt;

	if (argc == 5 || argc == 6)
	{
		if (!ft_init_data(&dt, argv, argc))
		{
			ft_putstr(2, "Error\nInvalid argument.\n");
			return (1);
		}
	}
	else
		ft_putstr(2, "Error\nWrong number of arguments.\n");
	return (0);
}