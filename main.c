/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouzar <mobouzar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 14:46:40 by mobouzar          #+#    #+#             */
/*   Updated: 2019/07/03 01:26:32 by mobouzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		ft_manage_format(va_list list, t_format *f)
{
	if (f->specifier == 'c')
		ft_print_c(list, f);
	return (1);
}

int		ft_print_format(va_list list, const char *format, t_format *f)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (format[i])
	{
		if (format[i] != '%')
			ft_putchar(format[i]);
		else
		{
			j = ft_getformat(f, format + i);
			ft_manage_format(list, f);
			i += j;
		}
		i++;
	}
	return (1);
}

int		ft_printf(const char *format, ...)
{
	va_list		list;
	t_format	f;
	int			ret;

	va_start(list, format);
	ret = ft_print_format(list, format, &f);
	
	va_end(list);
	return (ret);
}

int	main(void)
{
	// char		*t;
	int		i;
	int		j;
	// int		a;
	// // int		b;
	// // int		c;
	// t_format f;

	// i = 0;
	// j = 0;
	// t = ft_strdup("%+#3535.10000X hhhh %.9p");
	// a = ft_getformat(&f, t);
	// j = 0;
	// while (j < 5)
	// {
	// 	printf("flag => |%c| \n", f.flag[j]);
	// 	j++;
	// 	if (f.flag[j] == '\0')
	// 		break ;
	// }
	// printf("width     => |%d| \n", f.width);
	// printf("precision => |%d| \n", f.precision);
	// printf("hh lenght m => |%d| \n", f.hh);
	// printf("h lenght m => |%d| \n", f.h);
	// printf("ll lenght m => |%d| \n", f.ll);
	// printf("l lenght m => |%d| \n", f.l);
	// printf("lenght => |%d|\n", a);

	printf("--------------------------------------------------\n");
	i = ft_printf("hello |%-5c| World! |%-3c| 55 |%-6c| ---- |%d| \n", 'h', 'j', 'l', 9);
	j = printf("hello |%-5c| World! |%-3c| 55 |%-6c| ---- |%d| \n", 'h', 'j', 'l', 9);
	// i = ft_printf("hello\nWorld!\n");
	// j = printf("hello\nWorld!\n");
	printf("mine => %d, sys => %d\n", i, j);
	// free(t);
	return (0);
}
