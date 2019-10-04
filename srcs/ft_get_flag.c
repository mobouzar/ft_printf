/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_flag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mydevice <mydevice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 19:41:51 by mobouzar          #+#    #+#             */
/*   Updated: 2019/10/04 14:46:20 by mydevice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int		ft_flag(t_init *lst, const char *format)
{
	int	i;

	i = 0;
	while (format[++i] && ft_strchr("0#+- ", format[i]))
		if (format[i] == '0' && ((lst->flag & MINUS) != MINUS))
			lst->flag |= ZERO;
		else if (format[i] == '#')
			lst->flag |= HASH;
		else if (format[i] == ' ' && ((lst->flag & PLUS) != PLUS))
			lst->flag |= SPACE;
		else if (format[i] == '+')
		{
			if ((lst->flag & SPACE) == SPACE)
				lst->flag ^= SPACE;
			lst->flag |= PLUS;
		}
		else if (format[i] == '-')
		{
			if ((lst->flag & ZERO) == ZERO)
				lst->flag ^= ZERO;
			lst->flag |= MINUS;
		}
	return (i);
}

static int		ft_width(t_init *lst, const char *format, int i)
{
	int	j;

	j = i;
	while (format[j] >= '0' && format[j] <= '9')
		j++;
	lst->width = ft_atoi(format + i);
	return (j);
}

static int		ft_precision(t_init *lst, const char *format, int i)
{
	int		j;
	char	*tmp;

	j = i;
	if (format[i] == '.')
	{
		j++;
		while (format[j] >= '0' && format[j] <= '9')
			j++;
		tmp = ft_strsub(format, i + 1, j);
		lst->precision = ft_atoi(tmp);
		free(tmp);
		if ((lst->flag & ZERO) == ZERO && lst->specifier != 'f')
			lst->flag ^= ZERO;
	}
	if (lst->specifier == 'f' && lst->precision < 0)
		lst->precision = 6;
	return (j);
}

static void		ft_modifier(t_init *lst, const char *format, int i)
{
	while (ft_strchr("lhL", format[i]))
	{
		if (format[i] == 'l' && format[i + 1] == 'l')
			lst->flag |= LL;
		if (format[i] == 'l' && format[i + 1] != 'l')
			lst->flag |= LONG;
		if (format[i] == 'h' && format[i + 1] == 'h')
			lst->flag |= HH;
		if (format[i] == 'h' && format[i + 1] != 'h')
			lst->flag |= H;
		if (format[i] == 'L')
			lst->flag |= L_D;
		i++;
	}
}

int				ft_get_flag_of_format(t_init *lst, const char *format)
{
	int i;
	int	a;

	i = 1;
	ft_init(lst);
	while (format[i])
	{
		if (!ft_strchr("0-+#.hlL ", format[i])
		&& !(format[i] >= '0' && format[i] <= '9'))
		{
			lst->specifier = format[i];
			break ;
		}
		i++;
	}
	a = ft_flag(lst, format);
	a = ft_width(lst, format, a);
	a = ft_precision(lst, format, a);
	ft_modifier(lst, format, a);
	return (i);
}
