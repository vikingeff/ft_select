/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tool.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleger <gleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/04 16:44:12 by gleger            #+#    #+#             */
/*   Updated: 2014/04/29 10:08:00 by gleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

int		ft_putchar(int c)
{
	int	fd;

	fd = open("/dev/tty", O_RDWR);
	if (fd == -1)
	{
		write(2, "Open error\n", 11);
		exit(-1);
	}
	write(fd, &c, 1);
	close(fd);
	return (0);
}

int		ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str++ != '\0')
		i++;
	return (i);
}

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((unsigned char *)b)[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
