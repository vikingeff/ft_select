/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleger <gleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/05 16:55:39 by gleger            #+#    #+#             */
/*   Updated: 2014/01/12 22:44:21 by gleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>
#include <stdio.h>

void	make_menu(t_link *first_link)
{
	int	index;

	index = first_link->next->index;
	tputs(tgetstr("cl", NULL), 0, tputs_putchar);
	while (index != 0)
	{
		if (first_link->cursor)
			tputs(tgetstr("us", NULL), 1, tputs_putchar);
		if (first_link->selected)
			tputs(tgetstr("mr", NULL), 1, tputs_putchar);
		ft_putendl(first_link->data);
		tputs(tgetstr("me", NULL), 1, tputs_putchar);
		first_link = first_link->next;
		index = first_link->index;
	}
}

int	ft_init_term(struct termios *term)
{
	char	*txt;
	char	buff_env[BUFF_SIZE];

	if ((txt = getenv("TERM")) == NULL)
		return (-1);
	ft_bzero(buff_env, BUFF_SIZE);
	if (tgetent(buff_env, txt) < 1)
		return (-1);
	if (tcgetattr(0, term) == -1)
		return (-1);
	term->c_lflag &= ~(ICANON);
	term->c_lflag &= ~(ECHO);
	term->c_cc[VMIN] = 1;
	term->c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSANOW, term) == -1)
		return (-1);
	tputs(tgetstr("cl", NULL), 0, tputs_putchar);
	return (0);
}

int	ft_reset_term(struct termios term)
{
	if (tcgetattr(0, &term) == -1)
		return (-1);
	term.c_lflag = (ICANON | ECHO);
	if (tcsetattr(0, 0, &term) == -1)
		return (-1);
	tputs(tgetstr("ve", NULL), 1, tputs_putchar);
	tputs(tgetstr("te", NULL), 1, tputs_putchar);
	return (0);
}

t_link	*ft_keycatch(t_link *list_cursor)
{
	char	buffer[3];

	ft_bzero(buffer, 3);
	read(0, buffer, 3);
	if (UP)
	{
		list_cursor->prev->cursor = 0;
		list_cursor->cursor = 1;
	}
	else if (DOWN)
	{
		list_cursor->prev->cursor = 0;
		list_cursor->cursor = 1;
	}
	else if (SPACE)
	{
		if (list_cursor->selected == 1)
			list_cursor->selected = 0;
		else
			list_cursor->selected = 1;
	}
	else if (ESCAPE)
		return (NULL);
	return (find_first(list_cursor));
}

int	ft_select(t_link *list_first)
{
	t_link	*ret;
	struct termios	term;
	int	height;
	int	width;

	if ((height = ft_init_term(&term)) == -1)
		return (-1);
	while (1)
	{
		height = tgetnum ("li");
		width = tgetnum ("co");
		make_menu(find_first(list_first));
		ret = ft_keycatch(find_cursor(list_first));
		if (ret == NULL)
		{
			ft_reset_term(term);
			return (-1);
		}
	}
	if ((height = ft_reset_term(term)) == -1)
		return (-1);
	return (0);
}
