/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcazac <pcazac@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 11:17:10 by pcazac            #+#    #+#             */
/*   Updated: 2023/06/29 07:41:11 by pcazac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

void	error_mngr(char **command, int err)
{
	err = 127;
	perror("command not found:");
	exit(err);
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
	close(fd[1]);
	if (execve(command[0], command, env) == -1)
		error_mngr(command, errno);
	return (EXIT_SUCCESS);
}

int	parent(char **argv, char **env, int *fd)
{
	char	**command;
	int		outfile;

	command = NULL;
	waitpid(-1, NULL, WNOHANG);
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
	if (execve(command[0], command, env) == -1)
		error_mngr(command, errno);
	return (EXIT_SUCCESS);
}

int	main(int argc, char *argv[], char *env[])
{
	pid_t	pid;
	int		fd[2];
	int		i;

	i = argc;
	i++;
	if (init_check(argc, argv) == EXIT_FAILURE)
		return (errno);
	if (pipe (fd) == -1)
		return (errno);
	pid = fork();
	i = 2;
	while (i < (argc - 2))
	{
		pid = fork();
		if (pid == -1)
			exit(errno);
		if (pid > 0)
			child(argv, env, fd);
		if (pid == 0)
			child(argv, env, fd);
		i++;
	}
	if (pid > 0)
		parent(argv, env, fd);
	return (0);
}
