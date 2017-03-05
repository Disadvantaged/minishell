/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_wstring.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgolear <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 12:54:30 by dgolear           #+#    #+#             */
/*   Updated: 2017/03/05 11:04:50 by dgolear          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_wlen(wchar_t *s, int precision, int i)
{
	if (*s == '\0' || precision == 0)
		return (i);
	else if (*s <= 0x7F)
		return (get_wlen(s + 1, precision - 1, i + 1));
	else if (*s <= 0x7FF && precision >= 2)
		return (get_wlen(s + 1, precision - 2, i + 2));
	else if (*s <= 0xFFFF && precision >= 3)
		return (get_wlen(s + 1, precision - 3, i + 3));
	else if (*s <= 0x10FFFF && precision >= 4)
		return (get_wlen(s + 1, precision - 4, i + 4));
	else
		return (i);
}

static void	print_width(int len, t_param *params)
{
	int		width;

	if (params->width < len)
		params->width = len;
	width = params->width;
	if (len == 0 && width == 1)
		width = 0;
	while (width > len)
	{
		if (params->flags[2].sign)
			ft_putchar_fd('0', g_fd);
		else
			ft_putchar_fd(' ', g_fd);
		width--;
	}
}

int			print_wstring(t_param *params, va_list ap, char letter)
{
	wchar_t		*s;
	int			len;

	if (letter)
		;
	s = NULL;
	if ((s = va_arg(ap, wchar_t *)) == NULL)
		s = L"(null)";
	if (params->precision != NO_PRECISION)
		len = get_wlen(s, params->precision, 0);
	else
		len = ft_wstrlen(s);
	if (params->flags[1].sign == 0)
		print_width(len, params);
	ft_putnwstr_fd(s, len, g_fd);
	if (params->flags[1].sign != 0)
		print_width(len, params);
	return (params->width);
}
