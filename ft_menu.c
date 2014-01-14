/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_menu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleger <gleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/12 21:09:19 by gleger            #+#    #+#             */
/*   Updated: 2014/01/12 22:25:13 by gleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

t_link	*find_cursor(t_link *first_link)
{
	while(first_link->cursor != 0)
	{
		first_link = first_link->next;
	}
	return (first_link);
}

t_link	*find_first(t_link *random_link)
{
	while(random_link->index != 0)
	{
		random_link = random_link->next;
	}
	return (random_link);
}