/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcazac <pcazac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 10:32:54 by pcazac            #+#    #+#             */
/*   Updated: 2023/05/24 16:26:38 by pcazac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	d;
	size_t	s;
	size_t	i;

	i = 0;
	d = ft_strlen(dst);
	s = ft_strlen(src);
	if (d >= dstsize || !dstsize)
		return (dstsize + s);
	if ((dstsize - 1) > d && (dstsize - 1))
	{
		while (i < (dstsize - d - 1) && src[i])
		{
			dst[d + i] = src[i];
			i++;
		}
	}
	if ((dstsize - 1))
	dst[d + i] = '\0';
	return (d + s);
}
