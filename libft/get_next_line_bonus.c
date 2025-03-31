/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: md-harco <md-harco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 16:04:12 by md-harco          #+#    #+#             */
/*   Updated: 2024/12/12 15:16:42 by md-harco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*freejoin(char *s1, char *s2)
{
	char	*temp;

	temp = ft_strjoin((const char *) s1, (const char *) s2);
	if (temp)
		free(s1);
	return (temp);
}

static char	*read_file(char **largebuf, int fd)
{
	char	*buf;
	int		count;

	count = 1;
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
	{
		free(*largebuf);
		return (NULL);
	}
	while (count > 0)
	{
		count = read(fd, buf, BUFFER_SIZE);
		if (count == -1)
		{
			free (buf);
			return (NULL);
		}
		buf[count] = '\0';
		*largebuf = freejoin(*largebuf, buf);
		if (ft_strchr(buf, '\n'))
			count = 0;
	}
	free(buf);
	return (*largebuf);
}

static char	*extract_line(char *largebuf)
{
	char	*line;
	int		i;

	i = 0;
	while (largebuf[i] && largebuf[i] != '\n')
		i++;
	if (largebuf[i] == '\n')
	{
		line = ft_substr(largebuf, 0, i + 1);
		if (!line)
			free(largebuf);
		return (line);
	}
	line = ft_strdup(largebuf);
	if (!line)
		free(largebuf);
	return (line);
}

static char	*clean_buf(char *largebuf)
{
	char	*newbuf;
	size_t	i;

	i = 0;
	while (largebuf[i] && largebuf[i] != '\n')
		i++;
	if (largebuf[i] == '\n' && largebuf[i + 1])
	{
		newbuf = ft_strdup(largebuf + i + 1);
		free(largebuf);
		return (newbuf);
	}
	free(largebuf);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*largebuf;
	char		*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1024)
		return (NULL);
	if (!largebuf)
	{
		largebuf = ft_strdup("");
		if (!largebuf)
			return (NULL);
	}
	if (!read_file(&largebuf, fd) || !*largebuf)
	{
		free(largebuf);
		largebuf = NULL;
		return (NULL);
	}
	line = extract_line(largebuf);
	if (!line)
		return (NULL);
	largebuf = clean_buf(largebuf);
	return (line);
}
/*
int		main()
{
	char	*lu;
	int		fd;

	fd = open("../text2.txt", O_RDONLY);
	if (fd < 0)
		return (1);
	lu = get_next_line(fd);
	printf("|%s|", lu);
	free (lu);
	// Pour plusieurs lignes :
	// while ((lu = get_next_line(fd)) != NULL)
	//{
	//	printf("%s", lu);
	//	free(lu);
	//}
	close (fd);
	return (0);
}*/
