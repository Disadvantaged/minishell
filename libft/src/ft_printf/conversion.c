/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgolear <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 15:17:53 by dgolear           #+#    #+#             */
/*   Updated: 2017/03/05 10:52:26 by dgolear          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_conv	g_conv[] =
{
	{'d', &print_int},
	{'D', &print_int},
	{'i', &print_int},
	{'%', &print_percent},
	{'n', &print_len},
	{'s', &print_string},
	{'S', &print_wstring},
	{'c', &print_char},
	{'C', &print_wchar},
	{'p', &print_adress},
	{'u', &print_unsigned},
	{'U', &print_unsigned},
	{'o', &print_unsigned},
	{'O', &print_unsigned},
	{'x', &print_unsigned},
	{'X', &print_unsigned},
};

int		g_num = 16;

int	print_percent(t_param *params, va_list ap, char letter)
{
	int		width;

	if (ap || letter)
		;
	if (params->width == 0)
		params->width = 1;
	width = params->width;
	if (params->flags[1].sign)
		ft_putchar_fd('%', g_fd);
	while (width > 1)
	{
		if (params->flags[2].sign)
			ft_putchar_fd('0', g_fd);
		else
			ft_putchar_fd(' ', g_fd);
		width--;
	}
	if (!params->flags[1].sign)
		ft_putchar_fd('%', g_fd);
	return (params->width);
}

int		check(const char *format, int *pos, va_list ap)
{
	int			length;
	t_param		*params;

	length = 0;
	if ((params = (t_param*)ft_memalloc(sizeof(t_param))) == NULL
		|| (params->flags = check_flags(format, pos)) == NULL)
		return (0);
	if ((params->width = check_width(format, pos, ap)) < 0)
	{
		params->flags[1].sign = 1;
		params->width *= -1;
	}
	params->precision = check_precision(format, pos, ap);
	params->mod = check_length(format, pos);
	if (params->precision != NO_PRECISION && params->precision != 0)
		params->flags[2].sign = 0;
	if ((length = conversion(format, pos, params, ap)) == -1)
		return (0);
	free(params->flags);
	free(params);
	return (length);
}

int	conversion(const char *format, int *pos, t_param *params, va_list ap)
{
	int		i;
	int		printed;

	i = 0;
	while (i < g_num)
	{
		if (format[*pos] == g_conv[i].spec)
		{
			(*pos)++;
			return (g_conv[i].fun(params, ap, g_conv[i].spec));
		}
		i++;
	}
	if (params->width > 1)
		printed = params->width - 1;
	else
		printed = 0;
	if (params->flags[1].sign && params->width > 1)
		printed += ft_putchar_fd(format[(*pos)++], g_fd);
	while (params->width > 1)
		if (!params->flags[2].sign)
			params->width -= ft_putstr_fd(" ", g_fd);
		else
			params->width -= ft_putstr_fd("0", g_fd);
	return (printed);
}
