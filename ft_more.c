/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_more.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleger <gleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/09 10:41:48 by gleger            #+#    #+#             */
/*   Updated: 2014/01/09 17:53:27 by gleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

void	ft_putstr_fd(char const *str, int fd)
{
	write(fd, str, ft_strlen(str));
}

void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}

void	ft_putendl_fd(char const *str, int fd)
{
	char	end_line;

	end_line = '\n';
	ft_putstr_fd(str, fd);
	ft_putchar_fd(end_line, fd);
}

void	ft_puterr(char *str)
{
	ft_putendl_fd(str, 2);
}