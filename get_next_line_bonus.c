/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgencali <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 12:06:15 by mgencali          #+#    #+#             */
/*   Updated: 2022/12/22 12:13:43 by mgencali         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next(char *arr)
{
	char	*temp;
	int		i;
	int		j;

	i = 0;
	while (arr[i] && arr[i] != '\n')
		i++;
	if (!arr[i])
	{
		free(arr);
		return (NULL);
	}
	temp = (char *)malloc(sizeof(char) * (ft_strlen(arr) - i + 1));
	if (!temp)
		return (NULL);
	i++;
	j = 0;
	while (arr[i])
		temp[j++] = arr[i++];
	temp[j] = '\0';
	free(arr);
	return (temp);
}

char	*get_line(char *arr)
{
	char	*line;
	int		indx;

	indx = 0;
	if (!arr[indx])
		return (NULL);
	while (arr[indx] && arr[indx] != '\n')
		indx++;
	line = (char *)malloc(sizeof(char) * (indx + 2));
	if (!line)
		return (NULL);
	indx = 0;
	while (arr[indx] && arr[indx] != '\n')
	{
		line[indx] = arr[indx];
		indx++;
	}
	if (arr[indx] == '\n')
	{
		line[indx] = arr[indx];
		indx++;
	}
	line[indx] = '\0';
	return (line);
}

char	*read_arr(int fd, char *arr)
{
	char	*temp;
	int		size;

	temp = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!temp)
		return (NULL);
	size = 1;
	while (size != 0 && !ft_strchr(arr, '\n'))
	{
		size = read(fd, temp, BUFFER_SIZE);
		if (size == -1)
		{
			free(temp);
			return (NULL);
		}
		temp[size] = '\0';
		arr = ft_strjoin(arr, temp);
	}
	free(temp);
	return (arr);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*arr[4096];

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 4096)
		return (0);
	arr[fd] = read_arr(fd, arr[fd]);
	if (!arr[fd])
		return (NULL);
	line = get_line(arr[fd]);
	arr[fd] = get_next(arr[fd]);
	return (line);
}
/*
int main()
{
    int i = open("test.txt",O_RDONLY);
    int a = 0;
    for ( a = 0; a < 4; a++)
    {
        printf("%s", get_next_line(i));
    }

    return 0;
} */
