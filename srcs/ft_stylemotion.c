/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stylemotion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 14:52:32 by rbaran            #+#    #+#             */
/*   Updated: 2016/05/18 21:47:55 by rbaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

void	ft_underlinemode(int mode)
{
	char	*res;

	if (mode == 1)
		res = tgetstr("us", NULL);
	else
		res = tgetstr("ue", NULL);
	if (res)
		tputs(res, 0, &ft_putchar_int);
}
