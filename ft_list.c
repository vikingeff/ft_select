/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleger <gleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/08 17:54:40 by gleger            #+#    #+#             */
/*   Updated: 2014/01/12 22:29:02 by gleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

t_link	*make_list(size_t nb_link, char **list)
{
	t_link	*list_chain;
	t_link	*list_first;
	size_t	loop;

	loop = 1;
	while (loop < nb_link)
	{
		if (loop == 1)
		{
			list_chain = ft_lstnew(*(list + loop));
			list_chain->cursor = 1;
			list_first = list_chain;
		}
		else
			list_chain = ft_lstadd(*(list + loop), list_chain);
		if (list_chain == NULL)
			return (NULL);
		loop++;
	}
	list_chain->next = list_first;
	list_first->prev = list_chain;
	return (list_first);
}

t_link	*ft_lstadd(const char *data, t_link *prev)
{
	t_link	*link;

	link = ft_lstnew(data);
	prev->next = link;
	link->prev = prev;
	link->index = prev->index + 1;
	return (link);
}

t_link	*ft_lstnew(const char *data)
{
	t_link	*link;

	if ((link = malloc(sizeof(t_link))) == NULL)
		return (NULL);
	if (data == NULL)
		return (NULL);
	link->data = ft_strdup(data);
	link->next = NULL;
	link->prev = NULL;
	link->index = 0;
	link->selected = 0;
	link->cursor = 0;
	return (link);
}

void	print_list(t_link *first_link)
{
	int	index;

	index = first_link->next->index;
	while (index != 0)
	{
		ft_putendl(first_link->data);
		first_link = first_link->next;
		index = first_link->index;
	}
}