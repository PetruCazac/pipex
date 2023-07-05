/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcazac <pcazac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 11:17:10 by pcazac            #+#    #+#             */
/*   Updated: 2023/07/05 18:01:37 by pcazac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

int	main(int argc, char *argv[], char *env[])
{
	pid_t	pid1;
	pid_t	pid2;
	int		fd[2];

	if (init_check(argc, argv) == EXIT_FAILURE)
		return (errno);
	if (pipe(fd) == -1)
		return (-1);
	// pid1 = pork(&fd);
	pid1 = pork();
	if (pid1 == 0)
		child(argv, env, fd);
	// pid2 = pork(&fd);
	pid2 = pork();
	if (pid2 == 0)
		second_child(argv, env, fd);
	if (pid1 > 0 && pid2 > 0)
		parent(fd);
	else if (pid2 > 0)
		second_parent();
	waitall(fd);
	while (pid1)
	{
		pid1++;
	}
	return (0);
}

	// waitpid(-1, NULL, 0);