/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleger <gleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/04 15:00:33 by gleger            #+#    #+#             */
/*   Updated: 2014/01/05 17:03:12 by gleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

void	show_usage(void)
{
	ft_putendl("usage: ft_select [list of stuff ...]");
}

int	main(int argc, char **argv)
{
	if (argc <= 1)
		show_usage();
	else
		ft_select(argc, argv);
	return (0);
}
