/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvizcain <cvizcain@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 09:04:18 by cvizcain          #+#    #+#             */
/*   Updated: 2024/08/25 21:07:09 by cvizcain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

int	ft_argcount(const char* s)
{
	int argcount;

	argcount = 0;
	while (*s)
	{
		if (*s == '%')
			++argcount;
		++s;
	}
	printf("Arguments count: %i", argcount);

	return argcount;
}

int	ft_printf(const char* s, ...)
{
	int args;
	va_list lista;
	
	args = 0;
	args = ft_argcount(s);
	while (s++)
	va_start(lista, s);
	
	write(1, s, sizeof(s) + 2);
	return (1);
}

int	main(void)
{
	ft_argcount("%Ho%la mu%ndo");
	return (0);
}