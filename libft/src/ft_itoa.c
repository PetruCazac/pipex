/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcazac <pcazac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 15:28:14 by pcazac            #+#    #+#             */
/*   Updated: 2023/05/24 16:26:38 by pcazac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

static char	*transform_itoa(char *nbr, int n, int d, int neg);
static int	size(int n);
static int	check(int n);

char	*ft_itoa(int n)
{
	int		d;
	int		neg;
	char	*nbr;

	neg = 0;
	d = 0;
	if (n == 0)
		return (ft_strdup("0"));
	if (!n)
		return (NULL);
	neg = check(n);
	if (neg == 1)
		n = n * (-1);
	else if (neg == 2)
		n = 147483648;
	d = size(n);
	nbr = (char *)ft_calloc(d + neg + 1, sizeof(char));
	if (nbr == NULL)
		return (NULL);
	nbr = transform_itoa(nbr, n, d, neg);
	return (nbr);
}

static int	check(int n)
{
	if (n < 0)
	{
		if (n == -2147483648)
			return (2);
		return (1);
	}
	return (0);
}

static char	*transform_itoa(char *nbr, int n, int d, int neg)
{
	int	i;
	int	j;

	if (neg == 1)
		nbr[0] = '-';
	if (neg == 2)
	{
		nbr[0] = '-';
		nbr[1] = '2';
	}
	i = d + neg - 1;
	while (i >= neg)
	{
		j = n % 10;
		n = n / 10;
		nbr[i] = j + 48;
		i--;
	}
	return (nbr);
}

static int	size(int n)
{
	int	i;

	i = 0;
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}
