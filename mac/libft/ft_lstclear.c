/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihibti <ihibti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 11:31:44 by ihibti            #+#    #+#             */
/*   Updated: 2023/11/20 16:05:39 by ihibti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// void	ft_lstclear(t_list **lst, void (*del)(void *))
// {
// 	t_list	*current;
// 	t_list	*tmp;

// 	current = *lst;
// 	while (current->next != NULL)
// 	{
// 		tmp = current->next;
// 		del(current);
// 		free(current);
// 		current = tmp;
// 	}
// 	del(current);
// 	free(current);
// 	*lst = NULL;
// }

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*tmp;

	if (lst == NULL || !del)
		return ;
	current = *lst;
	while (current)
	{
		tmp = current->next;
		(*del)(current->content);
		free(current);
		current = tmp;
	}
	*lst = NULL;
}
