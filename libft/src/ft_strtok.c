/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgolear <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 14:41:07 by dgolear           #+#    #+#             */
/*   Updated: 2017/03/06 14:58:14 by dgolear          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtok_r(char *str, const char *delim, char **nextp)
{
	char *ret;

	if (str == NULL)
	{
		str = *nextp;
	}
	str += ft_strspn(str, delim);
	if (*str == '\0')
		return (NULL);
	ret = str;
	str += ft_strcspn(str, delim);
	if (*str)
		*str++ = '\0';
	*nextp = str;
	return (ret);
}
