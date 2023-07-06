/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcazac <pcazac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 13:16:27 by pcazac            #+#    #+#             */
/*   Updated: 2023/07/06 12:01:53 by pcazac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

int	pork(void)
{
	int	pid;

	pid = 0;
	pid = fork();
	if (pid == -1)
		exit(errno);
	return (pid);
}

int	waitall(int *fd)
{
	while (waitpid(-1, NULL, 0) != -1)
		close_pipe(fd);
	return (EXIT_SUCCESS);
}

void	close_pipe(int *fd)
{
	close(fd[0]);
	close(fd[1]);
	close(STDIN_FILENO);
}
