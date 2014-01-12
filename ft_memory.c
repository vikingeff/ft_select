/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleger <gleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/07 15:44:16 by gleger            #+#    #+#             */
/*   Updated: 2014/01/12 20:08:27 by gleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

void	ft_bzero(void *s, size_t n)
{
	size_t	loop;
	char	*str;

	str = s;
	if (n != 0)
	{
		loop = 0;
		while (loop < n)
		{
			*(str + loop) = 0;
			loop++;
		}
	}
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*tmp;
	const char	*tmp2;
	size_t		loop;

	tmp = (char *)(dest);
	tmp2 = (char *)(src);
	loop = 0;
	while (loop < n)
	{
		*(tmp + loop) = *(tmp2 + loop);
		loop++;
	}
	return (dest);
}

char	*ft_strdup(const char *s1)
{
	int	size_s;
	int	loop;
	char	*str;

	size_s = 0;
	loop = 0;
	size_s = ft_strlen(s1);
	str = malloc(size_s * sizeof(char) + 1);
	if (str == NULL)
	{
		free (str);
		return (NULL);
	}
	while (loop < size_s)
	{
		*(str + loop) = *(s1 + loop);
		loop++;
	}
	*(str + loop) = '\0';
	return (str);
}

void	*ft_malloc(int size)
{
	void	*ptr;

	if ((ptr = malloc(size)) == NULL)
		ft_puterr("\033[1;31mError 0x01 Cannot allocate memory !\033[0;37m");
	return (ptr);
}

void	ft_free(void *ptr)
{
	if (ptr == NULL)
		ft_puterr("\033[1;31mError 0x02 Cannot free this pointer\033[0;37m");
	else
		free(ptr);
}