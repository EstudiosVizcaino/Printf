/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvizcain <cvizcain@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 09:04:18 by cvizcain          #+#    #+#             */
/*   Updated: 2024/08/29 14:55:54 by cvizcain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

void	ft_switch(const char *s, va_list	*lista, int *charcount)
{
	if (*s == 's')
		ft_putstr(va_arg(*lista, char *), charcount);
	else if (*s == 'c')
		ft_putchar(va_arg(*lista, int), charcount);
	else if (*s == 'i' || *s == 'd')
		ft_putnbr(va_arg(*lista, int), charcount);
	else if (*s == 'u')
		ft_putdecun(va_arg(*lista, int), charcount);
	else if (*s == 'x')
		ft_puthex(va_arg(*lista, size_t), charcount);
	else if (*s == 'X')
		ft_puthexcaps(va_arg(*lista, size_t), charcount);
	else if (*s == '%')
		ft_putchar('%', charcount);
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
  	printf("\ncharcount: %i\n", ft_printf("Hola %%%s %c%c %u %d",s ,'x','D', -10, -10));
  	//printf("\ncharcount: %i\n", printf("Hola %s %c%c %i %x | %X", s, 'x', 'D', 42, -69, -69));
  	//printf("\nCharcount: %i", ft_printf("%i Prueba %s %i i", 1, s,-2));
  	return (0);
  }