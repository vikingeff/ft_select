/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleger <gleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/05 16:55:39 by gleger            #+#    #+#             */
/*   Updated: 2014/01/05 18:43:03 by gleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

void	ft_select()//int nb_list, char **list)
{
	pid_t	pid_f;
	char	*txt;

	pid_f = fork();
	while (1)
	{
		if (pid_f)
		{
			wait(NULL);
			exit(0);
		}
		else
		{
			txt = getenv("TERM");
			ft_putendl(txt);
			exit(0);
		}
	}
}
