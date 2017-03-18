/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_setenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgolear <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 12:51:39 by dgolear           #+#    #+#             */
/*   Updated: 2017/03/18 13:16:26 by dgolear          ###   ########.fr       */
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
	if (value != NULL)
		ft_strcat(buf, value);
	else
		ft_strcat(buf, "\0");
	if (!env[i])
		env[i + 1] = NULL;
	env[i] = ft_strdup(buf);
}

int		b_setenv(char **args, char **env)
{
	if (args[1] == NULL)
	{
		print_env(env);
		return (0);
	}
	if (args[1][0] == '\0' || ft_strchr(args[1], '=') != NULL)
	{
		ft_dprintf(STDERR_FILENO, "setenv: VAR name contains \'=\' or \
points to empty string\n");
		return (-1);
	}
	set_var(args[1], args[2], env);
	return (0);
}
