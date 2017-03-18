/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgolear <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 13:35:25 by dgolear           #+#    #+#             */
/*   Updated: 2017/03/18 14:46:41 by dgolear          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_builtin	g_fun[] =
{
	{"exit", &b_exit},
	{"echo", &b_echo},
	{"cd", &b_cd},
	{"setenv", &b_setenv},
	{"unsetenv", &b_unsetenv},
	{"env", &b_env}
};

int			execute(char **args, char **env)
{
	int		ret;
	int		i;

	i = 0;
	while (i < 6)
	{
		if (ft_strcmp(args[0], g_fun[i].name) == 0)
		{
			ret = g_fun[i].fun(args, env);
			return (ret);
		}
		i++;
	}
	ret = launch(args, env);
	return (ret);
}
