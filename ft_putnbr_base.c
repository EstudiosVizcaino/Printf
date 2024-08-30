/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvizcain <cvizcain@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 21:24:57 by cvizcain          #+#    #+#             */
/*   Updated: 2024/08/30 22:26:19 by cvizcain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_base(unsigned int nbr, char Xxp, int *charcount)
{
	char			*base;
	unsigned int	base_len;

	base_len = 16;

	if (Xxp == 'p')
	{
		base = "0123456789abcdef";
		charcount += write(1, "0x", 2);
		Xxp = 'x';
	}

	if (Xxp == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (nbr < 16)
		ft_putchar(base[nbr % base_len], charcount);
	else
	{
		ft_putnbr_base(nbr / base_len, Xxp, charcount);
		ft_putnbr_base(nbr % base_len, Xxp, charcount);
	}
}