/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_echo.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgolear <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 14:21:42 by dgolear           #+#    #+#             */
/*   Updated: 2017/03/09 14:40:15 by dgolear          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		b_echo(char **args, char **env)
{
	int		nflag;
	int		i;

	i = 1;
	if (args[1] == NULL)
	{
		ft_printf("\n");
		exit(0);
	}
	if (ft_strcmp(args[1], "-n") == 0 && (env || !env))
	{
		nflag = 1;
		i++;
	}
	else
		nflag = 0;
	while (args[i] != NULL)
	{
		ft_putstr(args[i++]);
		if (args[i] == NULL && !nflag)
			ft_putchar('\n');
		else if (args[i] != NULL)
			ft_putchar(' ');
	}
	return (0);
}
