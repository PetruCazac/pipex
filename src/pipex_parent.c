/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_parent.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcazac <pcazac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 13:08:50 by pcazac            #+#    #+#             */
/*   Updated: 2023/07/05 17:47:11 by pcazac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

int	parent(int *fd)
{
// It waits for the child to run, once it ran, it closes all the PIPES!
	// waitpid(0, NULL, 0);
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	close(fd[1]);
	return (EXIT_SUCCESS);
}

// int	second_parent(int *fd)
int	second_parent(void)
{
// It waits for the child to run, once it ran, it closes all the PIPES!
	// waitpid(0, NULL, 0);
	close(STDIN_FILENO);
	// close(fd[0]);
	// close(fd[1]);
	return (EXIT_SUCCESS);
}
