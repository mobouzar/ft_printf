/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mydevice <mydevice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 01:35:10 by mobouzar          #+#    #+#             */
/*   Updated: 2019/10/04 14:48:24 by mydevice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_print_d(va_list list, t_init *lst)
{
	long long int	nbr;
	char			*str;
	char			*tmp;
	int				len;

	len = 0;
	if ((lst->flag & LL) == LL)
		nbr = va_arg(list, long long int);
	else if ((lst->flag & LONG) == LONG)
		nbr = va_arg(list, long int);
	else if ((lst->flag & HH) == HH)
		nbr = (char)va_arg(list, int);
	else if ((lst->flag & H) == H)
		nbr = (short)va_arg(list, int);
	else
		nbr = va_arg(list, int);
	str = ft_itoa(nbr);
	tmp = str;
	str = ft_manage_width(lst, str);
	len += ft_str_nbr(str);
	ft_strdel(&tmp);
	ft_strdel(&str);
	return (len);
}
