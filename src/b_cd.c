/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_cd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgolear <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 11:39:25 by dgolear           #+#    #+#             */
/*   Updated: 2017/03/18 12:20:59 by dgolear          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*find_home(char **env)
{
	int		i;

	i = 0;
	while (env[i])
	{
		if (ft_strstr(env[i], "HOME") != NULL)
			return (ft_strchr(env[i], '=') + 1);
		i++;
	}
	return (NULL);
}

int		num_args(char **args)
{
	int		i;

	i = 0;
	while (args[i])
		i++;
	return (i);
}

char	*add_path(char *name, char **env)
{
	char	path[4096];
	char	buf[4096];

	ft_strclr(path);
	ft_strclr(buf);
	getcwd(path, 4095);
	ft_strcat(buf, path);
	ft_strcat(buf, "/");
	if (name[0] == '/')
		return (ft_strdup(name));
	else if (name[0] == '~')
	{
		ft_strcpy(buf, find_home(env));
		ft_strcat(buf, "/");
		ft_strcat(buf, name + 2);
	}
	else
		ft_strcat(buf, name);
	return (ft_strdup(buf));
}

int		b_cd(char **args, char **env)
{
	int		i;
	char	*s;

	i = 0;
	if (args[1] == NULL)
	{
		s = find_home(env);
		chdir(s);
	}
	else
	{
		if (num_args(args) > 2)
		{
			ft_dprintf(STDERR_FILENO, "cd: Too many arguments.\n");
			return (-1);
		}
		s = add_path(args[1], env);
		if (chdir(s) == -1)
		{
			ft_dprintf(STDERR_FILENO, "cd: given path is not a \
directory or does not exist: %s\n", args[1]);
			return (-1);
		}
		ft_strdel(&s);
	}
	return (0);
}
