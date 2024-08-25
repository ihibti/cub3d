/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanypar <chanypar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 09:35:10 by ihibti            #+#    #+#             */
/*   Updated: 2024/07/16 18:12:37 by chanypar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <limits.h>
# include <stdarg.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int					ft_atoi(const char *str);
void				ft_bzero(void *ptr, int i);
void				*ft_calloc(size_t elementCount, size_t elementsize);
int					ft_isalnum(int c);
int					ft_isalpha(int lett);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
char				*ft_itoa(int n);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstdelone(t_list *lst, void (*del)(void *));
t_list				*ft_lstlast(t_list *lst);
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstnew(void *content);
int					ft_lstsize(t_list *lst);
void				*ft_memchr(const void *memoryBlock, int searchedChar,
						size_t size);
int					ft_memcmp(const void *ptr1, const void *ptr2, size_t size);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t size);
void				*ft_memset(void *b, int c, size_t len);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr_fd(char *s, int fd);
char				**ft_split(char const *str, char c);
char				*ft_strchr(const char *string, int searchedchar);
char				*ft_strdup(const char *str);
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
size_t				ft_strlcpy(char *dest, const char *src, unsigned int size);
int					ft_strlen(const char *str);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strncmp(const char *first, const char *second,
						size_t length);
int					ft_strcmp(const char *first, const char *second);
char				*ft_strnstr(const char *big, const char *small,
						size_t size);
char				*ft_strrchr(const char *string, int searchedchar);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_substr(char const *s, unsigned int start, size_t len);
int					ft_tolower(int c);
int					ft_toupper(int c);
int					ft_printf(const char *format, ...);
int					ft_printsr(char *str);
int					ft_printchar(int c);
int					ft_distrib(va_list args, char c);
void				ft_pri_sign(int number, int *count);
void				conv_hex(int n, int *count, int flag);
int					print_unsi(unsigned int number);
void				put_unsigned(unsigned int number, int *count);
void				put_uint(uint64_t number, int *count);
int					print_ptr(void *ptr);
void				init_printf(int *i, int *len);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 45
# endif

char				*distrib(char *ret, char *reste, char *acquired);
char				*re_alloc(char *ret, char *acquired);
int					init_gnl(char **ret, char **acquired, int *fd, char *reste);
int					pos_nl(char *str);
int					acquisition(char *acquired, int fd);
char				*get_next_line(int fd);
char				*rest_manager(char *reste, char *ret);
char				*return_manag(char **acquired, char **ret);

#endif