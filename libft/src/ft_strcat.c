/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgolear <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/15 08:29:16 by dgolear           #+#    #+#             */
/*   Updated: 2017/03/18 13:09:35 by dgolear          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dst, const char *src)
{
	int		i;
	int		n;

	if (dst == NULL || src == NULL)
		return (NULL);
	n = 0;
	i = ft_strlen(dst);
	while (src[n])
	{
		dst[i + n] = src[n];
		n++;
	}
	dst[i + n] = '\0';
	return (dst);
}
