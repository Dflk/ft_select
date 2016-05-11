/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_managedisplay.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaran <rbaran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 18:23:09 by rbaran            #+#    #+#             */
/*   Updated: 2016/05/11 13:25:02 by rbaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

static size_t	ft_lenmax(t_elems *elems)
{
	t_elems	*begin_elems;
	size_t	max;
	size_t	buf_size;

	begin_elems = elems;
	max = 0;
	while (elems->next != begin_elems)
	{
		if ((buf_size = ft_strlen(elems->data)) > max)
			max = buf_size;
		elems = elems->next;
	}
	if ((buf_size = ft_strlen(elems->data)) > max)
			max = buf_size;
	return (max);
}

void			ft_managedisplay(t_elems *elems, int fd)
{
	struct winsize	termsize;
	t_output		size_conf;

	if (ioctl(fd, TIOCGWINSZ, &termsize) == -1)
		return ;
	size_conf.len_max = (int)ft_lenmax(elems);
	size_conf.o_cols = termsize.ws_col / (size_conf.len_max + 1);
	size_conf.o_lines = termsize.ws_row;
	ft_set_positions(elems, &size_conf);
	ft_printconf(elems, fd);
}
