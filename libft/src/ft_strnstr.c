/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgolear <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/15 08:30:16 by dgolear           #+#    #+#             */
/*   Updated: 2016/10/24 16:00:05 by dgolear          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	l1;
	size_t	l2;
	size_t	i;
	size_t	j;

	i = 0;
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	if (l2 == 0)
		return ((char*)s1);
	while (s1[i] && i < len)
	{
		j = 0;
		while (s1[i + j] == s2[j] && i + j < len)
		{
			if (j == l2 - 1)
				return ((char*)s1 + i);
			j++;
		}
		i++;
	}
	return (NULL);
}
