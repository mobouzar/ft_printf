/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_f.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouzar <mobouzar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 16:53:23 by mobouzar          #+#    #+#             */
/*   Updated: 2019/09/17 15:25:59 by mobouzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*indefined_form(long double nbr)
{
	if (nbr == (1.0 / 0.0))
		return (ft_strdup("inf"));
	if (nbr == (-1.0 / 0.0))
		return (ft_strdup("-inf"));
	if (nbr != nbr)
		return (ft_strdup("nan"));
	return (ft_strdup(""));
}

int		ft_print_f(va_list list, t_init *lst)
{
	t_float		init;
	char		*str;
	double		k;

	str = NULL;
	init.f = 0.0;
	init.list.exp = 0.0;
	init.list.mantissa = 0.0;
	if ((lst->flag & L_D) == L_D)
		init.f = (long double)va_arg(list, long double);
	else
		init.f = va_arg(list, double);
	if ((init.f == 1.0 / 0.0) || (init.f == -1.0 / 0.0) || (init.f != init.f))
		str = indefined_form(init.f);
	else
		str = ft_exponent(&init.list, lst->precision, lst);
	str = ft_safe(str, ft_manage_width(lst, str));
	k = ft_str_nbr(str);
	ft_strdel(&str);
	return ((int)k);
}
