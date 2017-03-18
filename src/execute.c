/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgolear <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 13:35:25 by dgolear           #+#    #+#             */
/*   Updated: 2017/03/18 13:12:52 by dgolear          ###   ########.fr       */
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
				ft_dprintf(2, "minishell: cannot access bin\
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

static char	*get_path(char *name, char **env)
{
	char	*temp;
	char	path_var[1024];
	char	*realpath;
	char	paths[100][100];
	int		i;

	i = 0;
	while (env[i])
	{
		if (ft_strstr(env[i], "PATH") != NULL && env[i][0] == 'P')
			break ;
		i++;
	}
	ft_strcpy(path_var, ft_strchr(env[i], '=') + 1);
	ft_strcpy(paths[0], strtok_r(path_var, ":", &temp));
	i = 1;
	while ((realpath = strtok_r(NULL, ":", &temp)) != NULL)
		ft_strcpy(paths[i++], realpath);
	if ((realpath = check_paths(name, paths, i)) == NULL)
	{
		ft_dprintf(2, "minishell: command not found: %s\n", name);
		exit(-1);
	}
	return (realpath);
}

static int	launch(char **args, char **env)
{
	int		stat;
	pid_t	pid;
	pid_t	w;
	char	*path;

	pid = fork();
	if (pid < 0)
		exit(-1 + 0 * ft_dprintf(2, "minishell: fork() error\n"));
	if (pid == 0)
	{
		path = get_path(args[0], env);
		signal_handler(IS_CHILD);
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
