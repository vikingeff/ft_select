/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleger <gleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/11 17:48:25 by gleger            #+#    #+#             */
/*   Updated: 2014/05/04 13:58:32 by gleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

void			ft_free_list(t_dlist *arg)
{
	t_dlist_node	*node;
	int				i;

	i = 0;
	close(arg->fd);
	ft_del_instance();
	if (arg != NULL)
	{
		node = arg->head;
		while (++i != (int)arg->size)
		{
			node = node->next;
			free(node->prev);
		}
		free(node);
	}
	free(arg);
}

void			ft_exit(t_dlist *arg, struct termios term)
{
	if (arg != NULL)
		ft_free_list(arg);
	tputs(tgetstr("te", NULL), 1, ft_putchar);
	term.c_lflag = (ICANON | ECHO | ISIG | IEXTEN | ECHOE
			| ECHOK | ECHOKE | ECHOCTL);
	if (tcsetattr(0, 0, &term) == -1)
		exit(-1);
	exit(0);
}

void			ft_exit_esc(struct termios term, char *read_char, t_dlist *arg)
{
	if (read_char[2] == 'C' || read_char[2] == 'D' || read_char[2] == 'A'
			|| read_char[2] == 'B' || (read_char[2] == '3'
				&& read_char[3] == '~'))
		read_char[2] = 'C';
	else
		ft_exit(arg, term);
}

void			ft_putflags(struct termios term)
{
	term.c_lflag = (ICANON | ECHO | ISIG | IEXTEN | ECHOE | ECHOK 
		| ECHOKE | ECHOCTL);
}

void			ft_return(t_dlist *arg, struct termios term)
{
	int				i;
	int				j;
	t_dlist_node	*node;

	tputs(tgetstr("te", NULL), 1, ft_putchar);
	ft_putflags(term);
	if (tcsetattr(0, 0, &term) == -1)
		exit(-1);
	i = 0;
	j = 0;
	node = arg->head;
	while (i++ != (int)arg->size)
	{
		if (node->sel == 1)
		{
			write(1, node->data, ft_strlen(node->data));
			j++;
		}
		if (node->next->sel == 1 && node->next != arg->head && j != 0)
			write(1, " ", 1);
		node = node->next;
	}
	if (j != 0)
		write(1, "\n", 1);
	ft_free_list(arg);
}
