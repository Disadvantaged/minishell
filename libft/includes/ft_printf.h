/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgolear <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 16:02:48 by dgolear           #+#    #+#             */
/*   Updated: 2017/03/05 11:13:54 by dgolear          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <wchar.h>

# define BLACK "\x1b[30m"
# define RED "\x1b[31m"
# define GREEN "\x1b[32m"
# define YELLOW "\x1b[33m"
# define BLUE "\x1b[34m"
# define MAGENTA "\x1b[35m"
# define CYAN "\x1b[36m"
# define WHITE "\x1b[37m"
# define RESET "\x1b[0m"
# define NO_PRECISION -1
# define NO_COLOR -1

typedef struct	s_flag
{
	char	symbol;
	int		sign;
}				t_flag;

typedef	enum	e_length
{
	hh,
	h,
	ll,
	l,
	L,
	j,
	z,
	no_length
}				t_length;

typedef struct	s_param
{
	t_flag		*flags;
	int			precision;
	int			width;
	t_length	mod;

}				t_param;

typedef	struct	s_conv
{
	char	spec;
	int		(*fun)(t_param *, va_list, char);
}				t_conv;

int				print_sign(intmax_t val, t_param *params);
int				print_appendix(t_param *params, char letter, char *value,
		int *width);
int				conversion(const char *f, int *pos, t_param *param, va_list ap);
int				ft_printf(const char *format, ...);
int				check(const char *format, int *pos, va_list ap);
t_flag			*check_flags(const char *format, int *pos);
t_flag			*create_flag(void);
int				check_precision(const char *format, int *pos, va_list ap);
int				check_width(const char *format, int *pos, va_list ap);
t_length		check_length(const char *format, int *pos);
int				print_int(t_param *params, va_list ap, char letter);
int				print_string(t_param *params, va_list ap, char letter);
int				print_wstring(t_param *params, va_list ap, char letter);
int				print_percent(t_param *params, va_list ap, char letter);
int				print_len(t_param *params, va_list ap, char letter);
int				print_char(t_param *params, va_list ap, char letter);
int				print_wchar(t_param *params, va_list ap, char letter);
int				print_adress(t_param *params, va_list ap, char letter);
int				print_unsigned(t_param *params, va_list ap, char letter);
int				find_color(const char *format, int *i);
int				enable_color(char *str);
int				ft_dprintf(int fd, const char *format, ...);
int				ft_vdprintf(int fd, const char *format, va_list ap);

extern int		g_fd;

#endif
