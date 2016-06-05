/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaran <rbaran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 14:56:18 by rbaran            #+#    #+#             */
/*   Updated: 2016/06/02 16:07:48 by rbaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

int	ft_open(void)
{
	char	*tty;
	int		fd;

	if (!(tty = ttyname(1)))
		return (-1);
	fd = open(tty, O_WRONLY);
	free(tty);
	return (fd);
}
