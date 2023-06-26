/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcazac <pcazac@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 11:41:51 by pcazac            #+#    #+#             */
/*   Updated: 2023/06/26 09:26:05 by pcazac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"
// The function should take the arguments and separate the command from the file
// It should 

int	parse_in(char *argv, char **env, char **in)
{
	int	i;
	char **paths;

	i = -1;
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
	i = -1;
	while (paths[++i])
	{
		*in = ft_strjoin(ft_strjoin(paths[i], "/"), argv);
		if (access(*in, R_OK) == 0)
			return(EXIT_SUCCESS);
		else
			*in = NULL;
	}
	return (EXIT_FAILURE);
}

int	parse_out(char *argv, char **env, char **out)
{
	int	i;
	char **paths;

	i = -1;
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
	i = -1;
	while (paths[++i])
	{
		*out = ft_strjoin(ft_strjoin(paths[i], "/"), argv);
		if (access(*out, W_OK) == 0)
			return(EXIT_SUCCESS);
		else
			*out = NULL;
	}
	return (EXIT_FAILURE);
}

char	**parse_args(char *arg)
{
	char **args;

	args = ft_split(arg, '"');
	&(*args + 1) = ft_split(args[2], ' ');
	return (args);
}

int	parse_command(char *argv, char **env, char ***c)
{
	int		i;
	char	**paths;
	char	**args;

	args = parse_args(argv);
	i = -1;
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
	i = -1;
	while (paths[++i])
	{
		*c = ft_strjoin(ft_strjoin(paths[i], "/"), argv);
		if (access(*c, X_OK) == 0)
			return(EXIT_SUCCESS);
		else
			*c = NULL;
	}
	return (EXIT_FAILURE);
}
