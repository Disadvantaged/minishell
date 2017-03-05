/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgolear <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/15 08:39:06 by dgolear           #+#    #+#             */
/*   Updated: 2016/10/15 08:57:36 by dgolear          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*s;

	s = (char*)malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (s == NULL)
		return (NULL);
	ft_strcpy(s, src);
	return (s);
}
