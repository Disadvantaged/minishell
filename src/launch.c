/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgolear <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 14:07:01 by dgolear           #+#    #+#             */
/*   Updated: 2017/03/31 11:14:44 by dgolear          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*check_paths(char *name, char paths[][100], int max)
{
	char	realpath[200];
	int		i;

	realpath[0] = '\0';
	i = 0;
	while (i < max)
	{
		ft_strcpy(realpath, paths[i]);
		ft_strcat(realpath, "/");
		ft_strcat(realpath, name);
		if (access(realpath, F_OK) == 0)
		{
			if (access(realpath, X_OK) == -1)
			{
				ft_dprintf(STDERR_FILENO, "minishell: cannot access bin\
ary with address:%s\n", realpath);
				i++;
				continue;
			}
			return (ft_strdup(realpath));
		}
		i++;
	}
	return (NULL);
}

void		add_pathvar(char **env, char path_var[1024])
{
	char	*value;

	value = NULL;
	value = ft_getenv("PATH", env);
	if (value == NULL)
	{
		ft_dprintf(STDERR_FILENO, "minishell: PATH variable does not exist\n");
		exit(-1);
	}
	ft_strcpy(path_var, value);
	if (path_var[0] == '\0')
	{
		ft_dprintf(STDERR_FILENO, "minishell: PATH variable is empty\n");
		exit(-1);
	}
}

static char	*get_path(char *name, char **env)
{
	char	*temp;
	char	path_var[1024];
	char	*realpath;
	char	paths[100][100];
	int		i;

	if (name[0] != '/' && name[0] != '.')
	{
		i = 0;
		add_pathvar(env, path_var);
		ft_strcpy(paths[0], ft_strtok_r(path_var, ":", &temp));
		i = 1;
		while ((realpath = ft_strtok_r(NULL, ":", &temp)) != NULL)
			ft_strcpy(paths[i++], realpath);
		if ((realpath = check_paths(name, paths, i)) == NULL)
		{
			ft_dprintf(STDERR_FILENO,
				"minishell: command not found: %s\n", name);
			return (NULL);
		}
	}
	else
		return (name);
	return (realpath);
}

int			launch(char **args, char **env)
{
	int		stat;
	pid_t	pid;
	pid_t	w;
	char	*path;

	pid = fork();
	if (pid < 0)
		exit(-1 + 0 * ft_dprintf(STDERR_FILENO, "minishell: fork() error\n"));
	if (pid == 0)
	{
		signal_handler(IS_CHILD);
		if ((path = get_path(args[0], env)) == NULL)
			exit(-1);
		if (execve(path, args, env) == -1)
			exit(ft_dprintf(2, "minishell: Command execution error\n"));
	}
	else
	{
		if ((w = waitpid(pid, &stat, WUNTRACED)) == -1)
			exit(-1 + 0 * ft_dprintf(2, "minishell: Error with wait\n"));
		if (WIFEXITED(stat))
			return (WEXITSTATUS(stat));
	}
	return (0);
}
