/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgolear <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 16:00:34 by dgolear           #+#    #+#             */
/*   Updated: 2017/03/18 13:42:59 by dgolear          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		g_len = 0;
int				g_fd = 1;

int		print_len(t_param *params, va_list ap, char letter)
{
	int		*pointer;

	if (params || letter)
		;
	pointer = va_arg(ap, int *);
	*pointer = g_len;
	return (0);
}

int		ft_printf(const char *format, ...)
{
	va_list ap;

	va_start(ap, format);
	return (ft_vdprintf(1, format, ap));
}

int		ft_dprintf(int fd, const char *format, ...)
{
	va_list		ap;

	va_start(ap, format);
	return (ft_vdprintf(fd, format, ap));
}

int		ft_vdprintf(int fd, const char *format, va_list ap)
{
	int		i;

	i = 0;
	g_len = 0;
	g_fd = fd;
	while (format[i])
	{
		if (format[i] == '{')
		{
			if (find_color(format, &i) == 1)
				continue;
		}
		if (format[i++] != '%')
		{
			ft_putchar_fd(format[i - 1], g_fd);
			g_len++;
		}
		else
			g_len += check(format, &i, ap);
	}
	va_end(ap);
	return (g_len);
}
