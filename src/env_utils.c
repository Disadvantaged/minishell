/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgolear <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 13:26:52 by dgolear           #+#    #+#             */
/*   Updated: 2017/03/19 13:35:27 by dgolear          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_env(char **env)
{
	int		i;

	i = 0;
	while (env[i] != NULL)
		ft_printf("%s\n", env[i++]);
}

int		find_var(char *buf, char **env)
{
	int		j;
	int		i;

	i = 0;
	while (env[i])
	{
		j = 0;
		while (env[i][j] != '=')
		{
			if (buf[j] == env[i][j])
				j++;
			else
				break ;
		}
		if (env[i][j] == '=')
			return (i);
		i++;
	}
	return (i);
}

void	set_var(char *name, char *value, char **env)
{
	int		i;
	char	buf[4096];

	ft_strclr(buf);
	ft_strcat(buf, name);
	ft_strcat(buf, "=");
	i = find_var(buf, env);
	if (value == NULL)
		ft_strcat(buf, "\0");
	else if (value[0] == '\"')
	{
		ft_strcat(buf, value + 1);
		buf[ft_strlen(buf) - 1] = '\0';
	}
	else
		ft_strcat(buf, value);
	if (env[i] == NULL)
		env[i + 1] = NULL;
	env[i] = ft_strdup(buf);
}

char	*ft_getenv(char *name, char **env)
{
	int		i;
	int		j;
	char	varname[257];

	ft_strclr(varname);
	ft_strcpy(varname, name);
	i = 0;
	while (env[i])
	{
		j = 0;
		while (env[i][j] != '=')
		{
			if (varname[j] == env[i][j])
				j++;
			else
				break ;
		}
		if (env[i][j] == '=')
			return (&env[i][j + 1]);
		i++;
	}
	return (NULL);
}
