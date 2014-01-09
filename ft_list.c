/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleger <gleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/08 17:54:40 by gleger            #+#    #+#             */
/*   Updated: 2014/01/09 14:50:40 by gleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

void	make_list(int nb_link, char **list)
{
	t_link	*list_chain;
	size_t	loop;

	loop = 1;
	(void)nb_link;
	(void)list;
	(void)list_chain;
	/*while (loop < nb_link)
	list_chain = ft_lstnew(*(list + loop), */
}

t_link		*ft_lstnew(const void *data, size_t data_size)
{
	t_link	*link;

	if ((link = (t_link *)(ft_malloc(sizeof(t_link)))) == NULL)
		return (NULL);
	if (data == NULL)
	/*{
		link->content = NULL;
		link->content_size = 0;
		link->next = NULL;
		return (link);
	}*/
		return (NULL);
	else if ((link->data = ft_malloc(data_size)) == NULL)
	{
		ft_free(link);
		return (NULL);
	}
	ft_memcpy(link->data, data, data_size);
	//link->data_size = data_size;
	link->next = NULL;
	return (link);
}