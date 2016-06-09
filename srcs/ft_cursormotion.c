/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cursormotion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaran <rbaran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 22:50:49 by rbaran            #+#    #+#             */
/*   Updated: 2016/06/09 10:56:43 by rbaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

void	ft_movecursor(int posX, int posY)
{
	char	*res;

	if ((res = tgetstr("cm", NULL)))
		tputs(tgoto(res, posX, posY), 0, &ft_putchar_int);
}

void	ft_clearscreen(void)
{
	char	*res;

	if ((res = tgetstr("cl", NULL)))
		tputs(res, 0, &ft_putchar_int);
}

void	ft_savecursor(void)
{
	char	*res;

	if ((res = tgetstr("sc", NULL)))
		tputs(res, 0, &ft_putchar_int);
}

void	ft_restorecursor(void)
{
	char	*res;

	if ((res = tgetstr("rc", NULL)))
		tputs(res, 0, &ft_putchar_int);
}
