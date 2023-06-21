/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcazac <pcazac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 10:52:17 by pcazac            #+#    #+#             */
/*   Updated: 2023/06/20 09:32:08 by pcazac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

static char		**assign(char **dst, const char *s, char c);
static size_t	occur(char const *s, char c);
void			freeall(char **s);
static int		occur_str(char const *s, char c);

char	**ft_split(char const *s, char c)
{
	char	**sn;

	if (!s)
		return (NULL);
	sn = (char **) ft_calloc(occur(s, c), sizeof(char *));
	if (sn == NULL)
		return (NULL);
	if (occur(s, c) != 1)
		sn = assign(sn, s, c);
	return (sn);
}

static char	**assign(char **dst, const char *s, char c)
{
	int		i;
	int		n;
	int		start;

	n = -1;
	i = 0;
	start = 0;
	while (s[i] != '\0')
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
		{
			n++;
			start = i;
		}
		if (s[i] && occur_str(&s[i], c))
			dst[n] = ft_substr(s, start, occur_str(&s[i], c));
		if (dst[n] == NULL)
			return (freeall(dst), NULL);
		i = i + occur_str(&s[i], c);
	}
	return (dst);
}

static int	occur_str(char const *s, char c)
{
	int		i;

	i = 0;
	while (s[i] != c && s[i])
	{
		i++;
	}
	return (i);
}

void	freeall(char **s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}

static size_t	occur(char const *s, char c)
{
	int		i;
	size_t	n;
	char	m;

	i = 0;
	n = 0;
	m = c;
	while (s[i])
	{
		while (m == c && s[i] == c)
			m = s[++i];
		if (s[i])
			n++;
		while (s[i] && s[i] != c)
			m = s[++i];
	}
	return (n + 1);
}
