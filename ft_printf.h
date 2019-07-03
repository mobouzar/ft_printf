/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouzar <mobouzar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 21:51:14 by mobouzar          #+#    #+#             */
/*   Updated: 2019/07/03 01:18:27 by mobouzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>


typedef struct	s_format
{
	char		specifier;
	int			width;
	int			precision;
	char		flag[5];
	int			l;
	int			ll;
	int			h;
	int			hh;
}				t_format;

void	ft_init(t_format *f);
int		ft_flag(t_format *f, const char *format);
int		ft_width(t_format *f, const char *format, int i);
int		ft_precision(t_format *f, const char *format, int i);
void	ft_length_modifier(t_format *f, const char *format, int i);

int		ft_is_specifier(char c);
int		ft_getformat(t_format *f, const char *format);

int		ft_manage_format(va_list list, t_format *f);

//int		ft_print_c(va_list list, char *format, t_format *f);

int		ft_print_c(va_list list, t_format *f);

int		ft_printf(const char* format, ...);

#endif