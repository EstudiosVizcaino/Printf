/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvizcain <cvizcain@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 09:04:18 by cvizcain          #+#    #+#             */
/*   Updated: 2024/09/01 21:32:19 by cvizcain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

void	ft_switch(const char *s, va_list	*lista, int *charcount)
{
	if (*s == 's')
		ft_putstr(va_arg(*lista, char *), charcount);
	if (*s == 'c')
		ft_putchar(va_arg(*lista, int), charcount);
	if (*s == 'i' || *s == 'd')
		ft_putnbr(va_arg(*lista, int), charcount);
	if (*s == 'u')
		ft_putdecun(va_arg(*lista, int), charcount);
	if (*s == 'p')
		ft_putptr(va_arg(*lista, void *), charcount);
	if (*s == 'x')
		ft_putnbr_hexa(va_arg(*lista, size_t), 'x', charcount);
	if (*s == 'X')
		ft_putnbr_hexa(va_arg(*lista, size_t), 'X', charcount);
	if (*s == '%')
		ft_putchar('%', charcount);
}

int	ft_printf(const char *s, ...)
{
	va_list	lista;
	int		charcount;
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
		{
			charcount += write (1, s, 1);
		}
		s++;
	}
	va_end(lista);
	return (charcount);
}
// int	main(void)
// {
// 	char	*s = ":)";
// 	printf("\ncharcount: %i\n", ft_printf("Hola %s %c%c %i %i %x | %X Pointer: %p - UwU: %u - Dinooo: %d", s, 'x', 'D', 0, 69,   0, 69, NULL, -2342, -42));
// 	printf("\ncharcount: %i\n", printf("Hola %s %c%c %i %i %x | %X Pointer: %p - UwU: %u - Dinooo: %d", s, 'x', 'D', 0, 69, 0, 69, NULL, -2342, -42));
// 	return (0);
// }
