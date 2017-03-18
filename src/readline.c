/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgolear <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 12:22:19 by dgolear           #+#    #+#             */
/*   Updated: 2017/03/09 15:55:35 by dgolear          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_line(void)
{
	char	*line;
	int		flag;

	flag = get_next_line(0, &line);
	if (flag == -1)
	{
		ft_dprintf(2, "minishell: Error with reading line from stdin\n");
		exit(-1);
	}
	else if (flag == 0)
	{
		ft_printf("\n");
		exit (0);
	}
	else
		return (line);
}

char	**realloc_array(char **args, int max_size)
{
	int		i;
	char	**temp;

	i = 0;
	if ((temp = (char **)malloc(sizeof(char *) * max_size * 2)) == NULL)
	{
		ft_dprintf(2, "minishell: Memory allocation error");
		exit(-1);
	}
	while (i < max_size)
	{
		temp[i] = args[i];
		i++;
	}
	free(args);
	return (temp);
}

char	**split_line(char *line)
{
	char	*tmp;
	char	**args;
	int		max_size;
	int		i;

	i = 1;
	max_size = 10;
	if ((args = (char **)malloc(sizeof(char *) * 10)) == NULL)
		exit (-1 + 0 * ft_dprintf(2, "minishell: Memory allocation error\n"));
	tmp = line;
	if ((args[0] = ft_strdup(ft_strtok_r(tmp, " \n\t\b\a", &tmp))) == NULL)
	{
		free(args);
		return (NULL);
	}
	while ((args[i] = ft_strdup(ft_strtok_r(NULL, " \n\t\b\a", &tmp))) != NULL)
		if (++i == max_size)
		{
			args = realloc_array(args, max_size);
			max_size *= 2;
		}
	args[i] = NULL;
	return (args);
}

char	**readline(void)
{
	char	*line;
	char	**args;

	line = get_line();
	if (line[0] == '\0' || line[1] == '\0')
	{
		ft_strdel(&line);
		return (NULL);
	}
	args = split_line(line);
	ft_strdel(&line);
	return (args);
}
