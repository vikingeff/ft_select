/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleger <gleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/05 16:55:39 by gleger            #+#    #+#             */
/*   Updated: 2014/01/06 23:42:11 by gleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>
#include <stdio.h>

void	ft_print(int size, char ** list)
{
	int	loop;

	loop = 1;
	while (loop < size)
	{
		ft_putendl(*(list + loop));
		loop++;
	}
}

int	ft_select(int nb_list, char **list)
{
	//pid_t	pid_f;
	char	*txt;
	struct termios	term;
	char	buffer[3];
	int	height;
	int	width;

	if ((txt = getenv("TERM")) == NULL)
		return (-1);
	if (tgetent(NULL, txt) < 1)
		return (-1);
	if (tcgetattr(0, &term) == -1)
  		return (-1);
	term.c_lflag &= ~(ICANON); // Met le terminal en mode canonique.
	term.c_lflag &= ~(ECHO); // les touches tapées ne s'inscriront plus dans le terminal
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	// On applique les changements :
	if (tcsetattr(0, TCSADRAIN, &term) == -1)
		return (-1);
	ft_print(nb_list, list);
	while (1)
	{
		txt = getenv("TERM");
		height = tgetnum ("li");
		width = tgetnum ("co");
		read(0, buffer, 3);
		//printf("%d - %d - %d\n", buffer[0], buffer[1], buffer[2]);
		printf("%d - %d\n", height, width);
    	if (buffer[2] == UP)
    	{
    		txt = tgetstr("up", NULL);
    		//printf("%s\n",txt);
    	}
			//printf("C'est une fleche haut !\n");
		else if (buffer[2] == 0)
		{
			printf("ESC, on quitte !\n");
			return (0);
		}
	}
	if (tcgetattr(0, &term) == -1)
		return (-1);
	term.c_lflag = (ICANON | ECHO);
	if (tcsetattr(0, 0, &term) == -1)
		return (-1);
}
