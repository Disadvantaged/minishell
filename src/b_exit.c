/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_exit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgolear <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 13:19:19 by dgolear           #+#    #+#             */
/*   Updated: 2017/03/09 14:39:35 by dgolear          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		b_exit(char **args, char **env)
{
	int		exitstatus;

	if (env)
		;
	if (args[1] != NULL)
		exitstatus = ft_atoi(args[1]);
	else
		exitstatus = 0;
	free_args(args);
	exit(exitstatus);
}
