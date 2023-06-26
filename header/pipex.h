/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcazac <pcazac@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 11:17:39 by pcazac            #+#    #+#             */
/*   Updated: 2023/06/25 16:05:20 by pcazac           ###   ########.fr       */
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

// typedef struct	comm
// {
// 	int		fd;
// 	char	*cmd_child;
// 	char	**cmd_child_args;
// 	char	*cmd_parent;
// 	char	**cmd_child_args;
// }				t_comm;

int	parse_in(char *argv, char **env, char **in);
int	parse_out(char *argv, char **env, char **out);
int	parse_command(char *argv, char **env, char ***c);

#endif
