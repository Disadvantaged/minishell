/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_wchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgolear <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 12:52:33 by dgolear           #+#    #+#             */
/*   Updated: 2017/03/05 11:04:18 by dgolear          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_len(wchar_t c)
{
	if (c <= 0x7F)
		return (1);
	else if (c <= 0x7FF)
		return (2);
	else if (c <= 0xFFFF)
		return (3);
	else if (c <= 0x10FFFF)
		return (4);
	else
		return (0);
}

static void	print_width(t_param *params, int len)
{
	int		width;

	if (params->width < len)
		params->width = len;
	width = params->width;
	while (width > len)
	{
		if (params->flags[2].sign)
			ft_putchar_fd('0', g_fd);
		else
			ft_putchar_fd(' ', g_fd);
		width--;
	}
}

int			print_wchar(t_param *params, va_list ap, char letter)
{
	int			len;
	wchar_t		c;

	if (letter)
		;
	c = va_arg(ap, wchar_t);
	len = get_len(c);
	if (params->flags[1].sign)
		print_width(params, len);
	ft_putwchar_fd(c, g_fd);
	if (!params->flags[1].sign)
		print_width(params, len);
	return (params->width);
}
