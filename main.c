/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleger <gleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/04 15:00:33 by gleger            #+#    #+#             */
/*   Updated: 2014/01/12 20:08:42 by gleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>
#include <stdio.h>
void	show_usage(void)
{
	ft_puterr("\033[0;31musage: \033[0;37mft_select [list of stuff ...]");
}

int		main(int argc, char **argv)
{
	t_link	*list_chain;

	if (argc <= 1)
		show_usage();
	else
	{
		list_chain = make_list(argc, argv);
		//ft_select(argc, argv);
		//ft_select(list_chain);
		print_list(list_chain);
	}
	return (0);
}
