/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mydevice <mydevice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 04:18:22 by mobouzar          #+#    #+#             */
/*   Updated: 2019/10/04 14:46:39 by mydevice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static char		*add(char **tmp, char *str)
{
	if (str != NULL)
		*tmp = str;
	else
		*tmp = NULL;
	return (str);
}

static int		ft_print(t_init *lst, unsigned long long int nbr)
{
	int		len;
	char	*str;
	char	*tmp;

	len = 0;
	str = NULL;
	if (lst->specifier == 'o')
		str = add(&tmp, ft_itoa_base(nbr, 8));
	else if (lst->specifier == 'x' || lst->specifier == 'p')
		str = add(&tmp, ft_itoa_base(nbr, 16));
	else if (lst->specifier == 'X')
	{
		str = add(&tmp, ft_itoa_base(nbr, 16));
		str = ft_str_toupper(str);
	}
	else if (lst->specifier == 'u')
		str = add(&tmp, ft_itoa_base(nbr, 10));
	str = ft_manage_width(lst, str);
	len += ft_str_nbr(str);
	ft_strdel(&tmp);
	free(str);
	return (len);
}

int				ft_print_base(va_list list, t_init *lst)
{
	unsigned long long int	nbr;
	int						len;

	len = 0;
	if ((lst->flag & LL) == LL || lst->specifier == 'p')
		nbr = va_arg(list, unsigned long long int);
	else if ((lst->flag & LONG) == LONG)
		nbr = va_arg(list, unsigned long int);
	else if ((lst->flag & HH) == HH)
		nbr = (unsigned char)va_arg(list, int);
	else if ((lst->flag & H) == H)
		nbr = (unsigned short)va_arg(list, int);
	else
		nbr = va_arg(list, unsigned int);
	len = ft_print(lst, nbr);
	return (len);
}
