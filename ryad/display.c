/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlemort <mlemort@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/08 10:38:08 by mlemort           #+#    #+#             */
/*   Updated: 2014/01/08 14:56:27 by rkorimba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <term.h>
#include "libft.h"
#include "ft_select.h"

void            display_list(t_data* root)
{
	t_data      *tmp;

	tmp = root->next;
	tputs(tgetstr("cl", NULL), 1, ft_outc);
	while (tmp->index != 0)
	{
		if (tmp->cursor)
			tputs(tgetstr("us", NULL), 1, ft_outc);
		if (tmp->select)
			tputs(tgetstr("mr", NULL), 1, ft_outc);
		ft_putendl(tmp->data);
		tputs(tgetstr("me", NULL), 1, ft_outc);
		tmp = tmp->next;
	}
}

void			return_selected(t_data *root)
{
	t_data *tmp;

	tmp = root->next;
	tputs(tgetstr("cl", NULL), 1, ft_outc);
	while (tmp->index != 0)
	{
		if (tmp->select)
		{
			ft_putstr(tmp->data);
			ft_putchar('\n');
		}
		tmp = tmp->next;
	}
}

