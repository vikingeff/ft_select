/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleger <gleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/07 15:26:31 by gleger            #+#    #+#             */
/*   Updated: 2014/04/29 10:09:15 by gleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

void			ft_dlist_clear(t_dlist *list)
{
	t_dlist_node	*cur;
	t_dlist_node	*del;

	cur = list->head;
	while (cur != NULL)
	{
		del = cur;
		cur = cur->next;
		list->ft_dlist_destroy(del->data);
		free(del);
	}
	ft_dlist_init(list);
}

void			ft_dlist_destroy(t_dlist *list)
{
	ft_dlist_clear(list);
	list->ft_dlist_destroy = NULL;
}

void			ft_dlist_del(t_dlist_node *node, t_dlist *list)
{
	if (list == NULL || node == NULL)
		return ;
	if (list->tail == node)
		list->tail = node->prev;
	if (node->next != NULL)
		node->next->prev = node->prev;
	if (list->head == node)
		list->head = node->next;
	if (node->prev != NULL)
		node->prev->next = node->next;
	free (node);
	list->size = list->size - 1;
}

t_dlist_node	*ft_dlist_delete(t_dlist *list, t_dlist_node *node)
{
	void			*del;
	t_dlist_node	*ret;

	ret = ft_dlist_erase(list, node, &del);
	list->ft_dlist_destroy(del);
	free(node);
	return (ret);
}

t_dlist_node	*ft_dlist_erase(t_dlist *list, t_dlist_node *erase,
					void **data)
{
	t_dlist_node	*ret;

	ret = erase->next;
	if (data != NULL)
		*data = erase->data;
	if (erase == list->head)
		list->head = ret;
	else if (erase == list->tail)
		list->tail = erase->prev;
	if (erase->prev != NULL)
		erase->prev->next = erase->next;
	if (erase->next != NULL)
		erase->next->prev = erase->prev;
	free(erase);
	list->size = list->size - 1;
	return (ret);
}
