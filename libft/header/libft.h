/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcazac <pcazac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 10:55:38 by pcazac            #+#    #+#             */
/*   Updated: 2023/06/19 14:24:57 by pcazac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef struct d_list
{
	struct d_list	*prev;
	struct d_list	*next;
	struct d_list	*end;
	struct d_list	*pos;
	int				index;
	int				number;
	int				cm_up;
	int				cm_down;
	int				cm_mv;
	int				mv_up;
	int				mv_down;
	int				mv;
	int				rest_up;
	int				rest_down;
	int				pos_up;
	int				pos_down;
	int				cm_dir;
	int				dir;
}					t_dlist;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 20
# endif

void	ft_dlstclear(t_dlist **lst);
void	ft_dlstadd_back(t_dlist **lst, t_dlist *new);
t_dlist	*ft_dlstnew(int content);
char	*get_next_line(int fd);
int		line_end(char *buff);
char	*ft_calloc_gnl(char **return_line, int *count, char *static_buffer);
void	clean_the_buff(char *buff);
char	*ft_bzero_gnl(char *str, int size);
void	copy_buff(char *static_buffer, char *temp_buffer);
char	*ft_treat(char *return_line);
int		ft_isalpha(int d);
int		ft_isdigit(int c);
int		ft_isalnum( int i);
int		ft_isascii(int a);
int		ft_isprint(int c);
size_t	ft_strlen(const char *c);
void	ft_bzero(void *c, size_t n);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
long	ft_atoi(const char *str);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strjoin(char const *s1, char const *s2);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
int		ft_printf(const char *format, ...);
int		ft_putstr_pf(char *s, int *count);
int		ft_strlen_pf(const char *c);
int		ft_putchar_pf(char c, int *counter);
int		putbase_pf(size_t input, char *base, size_t b_len, int *count);
int		ft_strcmp(const char *s1, const char *s2);

#endif
