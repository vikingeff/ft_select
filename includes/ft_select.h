/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleger <gleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/05 13:53:58 by gleger            #+#    #+#             */
/*   Updated: 2014/01/12 20:08:30 by gleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <dirent.h>
# include <fcntl.h>
# include <termios.h>
# include <termcap.h>
# define BUFF_SIZE	4096
# define ESCAPE	buffer[0] == 27 && buffer[1] == 0 && buffer[2] == 0
# define SPACE	buffer[0] == 32 && buffer[1] == 0 && buffer[2] == 0
# define UP	buffer[0] == 27 && buffer[1] == 91 && buffer[2] == 65
# define LEFT	buffer[0] == 27 && buffer[1] == 91 && buffer[2] == 68
# define RIGHT	buffer[0] == 27 && buffer[1] == 91 && buffer[2] == 67
# define DOWN	buffer[0] == 27 && buffer[1] == 91 && buffer[2] == 66
# define RETURN	10
# define DELETE	127
# define BACKSPACE	2117294875

typedef struct		s_link
{
	char			*data;
	int				index;
	int				select;
	struct s_link	*next;
	struct s_link	*prev;
}					t_link;

void	show_usage(void);
t_link	*make_list(size_t nb_link, char **list);
t_link	*ft_lstnew(const char *data);//, size_t data_size);
t_link	*ft_lstadd(const char *data,  t_link *prev);
void	print_list(t_link *first_link);
int		ft_init_term(struct termios *term);
int		ft_reset_term(struct termios term);
char	*ft_keycatch(void);
size_t	ft_strlen(const char *str);
void	ft_putchar(const char c);
int 	tputs_putchar(int c);
void	ft_putstr(const char *str);
void	ft_puterr(char *str);
void	ft_putendl(const char *str);
void	ft_putendl_fd(char const *str, int fd);
void	ft_putstr_fd(char const *str, int fd);
void	ft_putchar_fd(char c, int fd);
//int		ft_select(int nb_list, char **list);
void	ft_select(t_link *list_first);
void	ft_print(int size, char ** list);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_strdup(const char *s1);
void	*ft_malloc(int size);
void	ft_free(void *ptr);

#endif
