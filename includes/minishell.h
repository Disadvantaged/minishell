/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgolear <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 10:28:30 by dgolear           #+#    #+#             */
/*   Updated: 2017/03/09 15:14:41 by dgolear          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <dirent.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <signal.h>
# include "libft.h"

# define IS_PARENT 1
# define IS_CHILD 0

char		**readline(void);
void		free_args(char **args);
int			minishell_loop(char **env, char **commands);
int			execute(char **args, char **env);
int			b_exit(char **args, char **env);
int			b_cd(char **args, char **env);
int			b_echo(char **args, char **env);
int			b_setenv(char **args, char **env);
int			b_unsetenv(char **args, char **env);
int			b_env(char **args, char **env);
int			b_pwd(char **args, char **env);
void		signal_handler(int	flag);
void		trap(int sig);

typedef struct	s_builtin
{
	char	*name;
	int		(*fun)(char **, char **);
}				t_builtin;

#endif
