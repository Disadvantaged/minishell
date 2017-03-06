/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgolear <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 12:22:19 by dgolear           #+#    #+#             */
/*   Updated: 2017/03/06 13:32:21 by dgolear          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*readline(void)
{
	char	buf[2];
	char	*str;
	char	*temp;
	int		i;
	
	str = ft_strnew(1);
	buf[1] = '\0';
	while ((i = read(STDIN_FILENO, &buf, 1) > 0) && buf[0] != '\n')
	{
		temp = ft_strjoin(str, buf);
		ft_strdel(&str);
		str = temp;
	}
	if (i < 0)
	{
		ft_printf("minishell: error with reading from stdin");
		exit (-1);
	}
	return (str);
}
