/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcazac <pcazac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 11:17:10 by pcazac            #+#    #+#             */
/*   Updated: 2023/07/05 10:18:00 by pcazac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

int	child(char **argv, char **env, int *fd, int a)
{
	char	**command;

	command = NULL;
	command = parse_command(argv[a], env);
	dup2(fd[1], STDOUT_FILENO);
	close_pipe(fd);
	if (execve(command[0], command, env) == -1)
		error_mngr(command, errno);
	return (EXIT_SUCCESS);
}

int	parent(char **argv, char **env, int *fd, int i)
{
	char	**command;
	int		outfile;

	command = NULL;
	command = parse_command(argv[i], env);
	outfile = open(argv[i + 1], O_RDWR | O_TRUNC | O_CREAT, 0644);
	if (outfile < 0)
	{
		errno = 2;
		perror("OPEN ERROR");
		exit(errno);
	}
	dup2(outfile, STDOUT_FILENO);
	dup2(fd[0], STDIN_FILENO);
	close_pipe(fd);
	if (execve(command[0], command, env) == -1)
		error_mngr(command, errno);
	return (EXIT_SUCCESS);
}

int	main(int argc, char *argv[], char *env[])
{
	pid_t	pid;
	int		fd[2];
	int		i;

	i = 3;
	if (init_bonus_check(argc, argv) == EXIT_FAILURE)
		return (errno);
	pid = pork(&fd);
	if (pid == 0)
		first_child(argv, env, fd);
	while (i < (argc - 2))
	{
		if (pid > 0)
		{
			dup2(fd[0], STDIN_FILENO);
			close(fd[1]);
		}
		pid = pork(&fd);
		if (pid == 0)
			child(argv, env, fd, i);
		i++;
	}
	if (pid > 0)
	{
		parent(argv, env, fd, i);
		waitpid(0, NULL, 0);
	}
	return (0);
}
// Create a heredoc function that will be called in the main function and will copy the functioning
// of here-doc

