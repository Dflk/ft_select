/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_managedisplay.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaran <rbaran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 18:23:09 by rbaran            #+#    #+#             */
/*   Updated: 2016/06/09 15:31:34 by rbaran           ###   ########.fr       */
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

t_output		*ft_saveoutput(t_output *output)
{
	static t_output	*output_save = NULL;

	if (output)
	{
		output_save = output;
		return (NULL);
	}
	else
		return (output_save);
}

t_output		*ft_managedisplay(t_elems *elems, int fd)
{
	struct winsize	termsize;
	t_output		*size_conf;

	if (ioctl(1, TIOCGWINSZ, &termsize) == -1)
		return (0);
	if (!(size_conf = ft_memalloc(sizeof(t_output))))
		return (0);
	size_conf->len_max = (int)ft_lenmax(elems);
	size_conf->o_cols = termsize.ws_col / (size_conf->len_max + 1);
	size_conf->o_total_cols = termsize.ws_col;
	size_conf->header = (termsize.ws_col > 49 && termsize.ws_row > 8) ? 1 : 0;
	size_conf->o_lines = size_conf->header ? termsize.ws_row - 8 :
				termsize.ws_row;
	ft_set_positions(elems, elems, size_conf, 0);
	size_conf->fd = fd;
	ft_saveoutput(size_conf);
	return (size_conf);
}
