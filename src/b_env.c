/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_env.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgolear <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 12:40:58 by dgolear           #+#    #+#             */
/*   Updated: 2017/03/09 15:46:56 by dgolear          ###   ########.fr       */
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

int		b_env(char **args, char **env)
{
	if (args[1] == NULL)
		print_env(env);
	return (0);
}
