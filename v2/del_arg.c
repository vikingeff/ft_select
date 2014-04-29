/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleger <gleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/11 18:13:17 by gleger            #+#    #+#             */
/*   Updated: 2014/04/29 10:03:53 by gleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

t_dlist_node	*ft_select_arg(t_dlist *arg, t_dlist_node *node)
{
	if (node->sel == 1)
	{
		node->sel = 0;
		write(arg->fd, " ", 1);
	}
	else
	{
		node->sel = 1;
		write(arg->fd, "X", 1);
	}
	tputs(tgetstr("le", NULL), 1, ft_putchar);
	ft_underline(arg, node);
	ft_desunderline(arg, node);
	node = node->next;
	tputs(tgoto(tgetstr("cm", NULL), node->pos_x, node->pos_y),
			1, ft_putchar);
	ft_underline(arg, node);
	return (node);
}

void			ft_del_arg(t_dlist *arg, t_dlist_node *node,
					struct termios term)
{
	int		i;

	i = 0;
	if (node == node->next)
	{
		write(arg->fd, "101\n", 4);
		arg->head = NULL;
		arg->tail = NULL;
		free(node);
		free(arg);
		ft_exit(NULL, term);
	}
	else
	{
		node->prev->next = node->next;
		node->next->prev = node->prev;
	}
	if (arg->tail == node)
		arg->tail = node->prev;
	if (arg->head == node)
		arg->head = node->next;
	arg->size--;
	free(node);
	ft_select(arg, term);
}
