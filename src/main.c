/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgolear <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 11:30:55 by dgolear           #+#    #+#             */
/*   Updated: 2017/03/09 15:56:56 by dgolear          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_args(char **args)
{
	char	*temp;
	int		i;

	i = 0;
	while (args[i] != NULL)
	{
		temp = args[i];
		i++;
		ft_strdel(&temp);
	}
	free(args);
}

void	trap(int sig)
{
	if (sig == SIGINT)
		exit(SIGINT);
	if (sig == SIGQUIT)
		exit (SIGQUIT);
}

void	signal_handler(int	flag)
{
	if (flag == IS_PARENT)
	{
		signal(SIGTSTP, SIG_IGN);
		signal(SIGINT, SIG_IGN);
		signal(SIGQUIT, &trap);
	}
	else if (flag == IS_CHILD)
	{
		signal(SIGTSTP, SIG_DFL);
		signal(SIGINT, &trap);
		signal(SIGQUIT, SIG_DFL);
	}
}

int		minishell_loop(char **env, char **commands)
{
	char		**args;
	int			status;

	if (env || commands)
		;
	if (commands != NULL)
		execute(commands, env);
	status = 1;
	while (status)
	{
		signal_handler(IS_PARENT);
		ft_printf("$> ");
		if ((args = readline()) == NULL)
			continue;
		execute(args, env);
		free_args(args);
	}
	return (status);
}

int		main(int ac, char **av, char **env)
{
	minishell_loop(env, ac > 1 ? av + 1 : NULL);
	return (0);
}
