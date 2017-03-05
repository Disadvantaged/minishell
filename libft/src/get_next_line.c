/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgolear <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 17:08:39 by dgolear           #+#    #+#             */
/*   Updated: 2016/12/24 10:46:38 by dgolear          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		get_next_line(int fd, char **line)
{
	static char *string = NULL;
	char		*tmp;
	int			flag;
	int			error;
	char		temp[2];

	if (fd < 0 || line == NULL || read(fd, string, 0) < 0)
		return (-1);
	flag = 0;
	*line = ft_strnew(1);
	while ((error = read(fd, temp, 1) > 0))
	{
		flag = 1;
		if (temp[0] == '\n')
			break ;
		tmp = *line;
		*line = ft_strjoin(*line, temp);
		ft_strdel(&tmp);
	}
	if (error < 0)
		return (-1);
	return (flag);
}
