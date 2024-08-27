/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexcaps.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvizcain <cvizcain@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 17:25:09 by cvizcain          #+#    #+#             */
/*   Updated: 2024/08/27 20:24:50 by cvizcain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_write(char c, int *charcount)
{
	*charcount += write (1, &c, 1);
}

static void	ft_getnbr(int nb, int *charcount, char *base)
{
	if (nb > 9)
		ft_getnbr(nb / 16, charcount, base);
	ft_write((base[(nb % 16)]), charcount);
}

void	ft_puthexcaps(size_t nb, int *charcount)
{
		//Y = x % 15 -> 0 <= Y >= 15: Y ES EL INDEX DE BASE
	ft_getnbr(nb, charcount, "0123456789ABCDEF");
}
