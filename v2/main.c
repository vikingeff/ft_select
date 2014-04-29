/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleger <gleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/06 13:50:17 by gleger            #+#    #+#             */
/*   Updated: 2014/04/29 10:04:41 by gleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

void	ft_write_list(t_dlist *arg, t_dlist_node *node,
			struct termios term, t_dlist_node *ls_n)
{
	arg->index = -1;
	arg->line = 0;
	arg->cur_col = 1;
	node = ft_write_start(arg, node, term);
	while (++arg->index != (int)arg->size)
	{
		if (tgetnum("li") <= 2)
		{
			ft_terminal_small(arg);
			break ;
		}
		ft_calc_size(arg, node);
		if (arg->cur_col + arg->size_col > tgetnum("co") && arg->cur_col != 1)
		{
			ft_terminal_small(arg);
			break ;
		}
		if (arg->line == 0 && arg->cur_col != 1)
			arg->size_col = 0;
		arg->line = ft_define_x_y(arg, node, arg->line, arg->cur_col);
		node = ft_write_line(arg, node);
	}
	tputs(tgoto(tgetstr("cm", NULL), ls_n->pos_x, ls_n->pos_y), 1, ft_putchar);
	if (arg->index == (int)arg->size)
		ft_underline(arg, ls_n);
}

void	ft_select(t_dlist *arg, struct termios term)
{
	char			read_char[4];
	t_dlist_node	*node;

	signal(SIGWINCH, ft_resize);
	signal(SIGTSTP, ft_select_control_z);
	signal(SIGCONT, ft_select_fg);
	signal(SIGINT, ft_exit_signal);
	signal(SIGQUIT, ft_exit_signal);
	((t_sing *)ft_get_instance())->arg = arg;
	((t_sing *)ft_get_instance())->term = term;
	node = arg->head;
	ft_write_list(arg, node, term, node);
	node = arg->head;
	ft_underline(arg, node);
	ft_loop(arg, node, read_char, term);
}

void	ft_init_arg(t_dlist *arg, char **av, int ac)
{
	int	i;

	ft_dlist_init(arg);
	i = 0;
	while (++i < ac)
		ft_dlist_add_tail(arg, av[i]);
}

int		main(int ac, char **av)
{
	char			*name_term;
	struct termios	term;
	t_dlist			*arg;

	if (ac == 1)
		return (0);
	arg = ft_dlist_new();
	ft_init_arg(arg, av, ac);
	if ((name_term = getenv("TERM")) == NULL)
		return (-1);
	if (tgetent(NULL, name_term) == -1)
		return (-1);
	if (tcgetattr(0, &term) == -1)
		return (-1);
	tputs(tgetstr("ti", NULL), 1, ft_putchar);
	term.c_lflag &= ~(ICANON | ECHO);
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSADRAIN, &term) == -1)
		return (-1);
	if ((arg->fd = open("/dev/tty", O_RDWR) == -1))
		return (-1);
	ft_select(arg, term);
	close(arg->fd);
	return (0);
}
