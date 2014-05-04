/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleger <gleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/07 15:33:59 by gleger            #+#    #+#             */
/*   Updated: 2014/04/29 10:08:33 by gleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

static void		ft_dlist_funct_destroy(void *data)
{
	(void)data;
}

void			ft_dlist_init(t_dlist *list)
{
	ft_memset(list, 0, sizeof(*list));
	list->ft_dlist_destroy = ft_dlist_funct_destroy;
}

t_dlist			*ft_dlist_new(void)
{
	t_dlist	*new;

	new = (t_dlist *)malloc(sizeof(*new));
	if (new != NULL)
	{
		new->size = 0;
		new->head = NULL;
		new->tail = NULL;
	}
	return (new);
}

t_dlist_node	*ft_dlist_create(t_dlist_node *prev, t_dlist_node *next,
					void *data)
{
	t_dlist_node	*new;

	new = (t_dlist_node *)malloc(sizeof(*new));
	if (new != NULL)
	{
		new->next = next;
		new->prev = prev;
		new->data = data;
	}
	return (new);
}

t_dlist			*ft_dlist_add_tail(t_dlist *list, void *data)
{
	t_dlist_node	*new;

	if (list == NULL)
		return (NULL);
	new = (t_dlist_node *)malloc(sizeof(*new));
	if (new == NULL)
		return (NULL);
	new->data = data;
	new->sel = 0;
	if (list->tail == NULL)
	{
		new->prev = new;
		list->head = new;
		list->tail = new;
	}
	else
	{
		list->tail->next = new;
		new->prev = list->tail;
		list->tail = new;
	}
	new->next = list->head;
	list->head->prev = new;
	list->size = list->size + 1;
	return (list);
}
