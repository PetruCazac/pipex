/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcazac <pcazac@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 11:40:07 by pcazac            #+#    #+#             */
/*   Updated: 2023/07/04 16:26:44 by pcazac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

int	init_check(int argc, char *argv[])
{
	int	i;

	i = -1;
	if (argc != 5)
	{
		errno = 2;
		return (write(2, "ARGUMENT ERROR\n", 15), EXIT_FAILURE);
	}
	while (++i < argc)
	{
		errno = 2;
		if (argv[i][0] == '\0')
			return (write(2, "ARGUMENT EMPTY\n", 15), EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	init_bonus_check(int argc, char *argv[])
{
	int	i;

	i = -1;
	if (argc < 5)
	{
		errno = 2;
		return (write(2, "ARGUMENT ERROR\n", 15), EXIT_FAILURE);
	}
	while (++i < argc)
	{
		errno = 2;
		if (argv[i][0] == '\0')
			return (write(2, "ARGUMENT EMPTY\n", 15), EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
