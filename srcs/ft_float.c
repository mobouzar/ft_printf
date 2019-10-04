/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mydevice <mydevice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 14:23:50 by mobouzar          #+#    #+#             */
/*   Updated: 2019/10/04 14:50:30 by mydevice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char		*ft_mantissa(t_data *lst)
{
	t_var	var;
	char	*tmp;
	int		i;

	i = 0;
	var.result = ft_strdup("0");
	while (++i < 64)
	{
		if ((lst->mantissa >> (63 - i)) & 1)
		{
			tmp = var.result;
			var.tmp = ft_power("5", i);
			var.result = ft_sum(var.result, var.tmp);
			ft_strdel(&tmp);
			ft_strdel(&(var.tmp));
		}
		if (i < 63)
			var.result = ft_strjoin_free((var.result), ft_strdup("0"));
	}
	return (var.result);
}

char		*ft_putstr_float(char *src, char *dst, char *tmp, t_init *lst)
{
	int		a;
	int		prs;

	prs = lst->precision;
	a = ft_strlen(dst);
	if (prs > 0 || (lst->flag & HASH) == HASH)
		if (!(src = ft_strjoin_free(src, ft_strdup("."))))
			return (0);
	if (!(src = ft_strjoin_free(src, ft_strdup(tmp))))
		return (0);
	if (prs >= 63 && ((a) < prs))
	{
		prs -= a;
		src = ft_strjoin_00(src, prs);
	}
	return (src);
}

char		*ft_get_vurgile(char *str, int e, int prs, t_init *lst)
{
	const int	i = ft_strlen(str) - 63;
	char		*tmp_2;
	char		*ret;

	if (i >= 0 && e >= 0)
	{
		tmp_2 = ft_strsub(str, 0, i);
		str = ft_safe(str, ft_strdup(&str[i]));
		ret = ft_rounding(tmp_2, str, lst, prs);
	}
	else
	{
		if (ft_strchr(str, '-'))
		{
			tmp_2 = ft_strdup("-0");
			str = ft_safe(str, ft_strdup(&str[1]));
		}
		else
			tmp_2 = ft_strdup("0");
		str = ft_strjoin_free(ft_strjoin_00(ft_strnew(0), ft_abs(i + e)), str);
		ret = ft_rounding(tmp_2, str, lst, prs);
	}
	ft_strdel(&str);
	return (ret);
}

char		*ft_exponent(t_data *list, int prs, t_init *lst)
{
	char	*str;
	char	*tmp;

	tmp = NULL;
	str = ft_mantissa(list);
	if (list->exp != 0)
		list->exp = list->exp - 16383;
	if (list->as & 1)
		str = ft_strjoin_free(ft_strdup("1"), (str));
	tmp = list->exp < 0 ? "5" : "2";
	tmp = ft_power(tmp, ft_abs(list->exp));
	str = ft_safe(str, ft_produit(str, tmp));
	ft_strdel(&tmp);
	if (list->sign & 1)
		str = ft_strjoin_free(ft_strdup("-"), str);
	str = ft_get_vurgile(str, list->exp, prs, lst);
	return (str);
}
