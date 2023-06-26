/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcazac <pcazac@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 11:17:10 by pcazac            #+#    #+#             */
/*   Updated: 2023/06/26 09:22:25 by pcazac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

int	child(char **argv, char **env, int *fd)
{
	char	*file_path;
	char	**command;
	int		infile;

	ft_printf("%s, %s\n", argv[1], argv[2]);
	parse_in(argv[1], env, &file_path);
	parse_command(argv[2], env, &command);
	infile = open(file_path, O_RDONLY);
	// check the open function
	dup2(infile, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	close(fd[0]);
	if (execve(command[0], command + 1, env) == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	parent(char **argv, char **env, int *fd)
{
	char	*file_path;
	char	**command;
	int		outfile;

	ft_printf("%s, %s\n", argv[3], argv[4]);
	parse_out(argv[4], env, &file_path);
	parse_command(argv[3], env, &command);
	outfile = open(file_path, O_RDWR, O_CREAT);
	// Check the open command
	dup2(outfile, STDOUT_FILENO);
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	close(fd[1]);
	if (execve(command[0], command + 1, env) == -1)
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
	ft_printf("%i\n", argc);
	// if (!init_check(argc, argv, env))
	// 	return (EXIT_FAILURE);
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
