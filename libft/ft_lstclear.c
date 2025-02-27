/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apieniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 21:50:50 by apieniak          #+#    #+#             */
/*   Updated: 2024/12/16 13:37:07 by apieniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*current;
	t_list	*buff;

	if (!lst || !*lst)
		return ;
	current = *lst;
	while (current != NULL)
	{
		buff = current;
		current = current->next;
		if (buff->content != NULL)
			del(buff->content);
		free(buff);
	}
	*lst = NULL;
}
