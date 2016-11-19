/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srodrigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 15:34:05 by srodrigu          #+#    #+#             */
/*   Updated: 2016/10/04 16:21:24 by srodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _LIBFT_H

# define _LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

void	ft_putnbr(int num);
void	ft_putstr(char *str);
void	ft_putchar(char c);
size_t	ft_strlen(const char *str);
char	*ft_strcpy(char *dest, char *src);
int		ft_isdigit(int d);
int		ft_atoi(const char *str);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strcat(char *dest, char *src);
int		ft_strcmp(const char *str1, const char *str2);
int		ft_isascii(int a);
int		ft_isalpha(int c);
int		ft_isalnum(int c);
int		ft_isprint(int c);
int		ft_isspace(int c);
char	*ft_itoa(int num);
char	*ft_strchr(const char *str, int c);
void	*ft_memset(void *str, int c, size_t length);
void	ft_bzero(void *str, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memccpy(void *dest, const void *src, int c, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memchr(const void *src, int c, size_t size);
int		ft_memcmp(const void *str1, const void *str2, size_t n);
char	*ft_strdup(char *str);
char	*ft_strncpy(char *str1, char *str2, size_t n);
char	*ft_strncat(char *dest, char *src, size_t n);
size_t	ft_strlcat(char *dest, char *src, size_t n);
char	*ft_strrchr(const char *cp, int ch);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strstr(const char *in, const char *str);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
void	*ft_memalloc(size_t size);
void	ft_memdel(void **ap);
char	*ft_strnew(size_t size);
void	ft_strdel(char **as);
void	ft_strclr(char *s);
void	ft_striter(char *s, void (*f)(char *));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
char	*ft_strmap(char const *s, char (*f)(char));
int		ft_strnequ(char const *s1, char const *s2, size_t n);
int		ft_strequ(char const *s1, char const *s2);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
char	*ft_strmapi(char const *str, char (*f)(unsigned int, char));
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s);
char	**ft_strsplit(char const *s, char c);
void	ft_putendl_fd(char const *s, int fd);
void	ft_putstr_fd(char const *s, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putendl(char const *s);
char	*ft_trim_newline(char *str);

#endif
