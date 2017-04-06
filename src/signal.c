/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgolear <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 18:20:20 by dgolear           #+#    #+#             */
/*   Updated: 2017/04/06 18:32:29 by dgolear          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	trap_parent(int sig)
{
	if (sig == SIGINT)
		ft_putstr("\n$> ");
}

void	trap(int sig)
{
	if (sig == SIGINT)
		exit(SIGINT);
	if (sig == SIGQUIT)
		exit(SIGQUIT);
}

void	signal_handler(int flag)
{
	if (flag == IS_PARENT)
	{
		signal(SIGTSTP, SIG_IGN);
		signal(SIGINT, &trap_parent);
		signal(SIGQUIT, &trap);
	}
	else if (flag == IS_CHILD)
	{
		signal(SIGTSTP, SIG_DFL);
		signal(SIGINT, &trap);
		signal(SIGQUIT, SIG_DFL);
	}
}
