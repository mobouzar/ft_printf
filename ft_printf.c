/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouzar <mobouzar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 14:46:40 by mobouzar          #+#    #+#             */
/*   Updated: 2019/09/16 23:13:27 by mobouzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_init(t_init *lst)
{
	lst->precision = -1;
	lst->flag = 0;
	lst->width = -1;
	lst->specifier = '\0';
}

int		ft_manage_format(va_list list, t_init *lst)
{
	int	ret;

	ret = 0;
	if (lst->specifier == 'd' || lst->specifier == 'i')
		ret += ft_print_d(list, lst);
	else if (lst->specifier == 'o' || lst->specifier == 'x'
	|| lst->specifier == 'X' || lst->specifier == 'u' || lst->specifier == 'p')
		ret += ft_print_base(list, lst);
	else if (lst->specifier == 's')
		ret += ft_print_s(list, lst);
	else if (lst->specifier == 'c')
		ret += ft_print_c(list, lst);
	else if (lst->specifier == 'f')
		ret += ft_print_f(list, lst);
	else
	{
		if ((lst->flag & SPACE) == SPACE)
			lst->flag ^= SPACE;
		if ((lst->flag & PLUS) == PLUS)
			lst->flag ^= PLUS;
		ret += ft_print_persent(lst);
	}
	return (ret);
}

int		ft_print_format(va_list list, const char *format, t_init *f)
{
	int		i;
	int		j;
	int		ret;

	i = 0;
	j = 0;
	ret = 0;
	while (format[i])
	{
		if (format[i] != '%')
			ret += ft_char_nbr(format[i]);
		else if (format[i] == '%' && format[i + 1] != '\0')
		{
			j = ft_get_flag_of_format(f, format + i);
			ret += ft_manage_format(list, f);
			i += j;
		}
		i++;
	}
	return (ret);
}

int		ft_printf(const char *format, ...)
{
	va_list		list;
	t_init		lst;
	int			ret;

	va_start(list, format);
	ret = ft_print_format(list, format, &lst);
	va_end(list);
	return (ret);
}
