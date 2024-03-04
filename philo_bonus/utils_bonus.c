/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoudema <jgoudema@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 17:23:37 by jgoudema          #+#    #+#             */
/*   Updated: 2024/03/04 13:58:21 by jgoudema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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

void	ft_putstr(int out, char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		write(out, &str[i++], 1);
}
