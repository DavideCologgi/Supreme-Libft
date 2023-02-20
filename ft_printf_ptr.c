/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 10:41:38 by dcologgi          #+#    #+#             */
/*   Updated: 2023/02/20 09:30:18 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_ptrlen(uintptr_t p)
{
	int	i;

	i = 0;
	while (p != 0)
	{
		p = p / 16;
		i++;
	}
	return (i);
}

void	ft_printptr(uintptr_t p)
{
	if (p >= 16)
	{
		ft_printptr(p / 16);
		ft_printptr(p % 16);
	}
	else
	{
		if (p <= 9)
			ft_putchar((p + '0'));
		else
			ft_putchar((p - 10 + 'a'));
	}
}

int	ft_putptr(uintptr_t p)
{
	write(1, "0x", 2);
	if (p == 0)
		return (write(1, "0", 1) + 2);
	else
		ft_printptr(p);
	return (ft_ptrlen(p) + 2);
}
