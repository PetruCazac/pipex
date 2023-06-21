/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstclear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcazac <pcazac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 15:28:28 by pcazac            #+#    #+#             */
/*   Updated: 2023/06/20 10:33:12 by pcazac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

void	ft_dlstclear(t_dlist **lst)
{
	t_dlist	*temp;

	if (lst == NULL || *lst == NULL)
		return ;
	while (*lst)
	{
		temp = *lst;
		// ft_printf("%i\n", temp->index);
		// (*lst)->prev = NULL;
		// (*lst)->next = NULL;
		// (*lst)->end = NULL;
		// (*lst)->pos = NULL;
		*lst = temp->end;
		free(temp);
	}
}
