/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_exit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgolear <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 13:19:19 by dgolear           #+#    #+#             */
/*   Updated: 2017/03/31 14:05:47 by dgolear          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		g_ret;

int		check_arg(char *arg)
{
	int		i;

	i = 0;
	if (arg[0] == '+' || arg[0] == '-')
		i++;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			return (-1);
		i++;
	}
	return (0);
}

int		b_exit(char **args, char **env)
{
	int		exitstatus;

	if (args[1] != NULL && env)
	{
		if (check_arg(args[1]) == -1)
		{
			ft_dprintf(STDERR_FILENO, "exit: numeric argument required\n");
			exit(-1);
		}
		if (args[2] != NULL)
		{
			ft_dprintf(STDERR_FILENO, "exit: too many arguments\n");
			return (-1);
		}
		exitstatus = ft_atoi(args[1]);
	}
	else
		exitstatus = g_ret;
	free_args(args);
	ft_printf("exit\n");
	exit(exitstatus);
}
