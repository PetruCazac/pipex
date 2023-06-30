/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcazac <pcazac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 15:20:17 by pcazac            #+#    #+#             */
/*   Updated: 2023/06/30 15:21:59 by pcazac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

int	first_child(char **argv, char **env, int *fd)
{
	char	**command;
	int		infile;

	command = NULL;
	command = parse_command(argv[2], env);
	infile = open(argv[1], O_RDONLY);
	if (infile < 0)
	{
		errno = 2;
		perror("OPEN ERROR");
		exit(errno);
	}
	dup2(infile, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close_pipe(fd);
	if (execve(command[0], command, env) == -1)
		error_mngr(command, errno);
	return (EXIT_SUCCESS);
}

void	error_mngr(char **command, int err)
{
	err = 127;
	ft_putstr_fd("command not found:", 2);
	ft_putstr_fd(command[0], 2);
	ft_putstr_fd("\n", 2);
	exit(err);
}

void	close_pipe(int *fd)
{
	close(fd[0]);
	close(fd[1]);
}

int	pork(int (*fd)[2])
{
	int	pid;

	pid = 0;
	if (pipe (*fd) == -1)
		return (-1);
	pid = fork();
	if (pid == -1)
		exit(errno);
	return (pid);
}
