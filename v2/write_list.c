/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleger <gleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/11 18:23:27 by gleger            #+#    #+#             */
/*   Updated: 2014/04/29 10:05:22 by gleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

int				ft_define_x_y(t_dlist *arg, t_dlist_node *node, int line,
					int cur_col)
{
	if (node != arg->head)
	{
		if (line != 0)
			line = line + node->prev->nbr_lines;
		else
			line = 2;
		node->pos_y = line;
	}
	else
	{
		node->pos_y = 2;
		line = 2;
	}
	node->pos_x = cur_col;
	return (line);
}

t_dlist_node	*ft_write_start(t_dlist *arg, t_dlist_node *node,
					struct termios term)
{
	char	*name_term;

	if ((name_term = getenv("TERM")) == NULL)
		ft_exit(arg, term);
	if (tgetent(NULL, name_term) == -1)
		ft_exit(arg, term);
	tputs(tgoto(tgetstr("cm", NULL), 0, 0), 1, ft_putchar);
	tputs(tgetstr("cd", NULL), 1, ft_putchar);
	write(arg->fd, "Make a choice !\n\n", 17);
	node = arg->head;
	return (node);
}

t_dlist_node	*ft_write_line(t_dlist *arg, t_dlist_node *node)
{
	tputs(tgoto(tgetstr("cm", NULL), node->pos_x - 1, node->pos_y),
			1, ft_putchar);
	if (node->sel == 1)
	{
		write(arg->fd, "\033[1;35;m[X] ", 4);
		tputs(tgetstr("mr", NULL), 1, ft_putchar);
		write(arg->fd, node->data, ft_strlen(node->data));
		tputs(tgetstr("me", NULL), 1, ft_putchar);
	}
	else
	{
		write(arg->fd, "[ ] ", 4);
		write(arg->fd, node->data, ft_strlen(node->data));
	}
	tputs(tgoto(tgetstr("cm", NULL), node->pos_x - 1,
				node->pos_y + node->nbr_lines), 1, ft_putchar);
	node = node->next;
	return (node);
}

void			ft_calc_size(t_dlist *arg, t_dlist_node *node)
{
	if ((ft_strlen(node->data) + 4) > tgetnum("co"))
		node->nbr_lines = 1 + (ft_strlen(node->data) + 4)
			/ (tgetnum("co") + 2);
	else
		node->nbr_lines = 1;
	if (arg->size_col < ft_strlen(node->data))
	{
		arg->size_col = ft_strlen(node->data) + 1;
	}
	if (tgetnum("li") <= arg->line + node->prev->nbr_lines)
	{
		arg->line = 0;
		if (arg->cur_col != 1)
			arg->cur_col++;
		arg->cur_col = arg->cur_col + arg->size_col + 6;
	}
}

void			ft_terminal_small(t_dlist *arg)
{
	tputs(tgoto(tgetstr("cm", NULL), 0, 0), 1, ft_putchar);
	tputs(tgetstr("cd", NULL), 1, ft_putchar);
	write(arg->fd, "The terminal is too small\n", 26);
}
