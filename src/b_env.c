/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_env.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgolear <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 12:40:58 by dgolear           #+#    #+#             */
/*   Updated: 2017/03/31 13:46:24 by dgolear          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			b_env(char **args, char **env)
{
	int		i;

	i = 1;
	if (args[1] == NULL)
		print_env(env);
	return (0);
}
