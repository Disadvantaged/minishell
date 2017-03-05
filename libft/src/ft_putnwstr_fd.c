/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnwstr_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgolear <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 11:01:45 by dgolear           #+#    #+#             */
/*   Updated: 2017/03/05 11:05:31 by dgolear          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putnwstr_fd(wchar_t *s, int len, int fd)
{
	int		i;

	i = 0;
	while (*s && i < len)
	{
		if (*s <= 0x7F)
			i++;
		else if (*s <= 0x7FF)
			i += 2;
		else if (*s <= 0xFFFF)
			i += 3;
		else if (*s <= 0x10FFFF)
			i += 4;
		if (i <= len)
			ft_putwchar_fd(*s++, fd);
	}
	return (i);
}
