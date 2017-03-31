/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_env.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgolear <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 12:40:58 by dgolear           #+#    #+#             */
/*   Updated: 2017/03/31 13:15:49 by dgolear          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	get_name(char *arg, char name[256])
{
	int		i;

	i = 0;
	while (arg[i] && arg[i] != '=')
	{
		name[i] = arg[i];
		i++;
	}
}

int			b_env(char **args, char **env)
{
	char	**envc;
	int		i;
	char	name[256];

	i = 1;
	if (args[1] == NULL)
		print_env(env);
	else
	{
		envc = copy_env(env);
		while (args[i] && ft_strchr(args[i], '=') != NULL)
		{
			ft_strclr(name);
			get_name(args[i], name);
			set_var(name, ft_strchr(args[i], '=') + 1, envc);
			i++;
		}
		if (args[i])
			launch(&args[i], envc);
		free_args(envc);
	}
	return (0);
}
