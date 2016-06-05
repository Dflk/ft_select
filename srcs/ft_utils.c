/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaran <rbaran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 22:57:54 by rbaran            #+#    #+#             */
/*   Updated: 2016/06/02 17:27:39 by rbaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

int	ft_putchar_int(int c)
{
	t_output	*output;

	output = ft_saveoutput(NULL);
	return (write(output->fd, &c, 1));
}
