/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouzar <mobouzar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 17:41:24 by mobouzar          #+#    #+#             */
/*   Updated: 2019/07/03 01:14:07 by mobouzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	ft_init(t_format *f)
{
	f->flag[0] = '\0';
	f->width = 0;
	f->precision = -1;
	f->l = -1;
	f->ll = -1;
	f->h = -1;
	f->hh = -1;
}

int		ft_flag(t_format *f, const char *format)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (ft_strchr("#0+- ", format[++i]) && j < 5)
	{
		if (format[i] != f->flag[j - 1])
			f->flag[j++] = format[i];
	}
	f->flag[j] = '\0';
	return (i);
}

int		ft_width(t_format *f, const char *format, int i)
{
	int	j;

	j = i;
	while (format[j] >= '0' && format[j] <= '9')
		j++;
	f->width = ft_atoi(format + i);
	return (j);
}

int		ft_precision(t_format *f, const char *format, int i)
{
	int		j;
	char	*temp;

	j = i + 1;
	if (format[i] == '.')
		while (format[j] >= '0' && format[j] <= '9')
			j++;
	temp = ft_strsub(format, i + 1, j);
	f->precision = ft_atoi(temp);
	free(temp);
	return (j);
}

void	ft_length_modifier(t_format *f, const char *format, int i)
{
	char	*length_mo;

	length_mo = ft_strsub(format, i, ft_strlen(format) - i - 1);
	if (!ft_strcmp(length_mo, "hh"))
		f->hh = 1;
	if (!ft_strcmp(length_mo, "h"))
		f->h = 1;
	if (!ft_strcmp(length_mo, "ll"))
		f->ll = 1;
	if (!ft_strcmp(length_mo, "l"))
		f->l = 1;
	free(length_mo);
}

/*
void 	split_format(t_format *f , char *str)
{
	int	i;
	int j;
	int	k;

	init(f);
	i = -1;
	j = -1;
	k = -1;
	while (str[++i])
	{
		if (ft_strchr("-+# ", str[i]))
			f->flag[++j] = str[i];
		if (f->flag[++k] )
		if (str[i] == '.')
		{
			f->precision = 1;
			while (str[i + f->precision] >= '0' && str[i + f->precision] <= '9')
				f->precision++;
			f->precision = ft_atoi(ft_strsub(str, i + 1, f->precision));
		}
	}
	f->specifier = str[i - 1];
}*/

/*int		ft_printf(char *format, ...)
{
	va_list		list;
	t_format	f;
	int			i;
	int			j;

	j = -1;
	i = 0;
	va_start(list, format);
	while (format[i])
	{
		if (format[i] != '%')
			ft_putchar(format[i]);
		else if (format[i] == '%')
		{
			j = i + 1;
			while (!ft_strchr("cspdiouxX", format[j]))
				j++;
			//split_format(&f,ft_strsub(format, i, j));

			if (ft_strchr(format + i, '-'))
				f.flag[0] = '-';
			printf("\tflag => %c", f.flag[0]);
			f.width = i + 1;
			while (format[i + 1] >= '0' && format[i + 1] <= '9' && format[i])
				i++;
			printf("\twidth => %d, i => %d", f.width, i);
			f.width = ft_atoi(ft_strsub(format, f.width, i));
			if (f.width < 0)
				f.width *= -1;
			printf("\twhidt => %d", f.width);
			while (!ft_strchr(f.specifier, format[i]))
				i++;
			if (format[i] == 'c')
				ft_print_c(list);
		}
		i++;
	}
	va_end(list);
	return (0);
}*/
