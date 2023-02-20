/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpascucc <cpascucc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 13:24:23 by cpascucc          #+#    #+#             */
/*   Updated: 2023/01/27 13:31:01 by cpascucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	i;
	void	*str;

	str = malloc(size * nmemb);
	if (!str || (nmemb == SIZE_MAX && size == SIZE_MAX))
		return (NULL);
	i = 0;
	ft_bzero(str, size * nmemb);
	return (str);
}
