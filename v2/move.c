/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleger <gleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/11 18:01:56 by gleger            #+#    #+#             */
/*   Updated: 2014/04/29 10:04:59 by gleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

void			ft_desunderline(t_dlist *arg, t_dlist_node *node)
{
	int	j;

	j = 0;
	while (j != 3)
	{
		tputs(tgetstr("nd", NULL), 1, ft_putchar);
		j = j + 1;
	}
	if (node->sel == 1)
		tputs(tgetstr("mr", NULL), 1, ft_putchar);
	j += ft_strlen(node->data);
	write(arg->fd, node->data, ft_strlen(node->data));
	if (node->sel == 1)
		tputs(tgetstr("me", NULL), 1, ft_putchar);
	while (j != 0)
	{
		tputs(tgetstr("le", NULL), 1, ft_putchar);
		j = j - 1;
	}
}

void			ft_underline(t_dlist *arg, t_dlist_node *node)
{
	int	j;

	j = 0;
	while (j != 3)
	{
		tputs(tgetstr("nd", NULL), 1, ft_putchar);
		j = j + 1;
	}
	tputs(tgetstr("us", NULL), 1, ft_putchar);
	if (node->sel == 1)
		tputs(tgetstr("mr", NULL), 1, ft_putchar);
	j += ft_strlen(node->data);
	write(arg->fd, node->data, ft_strlen(node->data));
	if (node->sel == 1)
		tputs(tgetstr("me", NULL), 1, ft_putchar);
	tputs(tgetstr("ue", NULL), 1, ft_putchar);
	tputs(tgoto(tgetstr("cm", NULL), node->pos_x, node->pos_y),
			1, ft_putchar);
}

t_dlist_node	*ft_go_up(t_dlist *arg, t_dlist_node *node)
{
	ft_desunderline(arg, node);
	node = node->prev;
	tputs(tgoto(tgetstr("cm", NULL), node->pos_x, node->pos_y),
			1, ft_putchar);
	ft_underline(arg, node);
	return (node);
}

t_dlist_node	*ft_go_down(t_dlist *arg, t_dlist_node *node)
{
	ft_desunderline(arg, node);
	node = node->next;
	tputs(tgoto(tgetstr("cm", NULL), node->pos_x, node->pos_y),
			1, ft_putchar);
	ft_underline(arg, node);
	return (node);
}
