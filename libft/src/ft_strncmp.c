/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgolear <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/15 08:29:26 by dgolear           #+#    #+#             */
/*   Updated: 2017/02/05 13:14:46 by dgolear          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (*(char *)s1 != *(char *)s2)
			return (*(unsigned char*)s1 - *(unsigned char*)s2);
		if (*(char *)s1 == '\0' && *(char *)s2 == '\0')
			return (0);
		s1++;
		s2++;
		i++;
	}
	return (0);
}
