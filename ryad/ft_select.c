/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkorimba <rkorimba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/05 11:37:37 by rkorimba          #+#    #+#             */
/*   Updated: 2014/01/08 15:03:20 by rkorimba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <termios.h>
#include <term.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include "libft.h"
#include "ft_select.h"

static t_data		*fill_list(int argc, char **argv)
{
	t_data			*root;
	t_data			*tmp;
	int				i;

	root = create_list();
	i = 0;
	tmp = root;
	while (i < argc - 1)
	{
		add_forward(tmp, argv[i + 1]);
		tmp = tmp->next;
		i++;
	}
	return (root);
}

static void			ft_exit(int i, struct termios term)
{
	term.c_lflag |= ICANON;
	term.c_lflag |= ECHO;
	tcsetattr(0, TCSANOW, &term);
	tputs(tgetstr("te", NULL), 1, ft_outc);
	tputs(tgetstr("ve", NULL), 1, ft_outc);
	exit(i);
}
/*
static void			adapt_size(void)
{
	struct winsize		win_size;

	ioctl(STDOUT_FILENO, TIOCGWINSZ, &win_size);

	ft_putnbr(win_size.ws_row);
	ft_putchar('\n');
	ft_putnbr(win_size.ws_row);
	ft_putchar('\n');

}
*/
static void			check_keyboard_action(t_data *tmp, struct termios term)
{
	char			buffer[3];

	while (1)
	{
		display_list(tmp);
		if (tmp->next == tmp)
				ft_exit(1, term);
		ft_bzero(buffer, 3);
		read(0, buffer, 3);
		if (buffer[0] == 127)
			delete_elem(tmp);
		else if (buffer[0] == 10 || buffer[0] == 13)
		{
			return_selected(tmp);
			ft_exit(1, term);
		}
		else if (buffer[0] == 32)
			selected(tmp);
		else if (buffer[0] == 27 && buffer[1] == 91 && buffer[2] == 65)
			prev_cursor(tmp);
		else if (buffer[0] == 27 && buffer[1] == 91 && buffer[2] == 66)
			next_cursor(tmp);
		else if (buffer[0] == 27)
			ft_exit(0, term);
	}
}

int					main(int argc, char **argv)
{
	t_data			*root;
	struct termios	term;

	if (tgetent(NULL, getenv("TERM")) != 1)
		return (-1);
	if (tcgetattr(0, &term) == -1)
		return (-1);
	term.c_lflag &= ~(ICANON);
	term.c_lflag &= ~(ECHO);
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSANOW, &term) == -1)
		return (-1);
	root = fill_list(argc, argv);
	root->next->cursor = 1;
	tputs(tgetstr("vi", NULL), 1, ft_outc);
	tputs(tgetstr("ti", NULL), 1, ft_outc);
//	adapt_size();
	check_keyboard_action(root, term);
	return (0);
}
