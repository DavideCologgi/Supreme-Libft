/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpascucc <cpascucc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 09:46:49 by cpascucc          #+#    #+#             */
/*   Updated: 2023/01/25 09:46:51 by cpascucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*curr;

	if (!lst)
		return ;
	if (*lst)
	{
		curr = ft_lstlast(*lst);
		curr->next = new;
	}
	else
		*lst = new;
}
