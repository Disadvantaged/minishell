/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_env.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgolear <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 12:40:58 by dgolear           #+#    #+#             */
/*   Updated: 2017/03/19 12:09:55 by dgolear          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
				break;
		}
		if (env[i][j] == '=')
			return (&env[i][j + 1]);
		i++;
	}
	return (NULL);
}

void	print_env(char **env)
{
	int		i;

	i = 0;
	while (env[i] != NULL)
		ft_printf("%s\n", env[i++]);
}

int		b_env(char **args, char **env)
{
	if (args[1] == NULL)
		print_env(env);
	return (0);
}
