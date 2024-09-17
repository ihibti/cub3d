/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihibti <ihibti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:14:20 by ihibti            #+#    #+#             */
/*   Updated: 2023/11/16 19:16:34 by ihibti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// void	freeList(t_list *head)
// {
// 	if (head)
// 		freeList((t_list *)head->next);
// 	free(head);
// }
// void	*addOne(void *p)
// {
// 	void	*r;

// 	r = malloc(sizeof(int));
// 	*(int *)r = *(int *)p + 1;
// 	return (r);
// }

// t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
// {
// 	t_list	*current;
// 	t_list	*new;
// 	t_list	*tmp;
// 	t_list	**stack;

// 	stack = malloc(sizeof(t_list *));
// 	if (lst == NULL || stack == 0 || f == NULL || del == NULL)
// 		return (NULL);
// 	*stack = NULL;
// 	current = lst;
// 	while (current != NULL)
// 	{
// 		// printf("loop\n");
// 		tmp = current->next;
// 		new = ft_lstnew(f(current->content));
// 		ft_lstadd_back(stack, new);
// 		new = new->next;
// 		del(current);
// 		free(current);
// 		current = tmp;
// 	}
// 	// if (!stack)
// 	// return (NULL);
// 	return (*stack);
// }
// t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
// {
// 	t_list	*new;
// 	t_list	*tmp;
// 	t_list	*rem;
// 	t_list	*start;

// 	if (lst == NULL)
// 		return (NULL);
// 	start = lst;
// 	while (lst != NULL)
// 	{
// 		// printf("loop\n");
// 		tmp = lst->next;
// 		rem = lst;
// 		lst = ft_lstnew(f(lst->content));
// 		// ft_lstadd_back(stack, new);
// 		// new = new->next;
// 		del(rem);
// 		free(rem);
// 		lst = tmp;
// 	}
// 	// if (!stack)
// 	// return (NULL);
// 	return (start);
// }

// int	main(void)
// {
// 	int		tab[] = {0, 1, 2, 3};
// 	t_list	*l;
// 	t_list	*m;

// 	l = ft_lstnew(tab);
// 	for (int i = 1; i < 4; ++i)
// 		ft_lstadd_back(&l, ft_lstnew(tab + i));
// 	m = ft_lstmap(l, addOne, free);
// 	return (0);
// }

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*p;

	if (!lst || !f)
		return (0);
	p = ft_lstnew((*f)(lst->content));
	if (!p)
	{
		ft_lstclear(&p, del);
		return (0);
	}
	lst = lst->next;
	while (lst)
	{
		new = ft_lstnew((*f)(lst->content));
		if (!(new))
		{
			ft_lstclear(&p, del);
			return (0);
		}
		ft_lstadd_back(&p, new);
		lst = lst->next;
	}
	return (p);
}
