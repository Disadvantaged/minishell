/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgolear <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 09:44:19 by dgolear           #+#    #+#             */
/*   Updated: 2017/03/05 11:13:47 by dgolear          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <fcntl.h>

int				ft_printf(const char *format, ...);
int				get_next_line(int fd, char **line);
void			ft_puttab(char **s);
void			ft_puterr(char *s);
void			*ft_memset(void *s, int c, size_t n);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memccpy(void *dest, const void *src, int c, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
size_t			ft_strlen(const char *s);
size_t			ft_wstrlen(const wchar_t *s);
int				ft_nbrlen(intmax_t n);
char			*ft_strdup(const char *str);
char			*ft_strndup(const char *s, size_t n);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strncpy(char *dst, const char *src, size_t n);
char			*ft_strcat(char *dst, const char *src);
char			*ft_strncat(char *dst, const char *src, size_t n);
size_t			ft_strlcat(char *dst, const char *src, size_t n);
char			*ft_strchr(const char *str, int c);
char			*ft_strrchr(const char *str, int c);
char			*ft_strstr(const char *haystack, const char *needle);
char			*ft_strnstr(const char *s2, const char *s1, size_t len);
int				ft_strcmp(const void *s1, const void *s2);
int				ft_intcmp(const void *s1, const void *s2);
int				ft_strncmp(const void *s1, const void *s2, size_t n);
int				ft_atoi(const char *s);
char			*ft_unsigned_itoa_base(uintmax_t val, char *base);
int				ft_atoi_base(const char *s, int str_base);
int				ft_isalpha(int ch);
int				ft_isdigit(int ch);
int				ft_isalnum(int ch);
int				ft_isascii(int ch);
int				ft_isprint(int ch);
int				ft_isupper(int ch);
int				ft_isblank(int ch);
int				ft_islower(int ch);
int				ft_isspace(int ch);
int				ft_toupper(int c);
int				ft_tolower(int c);
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f) (unsigned int, char *));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s);
char			**ft_strsplit(char const *s, char c);
char			*ft_itoa(intmax_t n);
int				ft_putchar(char c);
int				ft_putwchar(wchar_t c);
int				ft_putstr(char const *s);
int				ft_putnwstr(wchar_t *s, int n);
int				ft_putnwstr_fd(wchar_t *s, int n, int fd);
int				ft_putnstr_fd(char *s, int n, int fd);
int				ft_putwstr(wchar_t *s);
int				ft_putendl(char const *s);
void			ft_putnbr(intmax_t n);
int				ft_putchar_fd(char c, int fd);
int				ft_putwchar_fd(wchar_t c, int fd);
int				ft_putstr_fd(char const *s, int fd);
int				ft_putwstr_fd(wchar_t *s, int fd);
int				ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(intmax_t n, int fd);
typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;
int				ft_lstsort(t_list **head, intmax_t
		(*compare)(const void *, const void *));
t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
int				ft_lstlen(t_list *lst);
void			ft_lstrev(t_list **head);
void			ft_lstaddlast(t_list **alst, t_list *new);
int				ft_dprintf(int fd, const char *format, ...);
int				ft_vdprintf(int fd, const char *format, va_list ap);

#endif
