/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 15:39:45 by tcasale           #+#    #+#             */
/*   Updated: 2023/02/19 14:36:02 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stddef.h>
# include <string.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

//Mandatory
void		*ft_memset(void *s, int c, size_t n);
void		ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t nmemb, size_t size);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);

int			ft_strlen(const char *s);
char		*ft_strdup(const char *s);
char		*ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlcpy(char *dest, const char *src, size_t n);
char		*ft_strcat(char *dest, const char *src);
char		*ft_strncat(char *s1, const char *s2, size_t n);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(char *s, int c);
char		*ft_strnstr(const char *haystack, const char *needle, size_t n);
int			ft_strcmp(char *s1, char *s2);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char		*ft_substr(char const *s, int start, int len);
char		*ft_strtrim(char const *s1, char const *set);
char		**ft_split(char const *s, char c);
void		ft_striteri(char *s, void (*f)(unsigned int, char *));

int			ft_atoi(const char *nptr);
char		*ft_itoa(int n);

int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
int			ft_toupper(int c);
int			ft_tolower(int c);

void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);

//Bonus 

void		ft_lstadd_front(t_list **alst, t_list *new);
t_list		*ft_lstlast(t_list *lst);
t_list		*ft_lstnew(void *content);
int			ft_lstsize(t_list *lst);
void		ft_lstadd_back(t_list **alst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del) (void *));
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

//Supplement
int			ft_putchar(char c);
int			ft_putstr(char *str);
int			ft_putnbr(int n);
int			ft_putnbr_unsigned(int n);
int			ft_putadress(unsigned long long n);
int			ft_puthexa_upper(long long n);
int			ft_puthexa_lower(long long n);

//str utils
//Renvoie 1 si str commence par start
int			ft_strstart(char *str, char *start);
//Supprime les espaces et les tabs au debut et a la fin de str
char		*ft_strclear(char *str);

//array utils
char		**ft_append_2d_char(char **array, char *new_el);

//malloc utils
int			**ft_malloc_2d_int(int x, int y);

//free utils
void		ft_free_2d_char(char **str);
void		ft_free_2d_int(int **array, int len);

int			ft_is_sort(int *tab, size_t lenght);

char		*ft_itoa_base(long long n, size_t base);
char		*ft_itoa_unsigned(int n);
char		*ft_itoa_adress(unsigned long long n);

#endif
