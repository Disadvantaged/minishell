/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_address.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgolear <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 18:21:55 by dgolear           #+#    #+#             */
/*   Updated: 2017/03/05 10:54:16 by dgolear          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char g_base[] = "0123456789abcdef";

static char	*print_addr(void *p)
{
	char			*s;
	unsigned long	i;
	int				len;
	unsigned long	copy;

	len = 0;
	i = (unsigned long)p;
	copy = i;
	while (copy > 0)
	{
		len++;
		copy /= 16;
	}
	if (len == 0)
		return (ft_strdup("0"));
	s = malloc(len + 1);
	s[len--] = '\0';
	while (i > 0)
	{
		s[len] = g_base[i % 16];
		i /= 16;
		len--;
	}
	return (s);
}

static void	print_width(t_param *p, char *adress)
{
	int		width;

	if (p->precision == 0 && ft_strcmp(adress, "0") == 0)
		p->width--;
	width = p->width;
	if (p->flags[1].sign)
		while (width > (int)ft_strlen(adress) + 2 && width > p->precision)
			width -= ft_putstr_fd(" ", g_fd);
	else
	{
		if (p->flags[2].sign)
			ft_putstr_fd("0x", g_fd);
		while (width > (int)ft_strlen(adress) + 2 && width > p->precision)
			if (p->flags[2].sign)
				width -= ft_putstr_fd("0", g_fd);
			else
				width -= ft_putstr_fd(" ", g_fd);
		if (!p->flags[2].sign)
			ft_putstr_fd("0x", g_fd);
	}
	if (p->precision > (int)ft_strlen(adress) + 2)
		p->width = p->precision + 2;
}

static void	print_precision(t_param *params, char *adress)
{
	int		precision;
	int		len;

	len = (int)ft_strlen(adress);
	precision = params->precision;
	while (precision > len)
		precision -= ft_putstr_fd("0", g_fd);
}

int			print_adress(t_param *params, va_list ap, char letter)
{
	void	*addr;
	char	*adress;

	addr = va_arg(ap, void *);
	adress = print_addr(addr);
	if (letter && params->width <= (int)ft_strlen(adress) + 2)
		params->width = ft_strlen(adress) + 2;
	if (params->flags[1].sign)
	{
		ft_putstr_fd("0x", g_fd);
		print_precision(params, adress);
		if (!(ft_strcmp(adress, "0") == 0 && params->precision == 0))
			ft_putstr_fd(adress, g_fd);
		print_width(params, adress);
	}
	else
	{
		print_width(params, adress);
		print_precision(params, adress);
		if (!(ft_strcmp(adress, "0") == 0 && params->precision == 0))
			ft_putstr_fd(adress, g_fd);
	}
	free(adress);
	return (params->width);
}
