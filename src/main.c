/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgolear <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 11:30:55 by dgolear           #+#    #+#             */
/*   Updated: 2017/03/06 13:34:37 by dgolear          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		minishell_loop(char **env, char **commands)
{
	char		*line;
//	t_list		*args;
//	t_list		*temp;
	int			status;

	if (env || commands)
		;
//	if (commands != NULL)
//		execute(commands);
	status = 1;
	while (status)
	{
		ft_printf("$> ");
		line = readline();
		args = get_args(line);
//		while (args != NULL)
//		{
//			temp = args;
//			args = args->next;
//			status = execute(temp->content);
//			free(temp);
//		}
		if (!ft_strcmp(line, "exit"))
			exit(0);
		ft_strdel(&line);
	}
	return (status);
}

int		main(int ac, char **av, char **env)
{
	minishell_loop(env, ac > 1 ? av + 1 : NULL);
	return (0);
}
