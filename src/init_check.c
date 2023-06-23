/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcazac <pcazac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 11:40:07 by pcazac            #+#    #+#             */
/*   Updated: 2023/06/23 15:54:18 by pcazac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

// The function should check the number of arguments.
// The function should check the order of the aarguments
// The function should check if the files are existent and the paths to the files are existent
// The function should check if the commands are existent and the paths to the commands are existent
int	init_check(int argc, char *argv[], char **env)
{
	int	i;

	i = -1;
	if (argc != 5)
		return (EXIT_FAILURE);
	while (++i < argc)
	{
		if (!argv[i])
			return (EXIT_FAILURE);
	}
	// Path finding and path management
}