/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheringe <rheringe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 10:14:21 by rheringe          #+#    #+#             */
/*   Updated: 2025/01/27 14:33:50 by rheringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	*rl[1024];
	char		*buffer;
	char		*line;
	char		*temp;
	int			bytes_read;

	buffer = ft_check_buffer(fd, &rl[fd]);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		rl[fd] = ft_get_temp(bytes_read, buffer, rl[fd]);
		if (ft_strchr(rl[fd], '\n'))
			break ;
	}
	free(buffer);
	if (bytes_read < 0 || (bytes_read == 0 && (!rl[fd] || rl[fd][0] == '\0')))
		return (free(rl[fd]), rl[fd] = NULL);
	line = ft_extract_line(rl[fd]);
	temp = ft_strdup(rl[fd] + ft_strlen(line));
	free(rl[fd]);
	rl[fd] = temp;
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
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
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

// #include <stdio.h>
// #include <fcntl.h>
// int main()
// {
// 	char *line;
// 	int fd1;
// 	int fd2;
// 	int i = 1;
// 	int j = 1;

// 	printf("BUFFER_SIZE:%d\n", BUFFER_SIZE);

// 	printf("\nFIRST TEST\n");
// 	fd1 = open("text copy.txt", O_RDONLY);
// 	while (i < 5)
// 	{
// 		line = get_next_line(fd1);
// 		printf("call %d is:%s", i, line);
// 		free(line);
// 		i++;
// 	}

// 	printf("\nSECOND TEST\n");
// 	fd2 = open("text jump line.txt", O_RDONLY);
// 	while (j < 6)
// 	{
// 		line = get_next_line(fd2);
// 		if (ft_strchr(line, '\n') == 0)
// 			printf("call %d is:%s\n", j, line);
// 		else
// 			printf("call %d is:%s", j, line);
// 		free(line);
// 		j++;
// 	}

// 	printf("\nFIRST TEST AGAIN\n");
// 	while ((line = get_next_line(fd1)) != NULL)
// 	{
// 		printf("call %d is:%s", i, line);
// 		free(line);
// 		i++;
// 	}
// 	close(fd1);

// 	printf("\nSECOND TEST AGAIN\n");
// 	while ((line = get_next_line(fd2)) != NULL)
// 	{
// 		if (ft_strchr(line, '\n') == 0)
// 			printf("call %d is:%s\n", j, line);
// 		else
// 			printf("call %d is:%s", j, line);
// 		free(line);
// 		j++;
// 	}
// 	close(fd2);

// 	printf("\nTHIRD TEST\n");
// 	printf("negative fd:%s\n", get_next_line(fd1));

// 	printf("\nFOURTH TEST\n");
// 	fd1 = open("text copy.txt", O_RDONLY);
// 	close(fd1);
// 	printf("close fd:%s\n", get_next_line(fd1));
// }