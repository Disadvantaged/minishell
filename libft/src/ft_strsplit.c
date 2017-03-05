/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgolear <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/15 15:12:45 by dgolear           #+#    #+#             */
/*   Updated: 2016/10/24 17:05:51 by dgolear          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_count_words(const char *str, char c)
{
	int i;
	int word;
	int count;

	i = 0;
	word = 0;
	count = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		while (str[i] != c && str[i])
		{
			i++;
			word = 1;
		}
		if (str[i] == c || str[i] == '\0')
		{
			if (word == 1)
				count++;
			word = 0;
			i++;
		}
	}
	return (count);
}

static int	ft_size(const char *str, int i, char c)
{
	int count;

	count = 0;
	while (str[i] != c && str[i])
	{
		count++;
		i++;
	}
	return (count);
}

char		**ft_strsplit(const char *str, char c)
{
	char	**res;
	int		i;
	int		j;
	int		k;

	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	if ((res = (char**)malloc(8 * ft_count_words(str, c) + 1)) == NULL)
		return (NULL);
	while (str[i])
		if ((str[i] == c) && str[i])
			i++;
		else if (str[i])
		{
			k = 0;
			if ((res[j] = (char*)malloc(ft_size(str, i, c) + 1)) == NULL)
				return (NULL);
			while (str[i] != c && str[i])
				res[j][k++] = str[i++];
			res[j++][k] = '\0';
		}
	res[j] = NULL;
	return (res);
}
