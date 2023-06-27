/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcazac <pcazac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 11:17:39 by pcazac            #+#    #+#             */
/*   Updated: 2023/06/27 15:46:42 by pcazac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX
# define PIPEX

# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <sys/wait.h>
# include "../libft/header/libft.h"
# include <errno.h>

char	**parse_command(char *argv, char **env);
int		init_check(int argc, char *argv[], char **env);
void	free_paths(char **path);
size_t	ft_strlength(char **c);
char	**parse_arg(char *argv);

#endif
