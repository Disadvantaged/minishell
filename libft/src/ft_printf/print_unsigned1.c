/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgolear <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 15:31:18 by dgolear           #+#    #+#             */
/*   Updated: 2017/03/05 11:03:48 by dgolear          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_appendix(t_param *ps, char letter, char *v, int *width)
{
	if (ps->flags[3].sign && (letter == 'o' || letter == 'O'))
	{
		ps->flags[3].sign = 0;
		if (ps->precision == NO_PRECISION || ps->precision == 0)
			ps->precision = 0;
		else
			ps->precision--;
		(*width)--;
		return (ft_putstr_fd("0", g_fd));
	}
	if (ps->flags[3].sign && v[0] != '0')
	{
		ps->flags[3].sign = 0;
		if (letter == 'X')
		{
			*width -= 2;
			return (ft_putstr_fd("0X", g_fd));
		}
		else if (letter == 'x')
		{
			*width -= 2;
			return (ft_putstr_fd("0x", g_fd));
		}
	}
	return (0);
}
