/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printconf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaran <rbaran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 22:47:21 by rbaran            #+#    #+#             */
/*   Updated: 2016/05/11 16:05:49 by rbaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>
#include <stdio.h>

static int		ft_searchtab(unsigned int chr)
{
	static unsigned int	tab_dir[] = {UP, LEF, RIG, DO, 0};
	int					i;

	i = 0;
	while (tab_dir[i])
	{
		if (chr == tab_dir[i])
			return (i);
		i++;
	}
	return (-1);
}

static void		ft_move(t_elems **elem, int index)
{
	ft_savecursor();
	ft_putstr((*elem)->data);
	ft_restorecursor();
	if (index == 1)
		*elem = (*elem)->prev;
	if (index == 2)
		*elem = (*elem)->next;
	ft_movecursor(*elem);
	ft_savecursor();
	ft_underlinemode(UNDER_ON);
	ft_putstr((*elem)->data);
	ft_underlinemode(UNDER_OFF);
	ft_restorecursor();
}

static t_elems	*ft_scanchr(unsigned int chr, t_elems **elem)
{
	int			index;

	if ((index = ft_searchtab(chr)) < 0)
		return (*elem);
	if (index == 1 || index == 2)
		ft_move(elem, index);
	return (*elem);
}

static void		ft_select(t_elems *elem)
{
	char			buf[5];
	int				ret;
	unsigned int	chr;

	while (1)
	{
		if ((ret = read(0, buf, 5)) == -1)
			return ;
		buf[ret] = '\0';
		chr = ((unsigned int *)buf)[0];
		elem = ft_scanchr(chr, &elem);
	}
}

void		ft_printconf(t_elems *elems, int fd)
{
	t_elems	*begin_elem;

	begin_elem = elems;
	ft_clearscreen();
	ft_movecursor(elems);
	ft_underlinemode(UNDER_ON);
	ft_putstr_fd(elems->data, fd);
	ft_underlinemode(UNDER_OFF);
	while ((elems = elems->next) != begin_elem)
	{
		ft_movecursor(elems);
		ft_putstr_fd(elems->data, fd);
	}
	ft_movecursor(elems);
	ft_select(elems);
}
