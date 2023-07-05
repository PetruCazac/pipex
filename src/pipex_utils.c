/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcazac <pcazac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 13:16:27 by pcazac            #+#    #+#             */
/*   Updated: 2023/07/05 18:01:12 by pcazac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

// int	pork(int (*fd)[])
int	pork(void)
{
	int	pid;

	// if (pipe(*fd) == -1)
	// 	return (-1);
	pid = 0;
	pid = fork();
	if (pid == -1)
		exit(errno);
	return (pid);
}

int	waitall(int *fd)
{
// it waits for at least one of the 2 processes to finish
// It waits for the child to run, once it ran, it closes all the PIPES!
	if (waitpid(-1, NULL, 0) == -1 || waitpid(0, NULL, 0) == -1)
	{
		close_pipe(fd);
		error_mngr(NULL, errno);
	}	
	close_pipe(fd);
	return (EXIT_SUCCESS);
}

void	close_pipe(int *fd)
{
	close(fd[0]);
	close(fd[1]);
	close(STDIN_FILENO);
}
