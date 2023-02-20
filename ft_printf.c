/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 17:08:24 by dcologgi          #+#    #+#             */
/*   Updated: 2023/02/20 09:30:13 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printer(va_list lista_parametri, const char tipo)
{
	int	char_stamp;

	char_stamp = 0;
	if (tipo == 'c')
		char_stamp += ft_putchar(va_arg(lista_parametri, int));
	else if (tipo == 's')
		char_stamp += ft_putstr(va_arg(lista_parametri, char *));
	else if (tipo == 'p')
		char_stamp += ft_putptr(va_arg(lista_parametri, uintptr_t));
	else if (tipo == 'd' || tipo == 'i')
		char_stamp += ft_putnbr(va_arg(lista_parametri, int));
	else if (tipo == 'u')
		char_stamp += ft_putunbr(va_arg(lista_parametri, unsigned int));
	else if (tipo == 'x' || tipo == 'X')
		char_stamp += ft_puthexnbr(va_arg(lista_parametri, unsigned int), tipo);
	else if (tipo == '%')
		char_stamp += ft_putchar('%');
	return (char_stamp);
}

int	ft_printf(const char *a, ...)
{
	va_list	lista_parametri;
	int		i;
	int		char_check;

	va_start(lista_parametri, a);
	i = 0;
	char_check = 0;
	while (a[i])
	{
		if (a[i] == '%')
		{
			i++;
			char_check += ft_printer(lista_parametri, a[i]);
			i++;
		}
		if (!a[i])
			return (char_check);
		if (a[i] != '%')
		{
			char_check += ft_putchar(a[i]);
			i++;
		}
	}
	va_end(lista_parametri);
	return (char_check);
}
