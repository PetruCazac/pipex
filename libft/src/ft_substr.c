/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcazac <pcazac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 09:27:08 by pcazac            #+#    #+#             */
/*   Updated: 2023/06/19 19:19:51 by pcazac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*s1;

	i = 0;
	if (!len)
		return (ft_strdup(""));
	if (start > ((unsigned int) ft_strlen(s)))
		return (ft_strdup(""));
	if (len > ((unsigned int) ft_strlen(s)) - start)
		len = ((unsigned int) ft_strlen(s)) - start;
	s1 = (char *) malloc(len + 1);
	if (!s1)
		return (NULL);
	if (!s)
		return (NULL);
	while (i < len && s[start + i])
	{
		s1[i] = s[start + i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}
