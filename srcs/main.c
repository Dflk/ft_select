/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaran <rbaran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 14:44:16 by rbaran            #+#    #+#             */
/*   Updated: 2016/06/02 17:38:38 by rbaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

int			main(int ac, char **av)
{
	t_output	*output;
	t_elems		*select;
	int			fd;

	if ((fd = ft_open()) == -1)
		return (0);
	if (tgetent(NULL, getenv("TERM")) == -1)
		return (0);
	if (!(select = ft_fillselect(ac, av)))
		return (0);
	if (ft_termios(1) == -1)
		return (0);
	if ((output = ft_managedisplay(select, fd)))
	{
		ft_select(select, output);
		free(output);
	}
	ft_termios(0);
	return (0);
}
