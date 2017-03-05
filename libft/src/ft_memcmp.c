/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgolear <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/15 12:38:11 by dgolear           #+#    #+#             */
/*   Updated: 2016/10/23 13:25:42 by dgolear          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (*((unsigned char*)s1 + i) == *((unsigned char*)s2 + i))
		{
			i++;
		}
		else
			return (*((unsigned char*)s1 + i) - *((unsigned char*)s2 + i));
	}
	return (*(unsigned char*)s1 - *(unsigned char*)s2);
}
