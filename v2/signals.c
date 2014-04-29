/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleger <gleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/11 18:54:25 by gleger            #+#    #+#             */
/*   Updated: 2014/04/29 10:05:10 by gleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

void	ft_select_control_z(int i)
{
	char	cp[2];
	t_sing	*select;

	if (isatty(1))
	{
		select = ft_get_instance();
		cp[0] = select->term.c_cc[VSUSP];
		cp[1] = 0;
		tputs(tgetstr("ke", NULL), 1, ft_putchar);
		tputs(tgetstr("te", NULL), 1, ft_putchar);
		signal(SIGTSTP, SIG_DFL);
		ioctl(0, TIOCSTI, cp);
		(void)i;
	}
}

void	ft_select_fg(int i)
{
	t_sing	*select;

	select = ft_get_instance();
	tputs(tgetstr("ti", NULL), 1, ft_putchar);
	tputs(tgetstr("ks", NULL), 1, ft_putchar);
	tcsetattr(0, 0, &select->term);
	signal(SIGTSTP, ft_select_control_z);
	ft_write_list(select->arg, select->arg->head, select->term, select->node);
	(void)i;
}

void	ft_resize(int i)
{
	t_sing	*sing;

	tputs(tgoto(tgetstr("cm", NULL), 0, 0), 1, ft_putchar);
	tputs(tgetstr("cd", NULL), 1, ft_putchar);
	sing = (t_sing *)ft_get_instance();
	ft_write_list(sing->arg, sing->arg->head, sing->term, sing->node);
	(void)i;
}

void	ft_exit_signal(int i)
{
	t_sing	*sing;

	sing = (t_sing *)ft_get_instance();
	ft_exit(sing->arg, sing->term);
	tputs(tgetstr("ke", NULL), 1, ft_putchar);
	(void)i;
}
