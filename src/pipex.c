/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcazac <pcazac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 11:17:10 by pcazac            #+#    #+#             */
/*   Updated: 2023/06/21 15:53:23 by pcazac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

int main(int argc, char *argv[], char *env[])
{
	pid_t	pid;
	id_t	fd[2];

	if (!init_check(argc, argv, env))
		return (EXIT_FAILURE);
	if (pipe (fd) == -1) // fd[0] - read end ; fd[1] - write end
		return (EXIT_FAILURE);
	pid = fork();
	if (pid == -1)
		return (EXIT_FAILURE);
	if(pid == 0)
	{
		dup2(pid, STDOUT_FILENO);
		close(pid);
		if (execve(gp(argv[1]), pa(argv[2]), env) == -1)
			return (freeall(), EXIT_FAILURE);
	}
	else if (pid > 0)
	{
		dup2(pid, STDIN_FILENO);
		close(pid);
		if (execve(gp(argv[3]), pa(argv[4]), env) == -1)
			return (freeall(), EXIT_FAILURE);
	}
	return (0);
}
