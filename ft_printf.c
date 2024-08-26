/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvizcain <cvizcain@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 09:04:18 by cvizcain          #+#    #+#             */
/*   Updated: 2024/08/26 21:23:39 by cvizcain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

int	ft_printf(const char *s, ...)
{
	va_list	lista;
	char	*c;

	va_start(lista, s);
	c = " ";
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			if (*s == 's')
			{
				c = va_arg(lista, char *);
				write (1, c, sizeof(c));
			}
		}
		else
		{
			write (1, s, 1);
		}
		s++;
	}
	write(1, s, sizeof(s) + 2);
	return (1);
}

int	main(void)
{
	char	*s = "Caracola";
	ft_printf("Hola: %s como mola", s);
	return (0);
}