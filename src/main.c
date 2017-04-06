/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgolear <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 11:30:55 by dgolear           #+#    #+#             */
/*   Updated: 2017/04/06 18:24:39 by dgolear          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		g_ret;

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
	args = NULL;
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
	g_ret = 0;
	minishell_loop(env, ac > 1 ? av + 1 : NULL);
	return (0);
}
