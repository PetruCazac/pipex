/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcazac <pcazac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 13:48:08 by pcazac            #+#    #+#             */
/*   Updated: 2023/05/24 16:26:38 by pcazac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

int	line_end(char *buff)
{
	int	i;

	i = 0;
	while (buff[i] != '\0')
	{
		if (buff[i] == '\n')
			return (i);
		i++;
	}
	return (i);
}

char	*ft_calloc_gnl(char **return_line, int *count, char *static_buffer)
{
	int	i;

	*return_line = malloc((*count + 1) * sizeof(char));
	if (!*return_line)
		return (NULL);
	ft_bzero_gnl(*return_line, *count);
	i = -1;
	while (static_buffer[++i])
		*(*return_line + i) = static_buffer[i];
	return (*return_line);
}

char	*ft_bzero_gnl(char *str, int size)
{
	int	i;

	i = 0;
	while (i <= size)
	{
		str[i] = 0;
		i++;
	}
	return (str);
}

void	copy_buff(char *static_buffer, char *temp_buffer)
{
	int	i;

	i = -1;
	while (++i < BUFFER_SIZE)
		static_buffer[i] = temp_buffer[i];
	clean_the_buff(static_buffer);
	return ;
}	

char	*ft_treat(char *return_line)
{
	char	*temp;
	int		i;

	if (!return_line)
		return (NULL);
	i = 0;
	while (return_line[i] != 0)
		i++;
	temp = malloc((i + 1) * sizeof(char));
	if (!temp)
	{
		free(return_line);
		return_line = NULL;
		return (NULL);
	}
	ft_bzero_gnl(temp, i);
	i = 0;
	while (return_line[i] != 0)
	{
		temp[i] = return_line[i];
		i++;
	}
	free(return_line);
	return_line = NULL;
	return (temp);
}
