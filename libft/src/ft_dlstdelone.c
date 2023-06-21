/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstdelone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcazac <pcazac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 15:30:11 by pcazac            #+#    #+#             */
/*   Updated: 2023/06/13 20:04:06 by pcazac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

void	ft_dlstdelone(t_dlist *lst)
{
	t_dlist	*p_temp;
	t_dlist	*n_temp;

	if (lst == NULL)
		return ;
	p_temp = lst->prev;
	n_temp = lst->next;
	n_temp->prev = lst->prev;
	p_temp->next = lst->next;
	free(lst);
	lst = NULL;
	return ;
}
