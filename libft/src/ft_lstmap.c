/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcazac <pcazac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 16:08:29 by pcazac            #+#    #+#             */
/*   Updated: 2023/05/24 16:26:38 by pcazac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

static int	clear(t_list *temp, t_list *temp1, void (*del)(void*));

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*temp;
	t_list	*lst1;
	t_list	*temp1;

	if (!lst)
		return (NULL);
	temp = ft_lstnew(f(lst->content));
	if (!temp)
	{
		free(temp->content);
		ft_lstclear(&temp, del);
		return (NULL);
	}
	lst1 = lst->next;
	temp1 = temp;
	while (lst1)
	{
		temp1->next = ft_lstnew(f(lst1->content));
		if (!clear(temp, temp1->next, del))
			return (NULL);
		lst1 = lst1->next;
		temp1 = temp1->next;
	}
	return (temp);
}

static int	clear(t_list *temp, t_list *temp1, void (*del)(void*))
{
	if (!temp1)
	{
		ft_lstclear(&temp, del);
		return (0);
	}
	return (1);
}
