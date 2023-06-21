/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcazac <pcazac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 16:38:55 by pcazac            #+#    #+#             */
/*   Updated: 2023/06/19 14:15:28 by pcazac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

static long	transform(const char *s);
static int	ft_isspace(char str);

long	ft_atoi(const char *str)
{
	size_t	i;
	long	j;

	i = 0;
	j = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
			j = transform(&str[i + 1]) * (-1);
	if (str[i] == '+')
			j = transform(&str[i + 1]);
	if (str[i] > 47 && str[i] < 58)
			j = transform(&str[i]);
	return (j);
}

static long	transform(const char *s)
{
	int		i;
	long	j;

	j = 0;
	i = 0;
	while (s[i] > 47 && s[i] < 58 && s[i])
	{
		j = j * 10 + (s[i] - 48);
		i++;
	}
	return (j);
}

static int	ft_isspace(char str)
{
	if (str == 32 || (str >= 9 && str <= 13))
		return (1);
	else
		return (0);
}
