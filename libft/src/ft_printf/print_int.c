/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgolear <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 16:48:26 by dgolear           #+#    #+#             */
/*   Updated: 2017/03/05 11:19:21 by dgolear          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static intmax_t	get_size(t_param *params, va_list ap, char letter)
{
	intmax_t	value;

	if (params->mod == z)
		value = (size_t)va_arg(ap, size_t);
	else if (params->mod == j)
		value = (intmax_t)va_arg(ap, intmax_t);
	else if (params->mod == ll)
		value = (long long)va_arg(ap, long long);
	else if (params->mod == l || letter == 'D')
		value = (long)va_arg(ap, long);
	else if (params->mod == no_length)
		value = (int)va_arg(ap, int);
	else if (params->mod == h)
		value = (short)va_arg(ap, int);
	else if (params->mod == hh)
		value = (char)va_arg(ap, int);
	else
		value = (int)va_arg(ap, int);
	return (value);
}

static int		print_width(intmax_t vl, t_param *ps)
{
	int		len;
	int		printed;
	int		width;

	printed = 0;
	if (!(vl == 0 && ps->precision == 0))
		len = ft_nbrlen(vl);
	else
		len = 0;
	if (ps->flags[2].sign && (vl < 0 || ps->flags[0].sign || ps->flags[5].sign))
		printed += print_sign(vl, ps);
	if (!ps->flags[2].sign && !ps->flags[1].sign
		&& (vl < 0 || ps->flags[0].sign || ps->flags[5].sign))
		ps->width--;
	width = ps->width;
	while (width > len && width > ps->precision)
	{
		if (ps->flags[2].sign)
			printed += ft_putstr_fd("0", g_fd);
		else
			printed += ft_putstr_fd(" ", g_fd);
		width--;
	}
	return (printed);
}

static int		print_precision(intmax_t val, t_param *params)
{
	int		printed;
	int		len;
	int		precision;

	precision = params->precision;
	len = ft_nbrlen(val);
	printed = 0;
	if ((params->flags[1].sign || !(params->flags[2].sign))
		&& (val < 0 || params->flags[0].sign || params->flags[5].sign))
		printed += print_sign(val, params);
	while (precision > len)
	{
		ft_putchar_fd('0', g_fd);
		printed++;
		precision--;
	}
	return (printed);
}

static int		print_value(intmax_t val, t_param *params)
{
	char		*s;
	int			printed;

	printed = 0;
	if (val < 0)
	{
		if (val == INTMAX_MIN)
			s = ft_strdup("9223372036854775808");
		else
			s = ft_itoa(-val);
	}
	else
		s = ft_itoa(val);
	while (s[printed])
	{
		ft_putchar_fd(s[printed++], g_fd);
		if (params->flags[4].sign && printed % 3 == 0)
			ft_putchar_fd(',', g_fd);
	}
	if (params->flags[4].sign)
		printed += printed / 4;
	ft_strdel(&s);
	return (printed);
}

int				print_int(t_param *params, va_list ap, char letter)
{
	int			printed;
	intmax_t	val;

	printed = 0;
	val = get_size(params, ap, letter);
	if (params->flags[1].sign)
	{
		printed += print_precision(val, params);
		if (!(val == 0 && params->precision == 0))
			printed += print_value(val, params);
		printed += print_width(val, params);
	}
	else
	{
		printed += print_width(val, params);
		printed += print_precision(val, params);
		if (!(val == 0 && params->precision == 0))
			printed += print_value(val, params);
	}
	return (printed);
}
