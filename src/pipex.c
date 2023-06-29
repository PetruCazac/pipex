/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcazac <pcazac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 11:17:10 by pcazac            #+#    #+#             */
/*   Updated: 2023/06/29 08:39:23 by pcazac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

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
	{
		errno = 127;
		ft_putstr_fd("command not found:\n", 2);
		ft_putstr_fd(command[0], 2);
		ft_putstr_fd("\n", 2);
		exit(errno);
	}
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
	close(fd[0]);
	close(fd[1]);
	if (execve(command[0], command, env) == -1)
	{
		errno = 127;
		ft_putstr_fd("command not found:\n", 2);
		ft_putstr_fd(command[0], 2);
		ft_putstr_fd("\n", 2);
		exit(errno);
	}
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
	if (pid == -1)
		exit(errno);
	if (pid == 0)
		child(argv, env, fd);
	else if (pid > 0)
		parent(argv, env, fd);
	return (0);
}
