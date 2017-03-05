/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 17:37:08 by exam              #+#    #+#             */
/*   Updated: 2016/10/23 18:29:33 by dgolear          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

const char g_s[] = "0123456789abcdef";

static int	ft_rec(char c, int str_base)
{
	int		i;

	i = 0;
	if (c >= 'A' && c <= 'F')
		c = c + 32;
	while (i < str_base)
	{
		if (c == g_s[i])
			return (i);
		i++;
	}
	return (-1);
}

static int	ft_power(int k, int n)
{
	int		i;
	int		num;

	num = 1;
	i = 0;
	while (i < k)
	{
		num = num * n;
		i++;
	}
	return (num);
}

int			ft_atoi_base(const char *str, int str_base)
{
	int		n;
	int		sign;
	int		i;
	int		k;

	sign = 1;
	i = 0;
	while ((str[i] == ' ' || str[i] == '\t' || str[i] == '\n') && str[i])
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	n = 0;
	while (ft_rec(str[i], str_base) != -1)
		i++;
	i--;
	k = 0;
	while (ft_rec(str[i], str_base) != -1)
	{
		n = n + ft_rec(str[i--], str_base) * ft_power(k++, str_base);
	}
	return (n * sign);
}
