/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_mngr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcazac <pcazac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 13:24:07 by pcazac            #+#    #+#             */
/*   Updated: 2023/07/05 13:24:24 by pcazac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

void	error_mngr(char **command, int err)
{
	err = 127;
	ft_putstr_fd("command not found:", 2);
	ft_putstr_fd(command[0], 2);
	ft_putstr_fd("\n", 2);
	exit(err);
}
