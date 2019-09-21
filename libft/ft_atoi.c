/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouzar <mobouzar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 06:31:31 by mobouzar          #+#    #+#             */
/*   Updated: 2019/08/08 20:18:13 by mobouzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int				multiplier;
	long long int	total;

	multiplier = 1;
	total = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\f' ||
			*str == '\r' || *str == '\v')
		str++;
	if (str[0] == '-')
	{
		multiplier = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		total = (total * 10) + *str - '0';
		str++;
	}
	if (total > 2147483647)
		return (-1);
	return (total * multiplier);
}
