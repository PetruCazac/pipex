/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcazac <pcazac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 11:40:07 by pcazac            #+#    #+#             */
/*   Updated: 2023/06/26 18:06:02 by pcazac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

// The function should check the number of arguments.
// The function should check the order of the aarguments
// The function should check if the files are existent and the paths to the files are existent
// The function should check if the commands are existent and the paths to the commands are existent

void	free_paths(char **path)
{
	int	i;

	i = -1;
	while (path[++i])
		free(path[i]);
	free(path);
	return ;
}
size_t	ft_strlength(char **c)
{
	int	i;

	i = 0;
	while (c[i] != NULL)
		i++;
	return (i);
}

int	check_infile(char *argv, char **env)
{
	int		i;
	char	**paths;
	char	**path;

	i = -1;
	paths = NULL;
	path = NULL;
	while (env[++i])
	{
		if (!ft_strncmp(env[i], "PWD=", 4))
			break ;
	}
	if (!env[i])
		return (EXIT_FAILURE);
	paths = ft_split(env[i] + 4, ':');
	if (!paths)
		return (EXIT_FAILURE);
	if (!*paths)
		return (free_paths(paths), EXIT_FAILURE);
	path = ft_calloc(ft_strlength(paths) + 1, sizeof(char *));
	i = -1;
	while (paths[++i])
	{
		path[0] = ft_strjoin(paths[i], "/");
 		free(paths[i]);
		paths[i] = ft_strjoin(path[0], argv);
		if (access(paths[i], R_OK) == 0)
			return(free_paths(path),
					free_paths(paths),
					EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}

int	check_outfile(char *argv, char **env)
{
	int		i;
	char	**paths;
	char	**path;

	i = -1;
	paths = NULL;
	path = NULL;
	while (env[++i])
	{
		if (!ft_strncmp(env[i], "PWD=", 4))
			break ;
	}
	if (!env[i])
		return (EXIT_FAILURE);
	paths = ft_split(env[i] + 4, ':');
	if (!paths)
		return (EXIT_FAILURE);
	if (!*paths)
		return (free_paths(paths), EXIT_FAILURE);
	path = ft_calloc(ft_strlength(paths) + 1, sizeof(char *));
	i = -1;
	while (paths[++i])
	{
		path[0] = ft_strjoin(paths[i], "/");
 		free(paths[i]);
		paths[i] = ft_strjoin(path[0], argv);
		if (access(paths[i], R_OK) == 0)
			return(free_paths(path),
					free_paths(paths),
					EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}

int	check_command(char *argv, char **env)
{
	int		i;
	char	**paths;
	char	**path;

	i = -1;
	paths = NULL;
	path = NULL;
	while (env[++i])
	{
		if (!ft_strncmp(env[i], "PATH=", 5))
			break ;
	}
	if (!env[i])
		return (EXIT_FAILURE);
	paths = ft_split(env[i] + 5, ':');
	if (!paths)
		return (EXIT_FAILURE);
	if (!*paths)
		return (free_paths(paths), EXIT_FAILURE);
	path = ft_calloc(ft_strlength(paths) + 1, sizeof(char *));
	i = -1;
	while (paths[++i])
	{
		path[0] = ft_strjoin(paths[i], "/");
 		free(paths[i]);
		paths[i] = ft_strjoin(path[0], argv);
		if (access(paths[i], R_OK) == 0)
			return(free_paths(path),
					free_paths(paths),
					EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}

int	init_check(int argc, char *argv[], char **env)
{
	int	i;

	i = -1;
	if (argc != 5)
		return (ft_printf("ARGUMENT ERROR:\n"), EXIT_FAILURE);
	while (++i < argc)
	{
		if (!argv[i])
			return (ft_printf("ARGUMENT EMPTY:\n"), EXIT_FAILURE);
	}
	if (check_infile(argv[1], env) == EXIT_FAILURE)
		return (ft_printf("EXIT FILE ERROR:\n"), EXIT_FAILURE);
	if (check_command(argv[2], env) == EXIT_FAILURE)
		return (ft_printf("COMMAND 1 ERROR:\n"), EXIT_FAILURE);
	if (check_command(argv[3], env) == EXIT_FAILURE)
		return (ft_printf("COMMAND 2 ERROR:\n"), EXIT_FAILURE);
	if (check_outfile(argv[4], env) == EXIT_FAILURE)
		return (ft_printf("SOURCE FILE ERROR:\n"), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
