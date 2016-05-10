/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manageselect.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaran <rbaran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 16:50:31 by rbaran            #+#    #+#             */
/*   Updated: 2016/05/09 23:14:03 by rbaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

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

void		ft_set_positions(t_elems *elems, t_output *size_conf)
{
	t_elems	*beg_elems;
	int		i;
	int		posX;
	int		posY;

	beg_elems = elems;
	posX = 0;
	posY = 0;
	i = 0;
	while (elems->next != beg_elems)
	{
		if ((i % (size_conf->o_cols - 1)) == 0)
		{
			posX = 0;
			posY++;
		}
		elems->posX = posX;
		elems->posY = posY;
		posX += size_conf->len_max + 1;
		elems = elems->next;
		i++;
	}
	if ((i % (size_conf->o_cols - 1)) == 0)
	{
		posX = 0;
		posY++;
	}
	elems->posX = posX;
	elems->posY = posY;
	posX += size_conf->len_max + 1;
}
