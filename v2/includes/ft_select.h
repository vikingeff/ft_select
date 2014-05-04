/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleger <gleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/03 11:02:43 by gleger            #+#    #+#             */
/*   Updated: 2014/05/04 13:54:35 by gleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include <termios.h>
# include <string.h>
# include <term.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <signal.h>
# include <sys/ioctl.h>

typedef struct			s_dlist
{
	size_t				size;
	struct s_dlist_node	*head;
	struct s_dlist_node	*tail;
	char				*ap;
	int					line;
	int					fd;
	int					index;
	int					cur_col;
	int					size_col;
	void				(*ft_dlist_destroy)(void *data);
}						t_dlist;

typedef struct			s_dlist_node
{
	struct s_dlist_node	*prev;
	struct s_dlist_node	*next;
	void				*data;
	int					pos_x;
	int					pos_y;
	int					nbr_lines;
	int					sel;
}						t_dlist_node;

typedef struct			s_sing
{
	t_dlist				*arg;
	struct termios		term;
	t_dlist_node		*node;
}						t_sing;

int				ft_putchar(int c);
int				ft_strlen(char *str);
void			ft_select(t_dlist *arg, struct termios term);
t_dlist			*ft_dlist_add_tail(t_dlist *list, void *data);
t_dlist_node	*ft_dlist_create(t_dlist_node *prev, t_dlist_node *next,
					void *data);
void			ft_dlist_del(t_dlist_node *node, t_dlist *list);
t_dlist_node	*ft_dlist_delete(t_dlist *list, t_dlist_node *node);
void			ft_dlist_init(t_dlist *list);
t_dlist			*ft_dlist_new(void);
t_dlist_node	*ft_dlist_erase(t_dlist *list, t_dlist_node *erase,
					void **data);
void			*ft_memset(void *b, int c, size_t len);
void			ft_memdel(void *ap);
void			ft_dlist_destroy(t_dlist *list);
void			ft_dlist_clear(t_dlist *list);
void			ft_exit_esc(struct termios term, char *read_char,
					t_dlist *arg);
void			ft_exit(t_dlist *arg, struct termios term);
void			ft_free_list(t_dlist *arg);
void			ft_return(t_dlist *arg, struct termios term);
void			ft_del_instance(void);
void			ft_desunderline(t_dlist *arg, t_dlist_node *node);
void			ft_underline(t_dlist *arg, t_dlist_node *node);
t_dlist_node	*ft_go_up(t_dlist *arg, t_dlist_node *node);
t_dlist_node	*ft_go_down(t_dlist *arg, t_dlist_node *node);
void			ft_del_arg(t_dlist *arg, t_dlist_node *node,
					struct termios term);
t_dlist_node	*ft_select_arg(t_dlist *arg, t_dlist_node *node);
void			ft_terminal_small(t_dlist *arg);
void			ft_calc_size(t_dlist *arg, t_dlist_node *node);
t_dlist_node	*ft_write_line(t_dlist *arg, t_dlist_node *node);
t_dlist_node	*ft_write_start(t_dlist *arg, t_dlist_node *node,
					struct termios term);
int				ft_define_x_y(t_dlist *arg, t_dlist_node *node, int line,
					int cur_col);
char			*ft_init_buffer(char *read_char);
void			*ft_get_instance(void);
void			ft_del_instance(void);
t_dlist_node	*ft_loop_keys(t_dlist *arg, t_dlist_node *node,
					char *read_char);
void			ft_loop(t_dlist *arg, t_dlist_node *node,
					char *read_char, struct termios term);
void			ft_select_control_z(int i);
void			ft_select_fg(int i);
void			ft_resize(int i);
void			ft_exit_signal(int i);
void			ft_write_list(t_dlist *arg, t_dlist_node *node,
					struct termios term, t_dlist_node *ls_n);

#endif
