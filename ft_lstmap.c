/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpascucc <cpascucc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 09:47:47 by cpascucc          #+#    #+#             */
/*   Updated: 2023/01/27 13:03:52 by cpascucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*temp_new;

	new = NULL;
	while (lst && f)
	{
		temp_new = ft_lstnew(f(lst->content));
		if (!temp_new)
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
		ft_lstadd_back(&new, temp_new);
		lst = lst->next;
	}
	return (new);
}
