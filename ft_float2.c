/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouzar <mobouzar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 16:40:42 by mobouzar          #+#    #+#             */
/*   Updated: 2019/09/17 15:42:34 by mobouzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_check_helper(char **part_e, int prs)
{
	char	*str;

	str = ft_strdup(*part_e);
	if (prs == 0)
	{
		if (I(str[ft_strlen(str) - 1]) % 2 != 0)
			*part_e = ft_safe(*part_e, ft_sum(str, "1"));
	}
	else
	{
		if ((int)ft_strlen(*part_e) >= prs && I(*part_e[prs - 1]) % 2 != 0)
			*part_e = ft_safe(*part_e, ft_sum(*part_e, "1"));
	}
}

static void		ft_check_rounding(char **str, char **part_e, int prs)
{
	int		i;
	char	*dst;

	dst = *str;
	i = prs + 1;
	while ((dst[i] == '0') && dst[i])
		i++;
	if (i < 63)
		*part_e = ft_safe(*part_e, ft_sum(*part_e, "1"));
	else
		ft_check_helper(part_e, prs);
}

char			*ft_rounding(char *srcs, char *dst, t_init *lst, int prs)
{
	char	*tmp;
	char	*tmp_3;

	tmp = ft_strsub(dst, 0, prs);
	if ((I(dst[prs]) > 5) && (int)ft_strlen(dst) >= prs)
	{
		tmp_3 = tmp;
		if (prs > 0)
			tmp = ft_sum(tmp, "1");
		else
			return (ft_safe(tmp_3, ft_sum(srcs, "1")));
		ft_strdel(&tmp_3);
	}
	else if ((I(dst[prs]) == 5) && prs > 0)
		ft_check_rounding(&dst, &tmp, prs);
	else if ((I(dst[prs]) == 5) && prs == 0)
		ft_check_rounding(&dst, &srcs, prs);
	if ((int)ft_strlen(tmp) > prs && prs > 0)
	{
		tmp_3 = ft_strsub(tmp, 0, 1);
		srcs = ft_safe(tmp_3, ft_safe(srcs, ft_sum(srcs, tmp_3)));
		tmp = ft_safe(tmp, ft_strdup(&tmp[1]));
	}
	return (ft_safe(tmp, ft_putstr_float(srcs, dst, tmp, lst)));
}
