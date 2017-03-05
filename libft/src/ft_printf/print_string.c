/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgolear <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 16:30:18 by dgolear           #+#    #+#             */
/*   Updated: 2017/03/05 11:02:02 by dgolear          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	min(int a, int b)
{
	if (a > b)
		return (b);
	return (a);
}

static int	print_width(char *s, t_param *params)
{
	int		printed;
	int		len;
	int		width;

	width = params->width;
	len = ft_strlen(s);
	if (params->precision != NO_PRECISION)
		len = min(len, params->precision);
	if (len == 0 && width == 1)
		width = 0;
	printed = 0;
	while (width > len)
	{
		if (params->flags[2].sign)
			ft_putchar_fd('0', g_fd);
		else
			ft_putchar_fd(' ', g_fd);
		width--;
		printed++;
	}
	return (printed);
}

static int	print_s(t_param *params, char *s)
{
	int		printed;

	printed = 0;
	if (params->precision == NO_PRECISION)
		printed += ft_putstr_fd(s, g_fd);
	else
		printed += ft_putnstr_fd(s, params->precision, g_fd);
	return (printed);
}

int			print_string(t_param *params, va_list ap, char letter)
{
	char	*s;
	int		printed;

	if (params->mod == l)
		return (print_wstring(params, ap, letter));
	s = NULL;
	printed = 0;
	if ((s = va_arg(ap, char *)) == NULL)
		s = "(null)";
	if (params->flags[1].sign == 0)
		printed += print_width(s, params);
	printed += print_s(params, s);
	if (params->flags[1].sign != 0)
		printed += print_width(s, params);
	return (printed);
}
