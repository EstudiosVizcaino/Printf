/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvizcain <cvizcain@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 17:21:12 by cvizcain          #+#    #+#             */
/*   Updated: 2024/08/29 14:51:47 by cvizcain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

void	ft_putchar(int c, int *charcount)
{
	int	prueba;

	prueba = 0;
	prueba = write (1, &c, 1);
	if (prueba == -1)
		exit (-1);
	else
		*charcount += prueba;
}
