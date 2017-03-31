/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_cd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgolear <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 11:39:25 by dgolear           #+#    #+#             */
/*   Updated: 2017/03/31 12:09:07 by dgolear          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			num_args(char **args)
{
	int		i;

	i = 0;
	while (args[i])
		i++;
	return (i);
}

char		*add_path(char *name, char **env)
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
		ft_strcpy(buf, ft_getenv("HOME", env));
		ft_strcat(buf, name + 1);
	}
	else if (name[0] == '-')
	{
		ft_strcpy(buf, ft_getenv("OLDPWD", env));
		ft_printf("%s\n", ft_getenv("OLDPWD", env));
	}
	else
		ft_strcat(buf, name);
	return (ft_strdup(buf));
}

static char	*check_path(char *s)
{
	if (access(s, F_OK) == -1)
		return ("File doesn't exist");
	else if (access(s, X_OK) == -1)
		return ("permission denied");
	else
		return ("Error accessing directory");
}

int			b_cd(char **args, char **env)
{
	char	*s;

	if (num_args(args) > 2)
	{
		ft_dprintf(STDERR_FILENO, "cd: Too many arguments.\n");
		return (-1);
	}
	if (args[1] == NULL)
		s = ft_strdup(ft_getenv("HOME", env));
	else
		s = add_path(args[1], env);
	if (chdir(s) == -1)
	{
		ft_dprintf(STDERR_FILENO, "cd: %s: %s\n", check_path(s), args[1]);
		return (-1);
	}
	set_var("OLDPWD", ft_getenv("PWD", env), env);
	set_var("PWD", getcwd(NULL, 255), env);
	ft_strdel(&s);
	return (0);
}
