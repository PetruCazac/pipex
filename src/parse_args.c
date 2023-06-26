/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcazac <pcazac@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 11:41:51 by pcazac            #+#    #+#             */
/*   Updated: 2023/06/26 21:34:01 by pcazac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"
// The function should take the arguments and separate the command from the file

char	**parse_command(char *argv, char **env)
{
	int		i;
	char	**paths;
	char	**path;
	char	**arg;

	i = -1;
	paths = NULL;
	path = NULL;
	arg = parse_arg(argv);
	while (env[++i])
	{
		if (!ft_strncmp(env[i], "PATH=", 5))
			break ;
	}
	if (!env[i])
		return (NULL);
	paths = ft_split(env[i] + 5, ':');
	if (!paths)
		return (NULL);
	if (!*paths)
		return (free_paths(paths), NULL);
	path = ft_calloc(ft_strlength(paths) + 1, sizeof(char *));
	i = -1;
	while (paths[++i])
	{
		path[i] = ft_strjoin(paths[i], "/");
 		free(paths[i]);
		paths[i] = ft_strjoin(path[i], *arg);
	}
	free_paths(path);
	i = -1;
	while (paths[++i])
	{
		if (access(paths[i], X_OK) == 0)
		{
			free(arg[0]);
			arg[0] = ft_strdup(paths[i]);
			return(free_paths(paths),
					arg);
		}
	}
	return (NULL);
}

// char	**parse_command(char *argv, char **env)
// {
// 	int		i;
// 	char	**paths;
// 	char	**args;
// 	char	*c;

// 	c = NULL;
// 	args = ft_split(argv, ' ');
// 	i = -1;
// 	while (env[++i])
// 	{
// 		if (!ft_strncmp(env[i], "PATH=", 5))
// 			break ;
// 	}
// 	if (!env[i])
// 		return (NULL);
// 	paths = ft_split(env[i] + 5, ':');
// 	if (!paths)
// 		return (NULL);
// 	i = -1;
// 	while (paths[++i])
// 	{
// 		if (*(paths[i]) == '\0')
// 			return (NULL);
		
// 		c = ft_strjoin(ft_strjoin(paths[i], "/"), args[0]);
// 		if (access((const char *) c, X_OK) == 0)
// 		{
// 			args[0] = c;
// 			free_paths(paths);
// 			return (args);
// 		}
// 	}
// 	free_paths(paths);
// 	free_paths(args);
// 	free(c);
// 	return (NULL);
// }