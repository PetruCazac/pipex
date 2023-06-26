/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcazac <pcazac@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 11:17:10 by pcazac            #+#    #+#             */
/*   Updated: 2023/06/26 22:29:43 by pcazac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

int	child(char **argv, char **env, int *fd)
{
	char	**command;
	int		infile;

	command = NULL;
	// ft_printf("Child: %s, %s\n", argv[1], argv[2]);
	command = parse_command(argv[2], env);
	infile = open(argv[1], O_RDONLY);
	if (infile < 0)
	{
		perror("OPEN ERROR");
		exit(EXIT_FAILURE);
	}
	dup2(infile, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	if (execve(command[0], command, env) == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	parent(char **argv, char **env, int *fd)
{
	char	**command;
	int		outfile;

	command = NULL;
	// ft_printf("Parent: %s, %s\n", argv[3], argv[4]);
	command = parse_command(argv[3], env);
	outfile = open(argv[4], O_RDWR, O_TRUNC, O_CREAT, 0644);
		if (outfile < 0)
	{
		perror("OPEN ERROR");
		exit(EXIT_FAILURE);
	}
	dup2(outfile, STDOUT_FILENO);
	dup2(fd[0], STDIN_FILENO);
	close(fd[1]);
	if (execve(command[0], command, env) == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int main(int argc, char *argv[], char *env[])
{
	pid_t	pid;
	int	fd[2];
	int	i = 0;

	i = argc;
	i++;
	// ft_printf("Number of arguments: %i\n", argc);
	if (init_check(argc, argv, env) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (pipe (fd) == -1) // fd[0] - read end ; fd[1] - write end
		return (EXIT_FAILURE);
	pid = fork();
	if (pid == -1)
		return (EXIT_FAILURE);
	if(pid == 0)
		child(argv, env, fd);
	else if (pid > 0)
		parent(argv, env, fd);
	return (0);
}
