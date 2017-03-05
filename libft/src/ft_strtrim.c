/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgolear <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/15 15:53:47 by dgolear           #+#    #+#             */
/*   Updated: 2016/10/24 16:55:22 by dgolear          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	int		len;
	char	*str;

	if (!s)
		return (NULL);
	i = 0;
	j = ft_strlen(s) - 1;
	while ((s[i] == ' ' || s[i] == '\t' || s[i] == '\n') && s[i])
		i++;
	while (s[i] && (s[j] == ' ' || s[j] == '\t' || s[j] == '\n'))
		j--;
	len = 0;
	if ((str = (char*)malloc(sizeof(char) * (j - i + 2))) == NULL)
		return (NULL);
	while (i <= j)
	{
		str[len] = s[i];
		len++;
		i++;
	}
	str[len] = '\0';
	return (str);
}
