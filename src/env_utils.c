/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgolear <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 13:26:52 by dgolear           #+#    #+#             */
/*   Updated: 2017/03/31 13:50:51 by dgolear          ###   ########.fr       */
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
		while (buf[j] && env[i][j] != '=')
		{
			if (buf[j] == env[i][j])
				j++;
			else
				break ;
		}
		if (env[i][j] == '=' && buf[j] == '\0')
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
	ft_strcpy(buf, name);
	i = find_var(buf, env);
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
	if (env[i] == NULL)
		env[i + 1] = NULL;
	env[i] = ft_strdup(buf);
}

char	*ft_getenv(char *name, char **env)
{
	int		i;
	int		j;

	i = 0;
	while (env[i])
	{
		j = 0;
		while (name[j] && env[i][j] != '=')
		{
			if (name[j] == env[i][j])
				j++;
			else
				break ;
		}
		if (env[i][j] == '=' && name[j] == '\0')
			return (&env[i][j + 1]);
		i++;
	}
	return (NULL);
}
