/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgolear <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 12:48:32 by dgolear           #+#    #+#             */
/*   Updated: 2017/03/05 11:06:48 by dgolear          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static uintmax_t	get_size(t_param *params, va_list ap, char letter)
{
	uintmax_t	value;

	if (params->mod == j)
		value = (uintmax_t)va_arg(ap, uintmax_t);
	else if (params->mod == ll)
		value = (unsigned long long)va_arg(ap, unsigned long long);
	else if (params->mod == l || letter == 'O' || letter == 'U')
		value = (unsigned long)va_arg(ap, unsigned long);
	else if (params->mod == z)
		value = (size_t)va_arg(ap, size_t);
	else if (params->mod == hh)
		value = (unsigned char)va_arg(ap, unsigned int);
	else if (params->mod == h)
		value = (unsigned short)va_arg(ap, unsigned int);
	else
		value = (unsigned int)va_arg(ap, unsigned int);
	return (value);
}

static char			*get_base(char letter)
{
	if (letter == 'U' || letter == 'u')
		return (ft_strdup("0123456789"));
	if (letter == 'o' || letter == 'O')
		return (ft_strdup("01234567"));
	if (letter == 'x')
		return (ft_strdup("0123456789abcdef"));
	else
		return (ft_strdup("0123456789ABCDEF"));
}

static int			print_precision(t_param *params, char *value, char letter)
{
	int		printed;
	int		precision;

	precision = params->precision;
	printed = 0;
	if (params->flags[1].sign)
		printed += print_appendix(params, letter, value, &params->width);
	if (precision > (int)ft_strlen(value))
		printed += precision - (int)ft_strlen(value);
	while (precision > (int)ft_strlen(value))
		precision -= ft_putstr_fd("0", g_fd);
	return (printed);
}

static int			print_width(t_param *ps, char *value, char l)
{
	int		printed;
	int		width;

	printed = 0;
	width = ps->width;
	if (value[0] == '0' && ps->precision == 0 && ps->width != 1)
		width++;
	if (ps->flags[2].sign)
		printed += print_appendix(ps, l, value, &width);
	else if (!ps->flags[1].sign && ps->flags[3].sign && (l == 'o' || l == 'O'))
		width--;
	else if (!ps->flags[1].sign && ps->flags[3].sign && (l == 'x' || l == 'x'))
		width -= 2;
	while (width > ps->precision && width > (int)ft_strlen(value))
	{
		if (ps->flags[2].sign)
			printed += ft_putstr_fd("0", g_fd);
		else
			printed += ft_putstr_fd(" ", g_fd);
		width--;
	}
	if (!ps->flags[2].sign)
		printed += print_appendix(ps, l, value, &width);
	return (printed);
}

int					print_unsigned(t_param *params, va_list ap, char letter)
{
	char		*value;
	int			printed;
	char		*base;

	printed = 0;
	base = get_base(letter);
	value = ft_unsigned_itoa_base(get_size(params, ap, letter), base);
	if (params->flags[1].sign)
	{
		printed += print_precision(params, value, letter);
		if (!(value[0] == '0' && params->precision == 0))
			printed += ft_putstr_fd(value, g_fd);
		printed += print_width(params, value, letter);
	}
	else
	{
		printed += print_width(params, value, letter);
		printed += print_precision(params, value, letter);
		if (!(value[0] == '0' && params->precision == 0))
			printed += ft_putstr_fd(value, g_fd);
	}
	ft_strdel(&value);
	ft_strdel(&base);
	return (printed);
}
