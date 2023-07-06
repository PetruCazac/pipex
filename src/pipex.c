/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcazac <pcazac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 11:17:10 by pcazac            #+#    #+#             */
/*   Updated: 2023/07/06 12:05:41 by pcazac           ###   ########.fr       */
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
	pid1 = pork();
	if (pid1 == 0)
		child(argv, env, fd);
	pid2 = pork();
	if (pid2 == 0)
		second_child(argv, env, fd);
	if (pid1 > 0 && pid2 > 0)
		parent(fd);
	else if (pid2 > 0)
		close(STDIN_FILENO);
	waitall(fd);
	return (0);
}

int	parent(int *fd)
{
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	close(fd[1]);
	return (EXIT_SUCCESS);
}

int	child(char **argv, char **env, int *fd)
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
	close(fd[0]);
	close(infile);
	if (execve(command[0], command, env) == -1)
		error_mngr(command, errno);
	return (EXIT_SUCCESS);
}

int	second_child(char **argv, char **env, int *fd)
{
	char	**command;
	int		outfile;

	command = NULL;
	command = parse_command(argv[3], env);
	outfile = open(argv[4], O_RDWR | O_TRUNC | O_CREAT, 0644);
	if (outfile < 0)
	{
		errno = 2;
		perror("OPEN ERROR");
		exit(errno);
	}
	dup2(outfile, STDOUT_FILENO);
	dup2(fd[0], STDIN_FILENO);
	close(fd[1]);
	close(outfile);
	printf("got to second child");
	if (execve(command[0], command, env) == -1)
		error_mngr(command, errno);
	return (EXIT_SUCCESS);
}
