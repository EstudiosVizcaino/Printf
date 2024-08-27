/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvizcain <cvizcain@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 09:04:18 by cvizcain          #+#    #+#             */
/*   Updated: 2024/08/27 16:59:08 by cvizcain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	va_list	lista;

	va_start(lista, s);
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			if (*s == 's')
				ft_putstr(va_arg(lista, char *));
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