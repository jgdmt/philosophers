/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoudema <jgoudema@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:49:30 by jgoudema          #+#    #+#             */
/*   Updated: 2024/01/05 16:35:05 by jgoudema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static const char	*ft_space(const char *str)
{
	while (*str && (*str == ' ' || *str == '\t' || *str == '\n'
			|| *str == '\r' || *str == '\f' || *str == '\v'))
		str++;
	return (str);
}

int	ft_atoi(const char *str)
{
	long int	res;
	long int	prev;
	int			sign;

	res = 0;
	sign = 1;
	prev = 0;
	str = ft_space(str);
	if (*str && (*str == '+' || *str == '-'))
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str && *str <= 57 && *str >= 48)
	{
		res = (res * 10) + (*str - 48);
		if (prev > res && sign > 0)
			return (-1);
		else if (prev > res && sign < 0)
			return (0);
		str++;
		prev = res;
	}
	return (res * sign);
}

long int	ft_atoli(const char *str)
{
	long int	num;
	int			sign;
	int			i;

	num = 0;
	sign = 1;
	i = -1;
	if (str[++i] == '-')
		sign = -1;
	if (str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		num = (num * 10) + (str[i++] - 48);
	num = num * sign;
	return (num);
}
