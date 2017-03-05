/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgolear <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/15 08:26:26 by dgolear           #+#    #+#             */
/*   Updated: 2016/10/18 16:15:55 by dgolear          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dst, const char *src, size_t n)
{
	size_t	i;
	size_t	len;

	len = 0;
	i = ft_strlen(dst);
	while (src[len] && len < n)
	{
		dst[i + len] = src[len];
		len++;
	}
	dst[i + len] = '\0';
	return (dst);
}
