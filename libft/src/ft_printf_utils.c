/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcazac <pcazac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 13:40:59 by pcazac            #+#    #+#             */
/*   Updated: 2023/06/05 14:03:21 by pcazac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

int	ft_strlen_pf(const char *c)
{
	int	i;

	i = 0;
	if (c[i] == '\0')
		return (0);
	while (c[i] != '\0')
		i++;
	return (i);
}

int	ft_putstr_pf(char *s, int *count)
{
	if (s == NULL)
	{
		if (write(1, "(null)", 6) < 0)
			return (-1);
		*count = *count + 6;
		return (0);
	}
	else if (write(1, s, ft_strlen_pf(s)) < 0)
		return (-1);
	*count = *count + ft_strlen_pf(s);
	return (0);
}

int	ft_putchar_pf(char c, int *count)
{
	if (write(1, &c, 1) < 0)
		return (-1);
	*count = *count + 1;
	return (1);
}

int	putbase_pf(size_t input, char *base, size_t b_len, int *count)
{
	size_t	i;

	i = 0;
	i = input % b_len;
	if (input > b_len - 1)
		if (putbase_pf(input / b_len, base, b_len, count) < 0)
			return (-1);
	if (i < b_len)
	{
		if (write(1, &base[i], 1) < 0)
			return (-1);
	}
	(*count)++;
	return (0);
}
