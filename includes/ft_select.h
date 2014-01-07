/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleger <gleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/05 13:53:58 by gleger            #+#    #+#             */
/*   Updated: 2014/01/07 13:36:36 by gleger           ###   ########.fr       */
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
# define BUFF_SIZE	4096
# define ESCAPE	0
# define SPACE	32
# define UP	buffer[0] == 27 && buffer[1] == 91 && buffer[2] == 65
# define LEFT	buffer[0] == 27 && buffer[1] == 91 && buffer[2] == 68
# define RIGHT	buffer[0] == 27 && buffer[1] == 91 && buffer[2] == 67
# define DOWN	buffer[0] == 27 && buffer[1] == 91 && buffer[2] == 66
# define RETURN	10
# define DELETE	127
# define BACKSPACE	2117294875

size_t	ft_strlen(const char *str);
void	ft_putchar(const char c);
int tputs_putchar(int c);
void	ft_putstr(const char *str);
void	ft_putendl(const char *str);
int	ft_select(int nb_list, char **list);
void	ft_print(int size, char ** list);

#endif
