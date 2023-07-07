/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcazac <pcazac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 11:41:51 by pcazac            #+#    #+#             */
/*   Updated: 2023/07/07 18:23:17 by pcazac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

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

char	**parse_arg(char *argv, char c)
{
	char	**arg;

	arg = ft_split(argv, c);
	if (!arg)
		return (NULL);
	if (!*arg)
		return (free_paths(arg), NULL);
	return (arg);
}

char	**get_path(char **argv, char **env)
{
	int		i;
	char	**paths;
	char	**path;

	i = -1;
	while (env[++i])
	{
		if (!ft_strncmp(env[i], "PATH=", 5))
			break ;
	}
	if (!env[i])
		return (NULL);
	paths = parse_arg(env[i] + 5, ':');
	path = ft_calloc(ft_strlength(paths) + 1, sizeof(char *));
	i = -1;
	while (paths[++i])
	{
		path[i] = ft_strjoin(paths[i], "/");
		free(paths[i]);
		paths[i] = ft_strjoin(path[i], *argv);
	}
	free_paths(path);
	return (paths);
}

char	**parse_command(char *argv, char **env)
{
	int		i;
	char	**paths;
	char	**arg;

	arg = parse_arg(argv, ' ');
	if (access(arg[0], F_OK) == 0)
		return (arg);
	paths = get_path(arg, env);
	i = -1;
	while (paths[++i])
	{
		if (access(paths[i], F_OK) == 0)
		{
			free(arg[0]);
			arg[0] = ft_strdup(paths[i]);
			return (free_paths(paths), arg);
		}
	}
	return (free_paths(paths), arg);
}
