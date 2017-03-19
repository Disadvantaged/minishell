/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_setenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgolear <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 12:51:39 by dgolear           #+#    #+#             */
/*   Updated: 2017/03/19 12:23:48 by dgolear          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	set_var(char *name, char *value, char **env)
{
	int		i;
	char	buf[4096];

	i = 0;
	ft_strclr(buf);
	while (env[i] && ft_strstr(env[i], name) == NULL)
		i++;
	ft_strcat(buf, name);
	ft_strcat(buf, "=");
	if (value == NULL)
		ft_strcat(buf, "\0");
	else if (value[0] == '\"')
	{
		ft_strcat(buf, value + 1);
		buf[ft_strlen(buf) - 1] = '\0';
	}
	else
		ft_strcat(buf, value);
	if (!env[i])
		env[i + 1] = NULL;
	env[i] = ft_strdup(buf);
}

int		b_setenv(char **args, char **env)
{
	int		i;

	i = 0;
	if (args[1] == NULL)
	{
		print_env(env);
		return (0);
	}
	if (!ft_isalpha(args[1][0]))
		return (-1 + 0 * ft_dprintf(STDERR_FILENO,
			"setenv: Variable name must begin with a letter\n"));
	while (args[1][i])
	{
		if (!ft_isalnum(args[1][i++]))
			return (-1 + 0 * ft_dprintf(STDERR_FILENO,
			"setenv: Variable name must contain alphanumeric characters\n"));
		i++;
	}
	set_var(args[1], args[2], env);
	return (0);
}
