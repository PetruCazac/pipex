/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcazac <pcazac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 11:17:10 by pcazac            #+#    #+#             */
/*   Updated: 2023/06/23 16:57:27 by pcazac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

int main(int argc, char *argv[], char *env[])
{
	pid_t	pid;
	int	fd[2];
	int	i = 0;

	i = argc;
	i++;
	ft_printf("%i\n", argc);
	// if (!init_check(argc, argv, env))
	// 	return (EXIT_FAILURE);
	if (pipe (fd) == -1) // fd[0] - read end ; fd[1] - write end
		return (EXIT_FAILURE);
	pid = fork();
	if (pid == -1)
		return (EXIT_FAILURE);
	if(pid == 0)
		child(argc, env, fd);
	else if (pid > 0)
	{
		ft_printf("%s, %s\n", argv[3], argv[4]);
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		close(fd[1]);
		// if (execve(gp(argv[3]), pa(argv[4]), env) == -1)
		if (execve(argv[3], &argv[4], env) == -1)
			return (EXIT_FAILURE);
	}
	return (0);
}

int	child(char **argv, char **env, int *fd)
{
	char	*path;
	int		infile;

	ft_printf("%s, %s\n", argv[1], argv[2]);
	path = get_path(argv[1]);
	infile = open(path, O_RDONLY);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	close(fd[0]);
	// if (execve(gp(argv[1]), pa(argv[2]), env) == -1)
	if (execve(argv[1], &argv[2], env) == -1)
		return (EXIT_FAILURE);
}

int	parent(char **argv, char **env)
{
	char	*path;
	int		infile;

	ft_printf("%s, %s\n", argv[1], argv[2]);
	path = get_path(argv[4]);
	infile = open(path, O_RDONLY);
	dup2(fd[0], STDOUT_FILENO);
	close(fd[0]);
	close(fd[1]);
	// if (execve(gp(argv[1]), pa(argv[2]), env) == -1)
	if (execve(argv[1], &argv[2], env) == -1)
		return (EXIT_FAILURE);
}