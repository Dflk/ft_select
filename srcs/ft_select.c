/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaran <rbaran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 22:47:21 by rbaran            #+#    #+#             */
/*   Updated: 2016/06/02 16:44:42 by rbaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>
#include <stdio.h>

static int		ft_searchtab(unsigned int chr)
{
	static unsigned int	tab_dir[] = {LEF, UP, DO, RIG, DEL, SUP, ESC, 0};
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

static void		ft_moventimes(t_elems **elem, int o_lines, int way)
{
	int	i;

	i = 0;
	while (i < o_lines)
	{
		*elem = way ? (*elem)->next : (*elem)->prev;
		i++;
	}
}

static void		ft_move(t_elems **elem, int index, t_output *output)
{
	int		map;

	map = (*elem)->map;
	ft_print(*elem, UNDER_OFF, output->fd);
	if (index == 1)
		*elem = (*elem)->prev;
	else if (index == 2)
		*elem = (*elem)->next;
	else if (index == 0)
		ft_moventimes(elem, output->o_lines, 0);
	else if (index == 3)
		ft_moventimes(elem, output->o_lines, 1);
	if ((*elem)->map != map)
		ft_printconf(ft_findstart(*elem, DISPLAY, output->header), *elem, output);
	ft_movecursor((*elem)->posX, (*elem)->posY);
	ft_print(*elem, UNDER_ON, output->fd);
}

static int	ft_scanchr(unsigned int chr, t_elems **elem, t_output *output)
{
	int			index;
	t_output	*output_buf;

	if ((index = ft_searchtab(chr)) < 0)
		return (1);
	if (index == 0 || index == 1 || index == 2 || index == 3)
		ft_move(elem, index, output);
	else if (index == 4 || index == 5)
	{
		ft_deleteelem(elem, output->header);
		if (!(*elem) ||
			!(output_buf =
				ft_managedisplay(ft_findstart((*elem), LIST, output->header), output->fd)))
			return (0);
		ft_memcpy(output, output_buf, sizeof(t_output));
		free(output_buf);
		ft_printconf(ft_findstart(*elem, DISPLAY, output->header), *elem, output);
	}
	else if (index == 6)
		return (0);
	return (1);
}

void			ft_select(t_elems *elem, t_output *output)
{
	char			buf[5];
	int				ret;
	unsigned int	chr;
	int				ret_scan;

	ft_printconf(elem, elem, output);
	ret_scan = 1;
	while (ret_scan)
	{
		ft_bzero(buf, 5);
		if ((ret = read(0, buf, 5)) == -1)
			return ;
		buf[ret] = '\0';
		chr = ((unsigned int *)buf)[0];
		ret_scan = ft_scanchr(chr, &elem, output);
	}
}
