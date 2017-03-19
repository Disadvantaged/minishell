/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_setenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgolear <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 12:51:39 by dgolear           #+#    #+#             */
/*   Updated: 2017/03/19 13:27:36 by dgolear          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"



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
