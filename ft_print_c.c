/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouzar <mobouzar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 22:04:15 by mobouzar          #+#    #+#             */
/*   Updated: 2019/07/03 01:15:22 by mobouzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	c_manage_options(t_format f, char c)
{
	int	i;

	if (ft_strchr(f.flag, '-'))
	{
		i = 1;
		ft_putchar(c);
		while (i++ <= f.width - 1)
			ft_putchar(' ');
	}
	else
	{
		i = 1;
		while (i++ <= f.width - 1)
			ft_putchar(' ');
		ft_putchar(c);
	}
}

// int		ft_print(va_list list, char *format, t_format *f)
// {
// 	char	c;
// 	int		i;
// 	int		j;

// 	i = 0;
// 	j = 0;
// 	c = (char)va_arg(list, int);
// 	while (format[i] && format[i] != '%')
// 		i++;
// 	while (j < i)
// 		ft_putchar(format[j++]);
// 	if (ft_strchr(format, '%') == NULL)
// 		return (ft_strlen(format));
// 	j = ft_getformat(f, format + i);
// 	f->specifier = format[j + i];
// 	c_manage_options(*f, c);
// 	ft_putstr(format + i + j + 1);
// 	if (f->width > 0)
// 		return (i + f->width + ft_strlen(format + j + i + 1));
// 	else
// 		return (i + f->width + ft_strlen(format + j + i));
// }

int		ft_print_c(va_list list, t_format *f)
{
	char	c;
	int		len;

	len = 0;
	c = (char)va_arg(list, int);
	c_manage_options(*f, c);
	len += f->width;
	return (len);
}

// int		ft_print_s(va_list list, char *format, t_format *f)
// {
// 	char	c;
// 	int		i;
// 	int		j;

// 	i = 0;
// 	j = 0;
// 	c = (char)va_arg(list, int);
// 	while (format[i] && format[i] != '%')
// 		i++;
// 	while (j < i)
// 		ft_putchar(format[j++]);
// 	return (1);
// }
