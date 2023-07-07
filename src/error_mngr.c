/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_mngr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcazac <pcazac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 13:24:07 by pcazac            #+#    #+#             */
/*   Updated: 2023/07/07 18:22:36 by pcazac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

void	error_mngr(char **command, int err)
{
	err = 127;
	ft_putstr_fd("command not found:", 2);
	ft_putstr_fd(command[0], 2);
	free_paths(command);
	ft_putstr_fd("\n", 2);
	exit(err);
}
