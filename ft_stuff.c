/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stuff.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleger <gleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/05 13:37:15 by gleger            #+#    #+#             */
/*   Updated: 2014/01/07 13:36:33 by gleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

size_t	ft_strlen(const char *str)
{
	int	loop;

	loop = 0;
	while (*(str + loop) != '\0')
		++loop;
	return (loop);
}

void	ft_putstr(const char *str)
{
	write(1, str, ft_strlen(str));
}

void	ft_putchar(const char c)
{
	write(1, &c, 1);
}

void	ft_putendl(const char *str)
{
	char	end_line;

	end_line = '\n';
	ft_putstr(str);
	ft_putchar(end_line);
}

int tputs_putchar(int c)
{
    write(1, &c, 1);
    return (1);
}
