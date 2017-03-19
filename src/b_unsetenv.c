/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_unsetenv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgolear <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 13:11:56 by dgolear           #+#    #+#             */
/*   Updated: 2017/03/19 13:39:27 by dgolear          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	remove_var(char *arg, char **env)
{
	int		i;
	int		j;

	i = 0;
	while (env[i])
	{
		j = 0;
		while (env[i][j] == arg[j] && env[i][j] != '=')
			j++;
		if (env[i][j] == '=')
		{
			j = i;
			while (env[j + 1])
			{
				env[j] = env[j + 1];
				j++;
			}
			env[j] = NULL;
		}
		i++;
	}
}

int		b_unsetenv(char **args, char **env)
{
	if (args[1] == NULL)
	{
		ft_dprintf(STDERR_FILENO, "unsetenv: Too few arguments.\n");
		return (-1);
	}
	remove_var(args[1], env);
	return (0);
}
