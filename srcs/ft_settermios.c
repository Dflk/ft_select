/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_settermios.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaran <rbaran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 12:01:46 by rbaran            #+#    #+#             */
/*   Updated: 2016/06/02 17:18:47 by rbaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

int		ft_termios(int set)
{
	static int				mode = 0;
	static struct termios	term_backup;
	struct termios			term;

	if (set == 1 && mode == 0)
	{
		if (tcgetattr(0, &term_backup)
			|| !ft_memcpy(&term, &term_backup, sizeof(struct termios)))
			return (-1);
		term.c_lflag &= ~(ICANON | ECHO);
		term.c_cc[VTIME] = 0;
		term.c_cc[VMIN] = 1;
		if (tcsetattr(0, TCSADRAIN, &term))
			return (-1);
		mode = 1;
	}
	else
	{
		mode = 0;
		if (tcsetattr(0, TCSANOW, &term_backup))
			return (-1);
	}
	return (0);
}
