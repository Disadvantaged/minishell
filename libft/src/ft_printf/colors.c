/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgolear <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 10:45:55 by dgolear           #+#    #+#             */
/*   Updated: 2017/03/05 11:15:13 by dgolear          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		find_color(const char *format, int *i)
{
	int		j;
	char	*str;
	char	*tmp;
	char	temp[2];
	int		color;

	temp[1] = '\0';
	str = ft_strnew(1);
	j = *i + 1;
	while (format[j] && format[j] != '}')
	{
		tmp = str;
		temp[0] = format[j++];
		str = ft_strjoin(str, temp);
		ft_strdel(&tmp);
	}
	color = enable_color(str);
	if (color != NO_COLOR)
	{
		*i = j + 1;
		return (1);
	}
	else
		return (0);
	ft_strdel(&str);
}

int		enable_color(char *str)
{
	if (!ft_strcmp(str, "black"))
		ft_putstr_fd(BLACK, g_fd);
	else if (!ft_strcmp(str, "red"))
		ft_putstr_fd(RED, g_fd);
	else if (!ft_strcmp(str, "green"))
		ft_putstr_fd(GREEN, g_fd);
	else if (!ft_strcmp(str, "yellow"))
		ft_putstr_fd(YELLOW, g_fd);
	else if (!ft_strcmp(str, "blue"))
		ft_putstr_fd(BLUE, g_fd);
	else if (!ft_strcmp(str, "magenta"))
		ft_putstr_fd(MAGENTA, g_fd);
	else if (!ft_strcmp(str, "white"))
		ft_putstr_fd(WHITE, g_fd);
	else if (!ft_strcmp(str, "cyan"))
		ft_putstr_fd(CYAN, g_fd);
	else if (!ft_strcmp(str, "eoc"))
		ft_putstr_fd(RESET, g_fd);
	else
		return (NO_COLOR);
	return (0);
}
