/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkorimba <rkorimba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/05 11:38:00 by rkorimba          #+#    #+#             */
/*   Updated: 2014/01/08 12:24:01 by rkorimba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

typedef struct		s_data
{
	void			*data;
	int				index;
	int				cursor;
	int				select;
	struct s_data	*next;
	struct s_data	*prev;
}					t_data;

t_data			*create_list(void);
void			add_forward(t_data *elem, void *data);
void			add_backward(t_data *elem, void *data);
void			add_head(t_data *root, void *data);
void			add_tail(t_data *root, void *data);

void			display_list(t_data *tmp);

void			next_cursor(t_data *tmp);
void			prev_cursor(t_data *tmp);
void			selected(t_data *tmp);
void			delete_elem(t_data *tmp);
void			return_selected(t_data *root);

void			del_elem(t_data *elem);
void			del_first_elem(t_data *root);
void			del_last_elem(t_data *root);
void			empty_list(t_data *root);
void			del_list(t_data **root);

int				ft_outc(int c);

#endif /* !FT_SELECT_H */
