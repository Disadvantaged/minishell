/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgolear <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 10:28:30 by dgolear           #+#    #+#             */
/*   Updated: 2017/03/31 12:43:31 by dgolear          ###   ########.fr       */
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

int				launch(char **args, char **env);
char			**readline(void);
void			free_args(char **args);
int				minishell_loop(char **env, char **commands);
int				execute(char **args, char **env);
int				b_exit(char **args, char **env);
int				b_cd(char **args, char **env);
int				b_echo(char **args, char **env);
int				b_setenv(char **args, char **env);
int				b_unsetenv(char **args, char **env);
int				b_env(char **args, char **env);
int				b_pwd(char **args, char **env);
void			signal_handler(int	flag);
void			trap(int sig);
void			set_var(char *name, char *value, char **env);
void			print_env(char **env);
int				num_args(char **args);
char			*ft_getenv(char *name, char **env);
char			**copy_env(char **env);
int				find_var(char *buf, char **env);

typedef struct	s_builtin
{
	char	*name;
	int		(*fun)(char **, char **);
}				t_builtin;

extern char		**g_env;

#endif
