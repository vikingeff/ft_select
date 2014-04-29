/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleger <gleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/11 18:36:26 by gleger            #+#    #+#             */
/*   Updated: 2014/04/29 10:08:53 by gleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

char			*ft_init_buffer(char *read_char)
{
	read_char[0] = 0;
	read_char[1] = 0;
	read_char[2] = 0;
	read_char[3] = 0;
	return (read_char);
}

void			*ft_get_instance(void)
{
	static t_sing	*inst = NULL;

	if (inst == NULL)
		inst = (t_sing *)malloc(sizeof(*inst));
	return (inst);
}

void			ft_del_instance(void)
{
	free(ft_get_instance());
}

t_dlist_node	*ft_loop_keys(t_dlist *arg, t_dlist_node *node,
					char *read_char)
{
	if (read_char[2] == 'A')
		node = ft_go_up(arg, node);
	else if (read_char[2] == 'B')
		node = ft_go_down(arg, node);
	else if (read_char[0] == ' ')
		node = ft_select_arg(arg, node);
	return (node);
}

void			ft_loop(t_dlist *arg, t_dlist_node *node, char *read_char,
				struct termios term)
{
	while (1)
	{
		((t_sing *)ft_get_instance())->node = node;
		read_char = ft_init_buffer(read_char);
		tputs(tgetstr("ks", NULL), 1, ft_putchar);
		read(0, read_char, 4);
		tputs(tgetstr("ke", NULL), 1, ft_putchar);
		if (arg->index == (int)arg->size && (read_char[2] == 'A'
					|| read_char[2] == 'B' || (read_char[2] == '3'
						&& read_char[3] == '~') || read_char[0] == 127
					|| read_char[0] == ' ' || read_char[0] == 10))
		{
			node = ft_loop_keys(arg, node, read_char);
			if ((read_char[3] == '~') || read_char[0] == 127)
				break ;
			else if (read_char[0] == 10)
			{
				ft_return(arg, term);
				return ;
			}
		}
		else if (read_char[0] == 033 || read_char[0] == 4)
			ft_exit_esc(term, read_char, arg);
	}
	ft_del_arg(arg, node, term);
}
