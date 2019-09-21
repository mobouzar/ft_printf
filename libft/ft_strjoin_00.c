/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_00.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouzar <mobouzar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 15:03:36 by mobouzar          #+#    #+#             */
/*   Updated: 2019/09/17 15:05:28 by mobouzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_00(char *dst, int i)
{
	char *str;

	str = ft_strdup(dst);
	while (i > 0)
	{
		str = ft_strjoin_free(str, ft_strdup("0"));
		i--;
	}
	ft_strdel(&dst);
	return (str);
}
