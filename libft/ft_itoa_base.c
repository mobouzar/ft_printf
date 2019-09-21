/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouzar <mobouzar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 22:10:43 by mobouzar          #+#    #+#             */
/*   Updated: 2019/08/09 16:32:04 by mobouzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int		ft_count(unsigned long long int value, int base)
{
	int		i;

	i = 1;
	while (value /= base)
		i++;
	return (i);
}

char	*ft_itoa_base(unsigned long long int value, int base)
{
	char		*str;
	const char	tab[16] = "0123456789abcdef";
	int			len;
	int			result;

	result = 0;
	len = ft_count(value, base);
	if (!(str = ft_strnew(len)))
		return (NULL);
	while (len--)
	{
		result = value % base;
		str[len] = tab[result];
		value /= base;
	}
	return (str);
}
