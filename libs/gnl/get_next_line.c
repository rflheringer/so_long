/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheringe <rheringe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 10:14:21 by rheringe          #+#    #+#             */
/*   Updated: 2024/11/19 14:06:18 by rheringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char		*rl;
	char			*buffer;
	char			*line;
	char			*temp;
	int				bytes_read;

	buffer = ft_check_buffer(fd, &rl);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		rl = ft_get_temp(bytes_read, buffer, rl);
		if (ft_strchr(rl, '\n'))
			break ;
	}
	free(buffer);
	if (bytes_read < 0 || (bytes_read == 0 && (!rl || rl[0] == '\0')))
		return (free(rl), rl = NULL);
	line = ft_extract_line(rl);
	temp = ft_strdup(rl + ft_strlen(line));
	free(rl);
	rl = temp;
	return (line);
}

char	*ft_extract_line(char *rl)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	while (rl[i] && rl[i] != '\n')
		i++;
	if (rl[i] == '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	j = 0;
	while (j < i)
	{
		line[j] = rl[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

char	*ft_check_buffer(int fd, char **rl)
{
	char	*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc((BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (NULL);
	if (*rl == NULL)
		*rl = ft_strdup("");
	return (buffer);
}

char	*ft_get_temp(int bytes_read, char *buffer, char *rl)
{
	char	*temp;

	buffer[bytes_read] = '\0';
	temp = ft_strjoin(rl, buffer);
	free(rl);
	return (temp);
}
