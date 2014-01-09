/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleger <gleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/04 15:00:33 by gleger            #+#    #+#             */
/*   Updated: 2014/01/09 14:50:39 by gleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

void	show_usage(void)
{
	ft_puterr("\033[0;31musage: \033[0;37mft_select [list of stuff ...]");
}

int		main(int argc, char **argv)
{
	if (argc <= 1)
		show_usage();
	else
		ft_select(argc, argv);
	return (0);
}
