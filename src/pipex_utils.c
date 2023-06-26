/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcazac <pcazac@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 19:08:41 by pcazac            #+#    #+#             */
/*   Updated: 2023/06/26 19:10:14 by pcazac           ###   ########.fr       */
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

char	**parse_arg(char *argv)
{
	char	**arg;

	arg = ft_split(argv, ' ');
	if (!arg)
		return (NULL);
	if (!*arg)
		return (free_paths(arg), NULL);
	return (arg);
}
