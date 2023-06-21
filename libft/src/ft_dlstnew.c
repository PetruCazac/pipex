/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcazac <pcazac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 09:55:12 by pcazac            #+#    #+#             */
/*   Updated: 2023/06/19 12:22:08 by pcazac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

t_dlist	*ft_dlstnew(int content)
{
	t_dlist	*tmp;

	tmp = malloc(sizeof(t_dlist));
	if (!tmp)
		return (NULL);
	tmp->number = content;
	tmp->index = 0;
	tmp->mv = 0;
	tmp->mv_up = 0;
	tmp->mv_down = 0;
	tmp->cm_up = 0;
	tmp->cm_down = 0;
	tmp->cm_mv = 0;
	tmp->rest_up = 0;
	tmp->rest_down = 0;
	tmp->cm_dir = 0;
	tmp->dir = 0;
	tmp->pos_up = 0;
	tmp->pos_down = 0;
	tmp->pos = NULL;
	tmp->next = NULL;
	tmp->prev = NULL;
	tmp->end = NULL;
	return (tmp);
}
