/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_itoa.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgolear <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 13:19:53 by dgolear           #+#    #+#             */
/*   Updated: 2017/02/27 13:55:06 by dgolear          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_symbols(uintmax_t val, int base_len)
{
	int		i;

	i = 0;
	if (val == 0)
		return (1);
	while (val > 0)
	{
		val /= base_len;
		i++;
	}
	return (i);
}

char		*ft_unsigned_itoa_base(uintmax_t val, char *base)
{
	char	*value;
	int		len;
	int		base_len;

	base_len = ft_strlen(base);
	len = count_symbols(val, base_len);
	if ((value = (char*)ft_memalloc(len + 1)) == NULL)
		return (NULL);
	if (val == 0)
		return (ft_strcpy(value, "0"));
	while (val > 0)
	{
		value[--len] = base[val % base_len];
		val /= base_len;
	}
	return (value);
}
