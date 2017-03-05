/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgolear <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/15 08:34:56 by dgolear           #+#    #+#             */
/*   Updated: 2016/10/23 13:56:40 by dgolear          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t	i;
	size_t	len;

	len = 0;
	i = ft_strlen(dst);
	if (n < i)
		return (n + ft_strlen(src));
	while (src[len] && i + len + 1 < n)
	{
		dst[i + len] = src[len];
		len++;
	}
	dst[len + i] = '\0';
	return (i + ft_strlen(src));
}
