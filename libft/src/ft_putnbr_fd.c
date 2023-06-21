/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcazac <pcazac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 13:21:37 by pcazac            #+#    #+#             */
/*   Updated: 2023/03/27 13:21:37 by pcazac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

static void	transform_itoa(long int n, int fd);

void	ft_putnbr_fd(int n, int fd)
{
	long int	j;

	if (n < 0)
	{
		write(fd, "-", 1);
		n = n * -1;
		if (n == -2147483648)
		{
			n = 147483648;
			write(fd, "2", 1);
		}
	}
	j = n;
	if (n != 0)
		transform_itoa(j, fd);
	if (n == 0)
		write(fd, "0", 1);
	return ;
}

static void	transform_itoa(long int n, int fd)
{
	int		i;
	char	m;

	i = 0;
	if (n == 0)
		return ;
	i = n % 10;
	transform_itoa((n / 10), fd);
	m = i + 48;
	write(fd, &m, 1);
	return ;
}
