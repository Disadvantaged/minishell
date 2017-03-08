/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgolear <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 11:30:55 by dgolear           #+#    #+#             */
/*   Updated: 2017/03/09 01:28:55 by dgolear          ###   ########.fr       */
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
		ft_printf("$> ");
		args = readline();
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
