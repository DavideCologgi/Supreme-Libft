/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 12:18:40 by dcologgi          #+#    #+#             */
/*   Updated: 2023/02/20 09:32:51 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_hexlen(unsigned int nb)
{
	int	i;

	i = 0;
	while (nb != 0)
	{
		i++;
		nb /= 16;
	}
	return (i);
}

void	ft_printhex(unsigned int nb, const char formato)
{
	if (nb >= 16)
	{
		ft_printhex(nb / 16, formato);
		ft_printhex(nb % 16, formato);
	}
	else
	{
		if (nb <= 9)
			ft_putchar(nb + '0');
		else
		{
			if (formato == 'x')
				ft_putchar(nb - 10 + 'a');
			if (formato == 'X')
				ft_putchar(nb - 10 + 'A');
		}
	}
}

int	ft_puthexnbr(unsigned int nb, const char formato)
{
	if (nb == 0)
		return (ft_putchar('0'));
	else
		ft_printhex(nb, formato);
	return (ft_hexlen(nb));
}
