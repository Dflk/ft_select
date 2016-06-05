/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printconf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaran <rbaran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 22:47:21 by rbaran            #+#    #+#             */
/*   Updated: 2016/06/02 16:14:01 by rbaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>
#include <stdio.h>

static void		ft_printheader(int cols, int fd)
{
	int		begin_position;

	begin_position = (cols - 42) / 2;
	ft_movecursor(begin_position, 0);
	ft_putstr_fd(HEADER_1, fd);
	ft_movecursor(begin_position, 1);
	ft_putstr_fd(HEADER_2, fd);
	ft_movecursor(begin_position, 2);
	ft_putstr_fd(HEADER_3, fd);
	ft_movecursor(begin_position, 3);
	ft_putstr_fd(HEADER_4, fd);
	ft_movecursor(begin_position, 4);
	ft_putstr_fd(HEADER_5, fd);
	ft_movecursor(begin_position, 5);
	ft_putstr_fd(HEADER_6, fd);
}

void		ft_print(t_elems *elem, int underline, int fd)
{
	ft_savecursor();
	if (underline)
		ft_underlinemode(UNDER_ON);
	ft_putstr_fd(elem->data, fd);
	if (underline)
		ft_underlinemode(UNDER_OFF);
	ft_restorecursor();
}

void		ft_printconf(t_elems *begin_list, t_elems *elems, t_output *output)
{
	int		map;
	t_elems	*begin_buf;

	ft_clearscreen();
	if (output->header)
		ft_printheader(output->o_total_cols, output->fd);
	map = begin_list->map;
	begin_buf = begin_list;
	while (begin_list->map == map)
	{
		ft_movecursor(begin_list->posX, begin_list->posY);
		if (begin_list == elems)
			ft_print(begin_list, UNDER_ON, output->fd);
		else
			ft_print(begin_list, UNDER_OFF, output->fd);
		begin_list = begin_list->next;
		if (begin_list == begin_buf)
			break ;
	}
	ft_movecursor(elems->posX, elems->posY);
}
