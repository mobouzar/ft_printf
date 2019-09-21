/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouzar <mobouzar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 23:08:04 by mobouzar          #+#    #+#             */
/*   Updated: 2019/09/17 16:59:23 by mobouzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_join_char(t_init *lst, char *str, int i)
{
	char		*tmp;
	char		*sign;

	if (ft_strstr(str, "nan"))
		return ((ft_strdup(str)));
	if (!(sign = ft_strnew(3)))
		return (0);
	tmp = NULL;
	tmp = str;
	str = ft_check(lst, str, &sign);
	if ((lst->flag & PLUS) == PLUS && tmp[0] != '-' && lst->specifier != 'u')
		*sign = '+';
	else if ((lst->flag & SPACE) == SPACE && tmp[0] != '-' &&
	tmp[0] != '+' && lst->specifier != 'u')
		*sign = ' ';
	if (((lst->flag & PLUS) == PLUS) && tmp[0] != '-' && tmp[0] != '+')
		i--;
	str = ft_push_c(str, i, "0", 1);
	if (*sign != '\0')
		str = ft_strjoin_free(ft_strdup(sign), str);
	ft_strdel(&sign);
	return (str);
}

static char		*ft_precision_helper(t_init *lst, char *str, int str_len)
{
	int i;

	i = -1;
	if (lst->precision >= str_len && (lst->specifier != 'f'))
		if ((lst->flag & PLUS) == PLUS || str[0] == '-')
			i = lst->precision - str_len + 1;
		else
			i = lst->precision - str_len;
	else if (lst->precision < str_len && lst->specifier == 's')
		str = ft_safe(str, ft_strsub(str, 0, lst->precision));
	str = ft_join_char(lst, str, i);
	return (str);
}

static char		*ft_manage_precision(t_init *lst, char *str)
{
	const int	str_len = ft_strlen(str);
	char		*tmp;
	int			i;

	i = -1;
	tmp = NULL;
	if (lst->precision == 0 && *str == '0' && lst->specifier != 'f')
	{
		str = ft_strdup("");
		tmp = str;
	}
	if ((lst->specifier == 'x' || lst->specifier == 'X'
	|| lst->specifier == 'u') && str[0] == '\0')
		return (str);
	str = ft_precision_helper(lst, str, str_len);
	if (lst->specifier == 'o' && (lst->flag & HASH) == HASH && str[0] != '0')
		str = ft_safe(str, ft_push_c(str, 1, "0", 1));
	ft_strdel(&tmp);
	return (str);
}

char			*ft_manage_width(t_init *lst, char *s)
{
	int			str_len;
	char		*str;
	int			i;

	i = 0;
	if (!(str = ft_strdup(s)))
		return (0);
	str = ft_safe(str, ft_manage_precision(lst, str));
	str_len = ft_strlen(str);
	if (lst->width > str_len)
	{
		if ((lst->flag & MINUS) == MINUS)
			str = ft_safe(str, ft_push_c(str, lst->width - str_len, " ", 0));
		else if ((lst->flag & ZERO) == ZERO && !ft_strstr(str, "inf")
		&& !ft_strstr(str, "nan"))
			str = ft_safe(str, ft_join_char(lst, str, lst->width - str_len));
		else
			str = ft_safe(str, ft_push_c(str, lst->width - str_len, " ", 1));
	}
	return (str);
}
