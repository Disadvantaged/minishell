/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgolear <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 10:28:30 by dgolear           #+#    #+#             */
/*   Updated: 2017/03/09 01:27:39 by dgolear          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <dirent.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <signal.h>
# include "libft.h"

char		**readline(void);
int			minishell_loop(char **env, char **commands);
int			execute(char **args, char **env);
int			b_exit(char **args);
int			b_cd(char **args);
int			b_echo(char **args);
int			b_setenv(char **args);
int			b_unsetenv(char **args);
int			b_env(char **args);
int			b_pwd(char **args);
sig_t		child_trap;
sig_t		parent_trap;

typedef struct	s_builtin
{
	char	*name;
	int		(*fun)(char **, char **);
}				t_builtin;

#endif
