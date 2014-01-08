/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_modifier.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlemort <mlemort@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/08 10:42:11 by mlemort           #+#    #+#             */
/*   Updated: 2014/01/08 10:42:22 by mlemort          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <term.h>
#include "libft.h"
#include "ft_select.h"

void			next_cursor(t_data *root)
{
	t_data		*tmp;

	tmp = root->next;
	if (tmp->prev->prev->cursor && tmp->prev->index == 0)
	{
		tmp->prev->prev->cursor = 0;
		tmp->cursor = 1;
	}
	else
	{
		while (tmp->index != 0)
		{
			if (tmp->cursor)
			{
				tmp->cursor = 0;
				tmp->next->cursor = 1;
				tmp = tmp->next;
			}
			tmp = tmp->next;
		}
	}
}

void			prev_cursor(t_data *root)
{
	t_data		*tmp;

	tmp = root->next;
	if (tmp->cursor && tmp->prev->index == 0)
	{
		tmp->cursor = 0;
		tmp->prev->prev->cursor = 1;
	}
	else
	{
		while (tmp->index != 0)
		{
			if (tmp->next->cursor)
			{
				tmp->next->cursor = 0;
				tmp->cursor = 1;
				tmp = tmp->next;
			}
			tmp = tmp->next;
		}
	}
}

static int		selected_last(t_data *root)
{
	t_data		*tmp;

	tmp = root;
	if (tmp->prev->prev->cursor && tmp->prev->index == 0)
	{
		if (tmp->prev->prev->select == 1)
			tmp->prev->prev->select = 0;
		else
		{
			tmp->prev->prev->cursor = 0;
			tmp->prev->prev->select = 1;
			tmp->cursor = 1;
		}
		return (1);
	}
	return (0);
}

void			selected(t_data *root)
{
	t_data		*tmp;

	tmp = root->next;
	if (!selected_last(tmp))
	{
		while (tmp->index != 0)
		{
			if (tmp->cursor)
			{
				if (tmp->select == 1)
					tmp->select = 0;
				else
				{
					tmp->select = 1;
					tmp->cursor = 0;
					tmp->next->cursor = 1;
					tmp = tmp->next;
				}
			}
			tmp = tmp->next;
		}
	}
}

void			delete_elem(t_data *root)
{
	t_data		*tmp;

	tmp = root->next;
	if (root->next->cursor)
	{
		root->next->next->cursor = 1;
		del_first_elem(root);
	}
	else if (root->prev->cursor)
	{
		root->prev->prev->cursor = 1;
		del_last_elem(root);
	}
	else
	{
		while (tmp->index != 0)
		{
			if (tmp->cursor)
			{
				tmp->next->cursor = 1;
				del_elem(tmp);
				tmp = tmp->next;
			}
			tmp = tmp->next;
		}
	}
}
