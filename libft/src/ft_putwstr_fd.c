/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgolear <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 14:04:16 by dgolear           #+#    #+#             */
/*   Updated: 2017/02/19 13:02:55 by dgolear          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putwstr_fd(wchar_t *s, int fd)
{
	int		i;

	i = 0;
	while (*s)
	{
		i += ft_putwchar_fd(*s, fd);
		s++;
	}
	return (i);
}
