/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvizcain <cvizcain@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 16:38:48 by cvizcain          #+#    #+#             */
/*   Updated: 2024/08/30 21:50:17 by cvizcain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

void	ft_putchar(int c, int *charcount);
void	ft_putdecun(int nb, int *charcount);
void	ft_puthex(size_t nb, int *charcount);
void	ft_puthexcaps(size_t nb, int *charcount);
void	ft_putptr(size_t i);
void	ft_putstr(char *s, int *charcount);
int		ft_strlen(char *s);
void	ft_putnbr(int nb, int *charcount);
void	ft_putnbr_base(unsigned int nbr, char base, int *charcount);

#endif
