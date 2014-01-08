/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleger <gleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/05 16:55:39 by gleger            #+#    #+#             */
/*   Updated: 2014/01/08 18:23:41 by gleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>
#include <stdio.h>

void	ft_print(int size, char ** list)
{
	int	loop;

	loop = 1;
	while (loop < size)
	{
		ft_putendl(*(list + loop));
		loop++;
	}
}

int	ft_init_term(struct termios *term)
{
	char	*txt;
	//struct termios	term;
	char	buff_env[BUFF_SIZE];

	if ((txt = getenv("TERM")) == NULL)
		return (-1);
	ft_bzero(buff_env, BUFF_SIZE);
	if (tgetent(buff_env, txt) < 1)
		return (-1);
	//printf("%s\n",buff_env);
	if (tcgetattr(0, term) == -1)
		return (-1);
	term->c_lflag &= ~(ICANON); // Met le terminal en mode canonique.
	term->c_lflag &= ~(ECHO); // les touches tapées ne s'inscriront plus dans le terminal
	term->c_cc[VMIN] = 1;
	term->c_cc[VTIME] = 0;
	// On applique les changements :
	if (tcsetattr(0, TCSADRAIN, term) == -1)
		return (-1);
	txt = tgetstr("cl", NULL);
	tputs(txt, 0, tputs_putchar);
	return (0);
}

int	ft_reset_term(struct termios term)
{
	if (tcgetattr(0, &term) == -1)
		return (-1);
	term.c_lflag = (ICANON | ECHO);
	if (tcsetattr(0, 0, &term) == -1)
		return (-1);
}

int	ft_select(int nb_list, char **list)
{
	//pid_t	pid_f;
	char	*txt;
	struct termios	term;
	char	buffer[3];
	//char	buff_env[BUFF_SIZE];
	int	height;
	int	width;

	if ((height = ft_init_term(&term)) == -1)
		return (-1);
	ft_print(nb_list, list);
	while (1)
	{
		//txt = getenv("TERM");
		height = tgetnum ("li");
		width = tgetnum ("co");
		ft_bzero(buffer, 3);
		read(0, buffer, 3);
		//printf("%d - %d - %d\n", buffer[0], buffer[1], buffer[2]);
		//printf("%d - %d\n", height, width);
		if (UP)
		{
			txt = tgetstr("up", NULL);
			tputs(txt, 0, tputs_putchar);
		}
		if (DOWN)
		{
			txt = tgetstr("do", NULL);
			tputs(txt, 0, tputs_putchar);
		}
		if (LEFT)
		{
			txt = tgetstr("le", NULL);
			tputs(txt, 0, tputs_putchar);
		}
		if (RIGHT)
		{
			txt = tgetstr("nd", NULL);
			tputs(txt, 0, tputs_putchar);
		}
		if (SPACE)
		{
			txt = tgetstr("uc", NULL);
			tputs(txt, 0, tputs_putchar);
		}
		if (ESCAPE)
			return (0);
	}
	if ((height = ft_reset_term(term)) == -1)
		return (-1);
	return (0);
}
