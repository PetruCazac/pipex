/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcazac <pcazac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 13:48:11 by pcazac            #+#    #+#             */
/*   Updated: 2023/05/24 16:26:38 by pcazac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

void	clean_the_buff(char *buff)
{
	int		i;
	int		start;

	i = 0;
	start = 0;
	if (buff[line_end(buff)] != '\n')
	{
		while (i < BUFFER_SIZE)
			buff[i++] = '\0';
		return ;
	}
	if (buff[line_end(buff)] == '\n')
		start = line_end(buff) + 1;
	while (i <= BUFFER_SIZE)
	{
		if (start + i <= BUFFER_SIZE)
			buff[i] = buff[start + i];
		else
			buff[i] = 0;
		i++;
	}
	buff[BUFFER_SIZE] = 0;
	return ;
}

char	*copy_line(int *count, char *temp_buffer, char **return_line)
{
	int	i;

	i = -1;
	while (temp_buffer[++i] && i < BUFFER_SIZE && temp_buffer[i] != '\n')
		*(*return_line + *count - BUFFER_SIZE + i) = temp_buffer[i];
	if (temp_buffer[i] && temp_buffer[i] == '\n')
		*(*return_line + *count - BUFFER_SIZE + i) = temp_buffer[i];
	*count = *count - BUFFER_SIZE;
	return (*return_line);
}

char	*read_newln(int fd, int *count, char *static_buffer, char **return_line)
{
	int		i;
	char	temp_buffer[BUFFER_SIZE + 1];

	ft_bzero_gnl(temp_buffer, BUFFER_SIZE);
	i = read(fd, temp_buffer, BUFFER_SIZE);
	if (i > 0)
		*count = *count + BUFFER_SIZE;
	if (i < 0 || (i == 0 && *count == 0))
		return (ft_bzero_gnl(static_buffer, BUFFER_SIZE), *return_line = NULL);
	if (temp_buffer[line_end(temp_buffer)] == '\n' || (i == 0 && *count != 0))
	{
		if (!ft_calloc_gnl(return_line, count, static_buffer))
			return (NULL);
		copy_buff(static_buffer, temp_buffer);
	}
	if (temp_buffer[line_end(temp_buffer)] != '\n' && i != 0)
	{
		if (!read_newln(fd, count, static_buffer, return_line))
			return (NULL);
	}
	if (*temp_buffer)
		copy_line(count, temp_buffer, return_line);
	return (*return_line);
}

char	*read_buffer(char *static_buffer, char **return_line)
{
	int	i;

	*return_line = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!(*return_line))
		return (NULL);
	ft_bzero_gnl(*return_line, BUFFER_SIZE);
	i = -1;
	while (static_buffer[++i] != '\n')
		*(*return_line + i) = static_buffer[i];
	*(*return_line + i) = static_buffer[i];
	clean_the_buff(static_buffer);
	return (*return_line);
}

char	*get_next_line(int fd)
{
	static char	static_buffer[10240][BUFFER_SIZE + 1];
	int			count;
	char		*return_line;

	count = 0;
	if (BUFFER_SIZE < 1 || fd > 10240 || fd < 0)
		return (NULL);
	while (static_buffer[fd][count] && static_buffer[fd][count] != '\n')
		count++;
	if (count <= BUFFER_SIZE && static_buffer[fd][count] == '\n')
		read_buffer(static_buffer[fd], &return_line);
	else
		read_newln(fd, &count, static_buffer[fd], &return_line);
	return (ft_treat(return_line));
}
