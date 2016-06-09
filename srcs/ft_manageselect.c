/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manageselect.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaran <rbaran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 16:50:31 by rbaran            #+#    #+#             */
/*   Updated: 2016/06/09 11:36:04 by rbaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

t_elems			*ft_findstart(t_elems *elems, int mode, int header)
{
	if (mode == DISPLAY)
	{
		if (!header)
			while (elems->posX != 0 || elems->posY != 0)
				elems = elems->prev;
		else
			while (elems->posX != 0 || elems->posY != 7)
				elems = elems->prev;
	}
	else if (mode == LIST)
	{
		if (!header)
			while (elems->posX != 0 || elems->posY != 0 || elems->map != 0)
				elems = elems->prev;
		else
			while (elems->posX != 0 || elems->posY != 7 || elems->map != 0)
				elems = elems->prev;
	}
	return (elems);
}

void			ft_deleteelem(t_elems **elem, int header)
{
	t_elems	*elem_buf;

	if ((*elem) == (*elem)->next && (*elem) == (*elem)->prev)
	{
		free(*elem);
		(*elem) = NULL;
		return ;
	}
	(*elem)->prev->next = (*elem)->next;
	(*elem)->next->prev = (*elem)->prev;
	elem_buf = (*elem)->next;
	if ((*elem)->posX == 0 && ((!header && (*elem)->posY == 0) ||
		(header && (*elem)->posY == 7)))
	{
		(*elem)->next->posX = 0;
		(*elem)->next->posY = header ? 7 : 0;
	}
	free(*elem);
	*elem = elem_buf;
}

static t_elems	*ft_createelem(char *av)
{
	t_elems	*elem;

	if ((elem = (t_elems*)ft_memalloc(sizeof(t_elems))))
	{
		elem->prev = elem;
		elem->next = elem;
		elem->selected = 0;
		elem->data = av;
	}
	return (elem);
}

t_elems			*ft_fillselect(int ac, char **av)
{
	int		i;
	t_elems	*beg_elems;
	t_elems	*elems;

	i = 0;
	beg_elems = NULL;
	while (++i < ac)
	{
		if (!beg_elems)
		{
			beg_elems = ft_createelem(av[i]);
			elems = beg_elems;
		}
		else
		{
			elems->next = ft_createelem(av[i]);
			elems->next->prev = elems;
			elems = elems->next;
			beg_elems->prev = elems;
			elems->next = beg_elems;
		}
	}
	return (beg_elems);
}

void			ft_set_positions(t_elems *elems, t_elems *beg_list, t_output
			*size_conf, int map)
{
	t_elems	*beg_elems;
	int		i;

	beg_elems = elems;
	i = 1;
	elems->posX = 0;
	elems->posY = size_conf->header ? 7 : 0;
	elems->map = map;
	while ((elems = elems->next) && elems != beg_elems && i < (size_conf->o_cols 
				* size_conf->o_lines))
	{
		if (elems == beg_list)
			return ;
		if ((i % (size_conf->o_lines)) == 0)
		{
			elems->posY = size_conf->header ? 7 : 0;
			elems->posX = elems->prev->posX + size_conf->len_max + 1;
		}
		else
		{
			elems->posX = elems->prev->posX;
			elems->posY = elems->prev->posY + 1;
		}
		elems->map = map;
		i++;
	}
	if (elems != beg_elems && elems != beg_list)
		ft_set_positions(elems, beg_list, size_conf, map + 1);
}
