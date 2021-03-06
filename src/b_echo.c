/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_echo.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgolear <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 14:21:42 by dgolear           #+#    #+#             */
/*   Updated: 2017/03/18 12:24:44 by dgolear          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_arg(char *arg)
{
	int		i;

	i = 0;
	while (arg[i] != '\0')
	{
		if (arg[i] != '\'' && arg[i] != '\"')
			ft_putchar(arg[i]);
		i++;
	}
}

int		b_echo(char **args, char **env)
{
	int		nflag;
	int		i;

	i = 1;
	if (args[1] == NULL)
	{
		ft_printf("\n");
		return (0);
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
		print_arg(args[i++]);
		if (args[i] == NULL && !nflag)
			ft_putchar('\n');
		else if (args[i] != NULL)
			ft_putchar(' ');
	}
	return (0);
}
