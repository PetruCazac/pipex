/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcazac <pcazac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 11:29:41 by pcazac            #+#    #+#             */
/*   Updated: 2023/05/24 16:26:38 by pcazac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t					i;
	void					*l;
	unsigned const char		*sc;
	unsigned char			uc;

	l = NULL;
	sc = (unsigned const char *) s;
	i = 0;
	uc = (unsigned char) c;
	while (i < n)
	{
		if (uc == sc[i])
			return ((void *) &sc[i]);
		i++;
	}
	return (l);
}
