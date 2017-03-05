/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgolear <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 16:59:23 by dgolear           #+#    #+#             */
/*   Updated: 2016/10/12 17:07:26 by dgolear          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*s;

	s = (char*)dest;
	i = 0;
	while (i < n)
	{
		*s = *(char*)src;
		i++;
		s++;
		src++;
	}
	return (dest);
}
