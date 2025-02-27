/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listsize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apieniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 19:41:26 by apieniak          #+#    #+#             */
/*   Updated: 2024/12/16 13:34:42 by apieniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_lstsize(t_size *lst)
{
	void	*current;
	int		i;

	i = 0;
	current = lst;
	while (current)
	{
		i++;
		current = current->next;
	}
	return (i);
}
