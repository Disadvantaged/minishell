/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgolear <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 18:46:37 by dgolear           #+#    #+#             */
/*   Updated: 2017/02/27 13:21:05 by dgolear          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flag		*create_flag(void)
{
	t_flag	*flag;
	int		i;

	if ((flag = (t_flag*)malloc(sizeof(t_flag) * 6)) == NULL)
		exit(-1);
	i = 0;
	while (i < 6)
		flag[i++].sign = 0;
	flag[0].symbol = '+';
	flag[1].symbol = '-';
	flag[2].symbol = '0';
	flag[3].symbol = '#';
	flag[4].symbol = '\'';
	flag[5].symbol = ' ';
	return (flag);
}

t_flag		*check_flags(const char *format, int *pos)
{
	t_flag	*flag;
	int		i;

	flag = create_flag();
	while (format[*pos] == '-' || format[*pos] == '+' || format[*pos] == ' '
		|| format[*pos] == '#' || format[*pos] == '0' || format[*pos] == '\'')
	{
		i = 0;
		while (i < 6)
		{
			if (flag[i].symbol == format[*pos])
				flag[i].sign++;
			i++;
		}
		(*pos)++;
	}
	if (flag[0].sign)
		flag[5].sign = 0;
	if (flag[1].sign)
		flag[2].sign = 0;
	return (flag);
}

int			check_width(const char *format, int *pos, va_list ap)
{
	int		width;

	if (format[*pos] == '*')
	{
		(*pos)++;
		width = va_arg(ap, int);
		if (ft_atoi(&format[*pos]) > 0)
		{
			width = ft_atoi(&format[*pos]);
			(*pos) += ft_nbrlen(ft_atoi(&format[*pos]));
		}
	}
	else if (ft_atoi(&format[*pos]) > 0)
	{
		width = ft_atoi(&format[*pos]);
		(*pos) += ft_nbrlen(ft_atoi(&format[*pos]));
		if (format[*pos] == '*')
		{
			(*pos)++;
			width = va_arg(ap, int);
		}
	}
	else
		width = 0;
	return (width);
}

int			check_precision(const char *format, int *pos, va_list ap)
{
	int		precision;

	if (format[*pos] == '.')
	{
		precision = 0;
		if (format[++(*pos)] == '*')
		{
			if ((precision = va_arg(ap, int)) < 0)
				precision = NO_PRECISION;
			(*pos)++;
		}
		else if (ft_atoi(&format[*pos]) < 0)
			(*pos) += ft_nbrlen(ft_atoi(&format[*pos]));
		else if (ft_atoi(&format[*pos]) > 0)
		{
			precision = ft_atoi(&format[*pos]);
			(*pos) += ft_nbrlen(ft_atoi(&format[*pos]));
		}
		else if (ft_isdigit(format[*pos]) == 1)
			(*pos)++;
		return (precision);
	}
	else
		return (NO_PRECISION);
}

t_length	check_length(const char *format, int *pos)
{
	if (format[*pos] == 'h' || format[*pos] == 'l' || format[*pos] == 'L'
		|| format[*pos] == 'j' || format[*pos] == 'z')
	{
		(*pos)++;
		if (format[*pos - 1] == 'h' && format[*pos] == 'h')
		{
			(*pos)++;
			return (hh);
		}
		else if (format[*pos - 1] == 'h' && format[*pos] != 'h')
			return (h);
		else if (format[*pos - 1] == 'l' && format[*pos] == 'l')
		{
			(*pos)++;
			return (ll);
		}
		else if (format[*pos - 1] == 'l' && format[*pos] != 'l')
			return (l);
		else if (format[*pos - 1] == 'L')
			return (L);
		else if (format[*pos - 1] == 'j')
			return (j);
		return (z);
	}
	return (no_length);
}
