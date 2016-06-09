/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaran <rbaran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 14:44:16 by rbaran            #+#    #+#             */
/*   Updated: 2016/06/09 15:34:19 by rbaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

static void	ft_setsignals(int fd)
{
	if (signal(SIGINT, SIG_IGN) == SIG_ERR)
		ft_putstr_fd("\033[31mSIGINT ERROR\033[0m", fd);
	if (signal(SIGWINCH, &ft_signals) == SIG_ERR)
		ft_putstr_fd("\033[31mSIGWINCH ERROR\033[0m", fd);
}

t_elems			*ft_saveelems(t_elems *elems)
{
	static t_elems	*save_elems = NULL;

	if (elems)
	{
		save_elems = elems;
		return (NULL);
	}
	else
		return (save_elems);
}

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
		ft_saveelems(select);
		ft_setsignals(output->fd);
		ft_select(select, output);
		free(ft_saveoutput(NULL));
	}
	ft_termios(0);
	return (0);
}
