/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvizcain <cvizcain@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 16:48:45 by cvizcain          #+#    #+#             */
/*   Updated: 2024/08/28 17:11:39 by cvizcain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <string.h>

void	ft_putstr(char *s, int *charcount)
{
	if (s == NULL)
	{
		*charcount += write (1, "(null)", 6);
		return ;
	}
	else if (*s != '\0')
		*charcount += write (1, s, ft_strlen(s));
}
