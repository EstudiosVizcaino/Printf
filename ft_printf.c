/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvizcain <cvizcain@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 09:04:18 by cvizcain          #+#    #+#             */
/*   Updated: 2024/08/30 21:49:50 by cvizcain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

void	ft_switch(const char *s, va_list	*lista, int *charcount)
{
	if (*s == 's')
		ft_putstr(va_arg(lista, char *), charcount);
	if (*s == 'c')
		ft_putchar(va_arg(lista, int), charcount);
	if (*s == 'i')
		ft_putnbr(va_arg(lista, int), charcount);
	if (*s == 'x')
		ft_putnbr_base(va_arg(lista, size_t),'x', charcount);
	if (*s == 'X')
		ft_putnbr_base(va_arg(lista, size_t), 'X', charcount);
}

int	ft_printf(const char *s, ...)
{
	va_list	lista;
	int		charcount;

	if (s == NULL)
		return (0);
	charcount = 0;
	va_start(lista, s);
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			ft_switch(s, &lista, &charcount);
		}
		else
			charcount += write (1, s, 1);
		s++;
	}
	return (charcount);
}

int	main(void)
{
	char	*s = ":)";
	printf("\ncharcount: %i\n", ft_printf("Hola %s %c%c %i %x | %X", s, 'x', 'D', 42, -69, 69));
	printf("\ncharcount: %i\n", printf("Hola %s %c%c %i %x | %X", s, 'x', 'D', 42, -69, 69));
	return (0);
}


