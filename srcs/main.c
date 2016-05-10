/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaran <rbaran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 14:44:16 by rbaran            #+#    #+#             */
/*   Updated: 2016/05/09 22:01:23 by rbaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

int	main(int ac, char **av)
{
	int		fd;
	t_elems	*select;

	if ((fd = ft_open()) == -1)
		return (0);
	if (tgetent(NULL, getenv("TERM")) == -1)
		return (0);
	if (!(select = ft_fillselect(ac, av)))
		return (0);
	if (ft_termios() == -1)
		return (0);
	ft_managedisplay(select, fd);
	ft_termios();
	return (0);
}
