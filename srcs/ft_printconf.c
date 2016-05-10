/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printconf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaran <rbaran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 22:47:21 by rbaran            #+#    #+#             */
/*   Updated: 2016/05/09 23:14:30 by rbaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

void	ft_printconf(t_elems *elems, int fd)
{
	t_elems	*begin_elem;

	begin_elem = elems;
	ft_clearscreen();
	while (elems->next != begin_elem)
	{
		ft_movecursor(elems);
		ft_putstr_fd(elems->data, fd);
		elems = elems->next;
	}
	ft_movecursor(elems);
	ft_putstr_fd(elems->data, fd);
}
