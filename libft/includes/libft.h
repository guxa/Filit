/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguleski <jguleski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 19:05:04 by jguleski          #+#    #+#             */
/*   Updated: 2018/11/02 16:44:10 by jguleski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdarg.h>
# include <fcntl.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <dirent.h>
# include <stdio.h>
# include <ctype.h>
# include <errno.h>
# include <sys/acl.h>
# include <sys/xattr.h>
# include <limits.h>

# define BUF_SIZE 20

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

void			ft_putnbr(int nb);
char			*ft_itoa(int n);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
t_list			*ft_lstnew(void const *content, size_t content_size);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
int				ft_strequ(char const *s1, char const *s2);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_strmap(char const *s, char (*f)(char));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
void			ft_striter(char *s, void (*f)(char *));
void			ft_strclr(char *s);
void			ft_strdel(char **as);
void			*ft_memalloc(size_t size);
void			ft_putendl_fd(char const *str, int fd);
void			ft_putendl(char const *str);
void			ft_putnbr_fd(int nb, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putchar_fd(char c, int fd);
char			*ft_strtrim(char const *s);
char			**ft_strsplit(char const *s, char c);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_isprint(int c);
int				ft_isascii(int c);
int				ft_isalpha(int c);
int				ft_isalnum(int c);
char			*ft_strnstr(const char *location, const char *target,
						size_t len);
char			*ft_strncat(char *restrict s1, const char *restrict s2,
						size_t n);
size_t			ft_strlcat(char *restrict dst, const char *restrict src,
						size_t dstsize);
char			*ft_strrchr(const char *s, int c);

int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memccpy(void *restrict dst, const void *restrict src, int c,
						size_t n);
void			*ft_memcpy(void *restrict dst, const void *restrict src,
						size_t n);
void			ft_bzero(void *s, size_t n);
void			ft_memdel(void **ap);
char			*ft_strjoin(const char *str1, const char *str2);
char			*ft_strcat(char *dest, const char *string);

char			*ft_itoa_base(long number, int base);

int				b_printf(const char *format, ...);
int				numberhandler(void *number, char type);
int				myprinter(const char *str, int start, int end);
int				findarg(const char *format, va_list ap);
int				is_vartype(char c);
int				parser(const char *format, va_list ap);
char			*cutstr(char const *inputstr, int start, int end);
char			*ft_strnew(size_t size);
int				countdigits(long number, int base);
int				myatoi_base(const char *str, int str_base);

void			ft_putstr(char *str);
void			ft_putchar(int c);
int				ft_atoi(char *str);

char			*ft_strstr(const char *location, const char *target);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strncpy(char *dst, const char *src, size_t len);
size_t			ft_strlen(const char *s);
char			*ft_strdup(const char *s1);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_strchr(const char *s, int c);
int				ft_isdigit(int c);
int				ft_tolower(int c);
int				ft_toupper(int c);
void			*ft_memset(void *b, int c, size_t len);

#endif
