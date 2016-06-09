/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signals.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/09 15:17:35 by rbaran            #+#    #+#             */
/*   Updated: 2016/06/09 15:39:36 by rbaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

static void	ft_resize(void)
{
	int			fd;
	t_output	*output_saved;
	t_elems		*elems_saved;

	output_saved = ft_saveoutput(NULL);
	elems_saved = ft_saveelems(NULL);
	fd = output_saved->fd;
	free(output_saved);
	if ((output_saved = ft_managedisplay(elems_saved, fd)))
	{
		ft_saveelems(elems_saved);
		ft_printconf(elems_saved, elems_saved, output_saved);
	}
}

void		ft_signals(int signal)
{
	if (signal == SIGWINCH)
		ft_resize();
}
