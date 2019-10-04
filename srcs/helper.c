/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mydevice <mydevice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 17:01:28 by mobouzar          #+#    #+#             */
/*   Updated: 2019/10/04 14:47:07 by mydevice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static char		*ft_prefix(t_init *lst, char *str, char *sign)
{
	if (str[0] == '0' && str[1] == 'x')
	{
		sign[0] = '0';
		sign[1] = 'x';
		str += 2;
	}
	if (str[0] == '0' && str[1] == 'X')
	{
		sign[0] = '0';
		sign[1] = 'X';
		str += 2;
	}
	if ((str[0] != '0' && ((lst->flag & HASH) == HASH)
	&& lst->specifier == 'x') || lst->specifier == 'p')
	{
		sign[0] = '0';
		sign[1] = 'x';
	}
	if (str[0] != '0' && ((lst->flag & HASH) == HASH) && lst->specifier == 'X')
	{
		sign[0] = '0';
		sign[1] = 'X';
	}
	return (str);
}

char			*ft_check(t_init *lst, char *str, char **tmp)
{
	char *sign;
	char *new;

	sign = *tmp;
	new = ft_strdup(str);
	if (*str == '-')
	{
		*sign = '-';
		str++;
	}
	if (*str == '+')
	{
		*sign = '+';
		str++;
	}
	if (*str == ' ')
	{
		*sign = ' ';
		str++;
	}
	str = ft_prefix(lst, str, sign);
	ft_strdel(&new);
	return (str);
}

char			*ft_push_c(char *str, int i, char *c, int ps)
{
	char	*ptr;

	ptr = ft_strdup(str);
	while (i > 0)
	{
		if (ps == 1)
			ptr = ft_strjoin_free(ft_strdup(c), ptr);
		else if (ps == 0)
			ptr = ft_strjoin_free(ptr, ft_strdup(c));
		i--;
	}
	return (ptr);
}
