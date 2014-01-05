/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleger <gleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/05 13:53:58 by gleger            #+#    #+#             */
/*   Updated: 2014/01/05 17:03:15 by gleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <dirent.h>
# include <fcntl.h>
# include <termios.h>
# include <termcap.h>
# define BUFF_SIZE 4096

size_t	ft_strlen(const char *str);
void	ft_putchar(const char c);
void	ft_putstr(const char *str);
void	ft_putendl(const char *str);
void	ft_select(int nb_list, char **list);

#endif
