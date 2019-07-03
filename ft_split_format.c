/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouzar <mobouzar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 20:20:47 by mobouzar          #+#    #+#             */
/*   Updated: 2019/07/03 01:14:01 by mobouzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		ft_is_specifier(char c)
{
	if (c == 'c')
		return (1);
	if (c == 's')
		return (1);
	if (c == 'p')
		return (1);
	if (c == 'd')
		return (1);
	if (c == 'i')
		return (1);
	if (c == 'o')
		return (1);
	if (c == 'u')
		return (1);
	if (c == 'x')
		return (1);
	if (c == 'X')
		return (1);
	if (c == 'f')
		return (1);
	return (0);
}

int		ft_getformat(t_format *f, const char *format)
{
	int i;
	int	a;
	int	b;
	int	c;

	i = 0;
	while (format[i])
	{
		if (ft_is_specifier(format[i]))
		{
			f->specifier = format[i];
			break ;
		}
		i++;
	}
	ft_init(f);
	a = ft_flag(f, format);
	b = ft_width(f, format, a);
	c = ft_precision(f, format, b);
	ft_length_modifier(f, format, c);
	return (i);
}
