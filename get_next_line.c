/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranaivo <aranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 11:20:34 by aranaivo          #+#    #+#             */
/*   Updated: 2024/03/22 15:24:14 by aranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include "get_next_line.h"

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 100
#endif

char *manage_stocked(char **data_stocked, int *read_value)
{
	char *result;
	char *temp_content;

	temp_content = NULL;
	result = ft_strdup("");
	if (*data_stocked )
	{
		if (check_nl(*data_stocked) != -1)
		{
			result = ft_substr(*data_stocked, 0, check_nl(*data_stocked) + 1);
			*data_stocked = ft_substr(*data_stocked, check_nl(*data_stocked) + 1, ft_strlen(*data_stocked) - check_nl(*data_stocked));
		}
	}
	return (result);
}

char *get_only_line(char **data_stocked, char **result, int read_value)
{
	char *temp;

	if (check_nl(*result) != -1)
	{
		*data_stocked = ft_substr(*result, check_nl(*result) + 1, read_value);
		temp = ft_substr(*result, 0, check_nl(*result) + 1);
		*result = ft_strdup(temp);
	}
	return (free(temp), *result);
}

char *get_only_read_char(char *temp_content, char **result, int read_value)
{
	char *temp;

	temp = ft_substr(temp_content, 0, read_value);
	*result = ft_join_until_nl(*result, temp);
	return (free(temp), *result);
}

char *get_next_line(int fd)
{
	static char *result;
	char *temp;
	static char *data_stocked;
	static int read_value;
	char *temp_content;

	if (!(result))
		read_value = 1;
	result = ft_strdup("");
	if (data_stocked && (check_nl(data_stocked) != -1))
	 	return (manage_stocked(&data_stocked, &read_value));
	if (data_stocked)
		result = ft_join_until_nl(result, data_stocked);

	if (read_value == 0 || fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (read_value != 0)
	{
		temp_content = malloc(BUFFER_SIZE * sizeof(char));
		if (!temp_content)
			return (NULL);
		read_value = read(fd, temp_content, BUFFER_SIZE);
		result = get_only_read_char(temp_content, &result, read_value);
		if (check_nl(result) != -1)
			return (free(temp_content), get_only_line(&data_stocked, &result, read_value));
	}
	return (result);
}

int main(void)
{
	int fd = open("./test.txt", O_RDONLY);
	char *res = "";
	if (fd == -1)
		printf("KO");
	else
	{
		while (res)
		{
			// free(res);
			res = get_next_line(fd);
			printf("%s", res);
		}
		// get_next_line(fd);
		// get_next_line(fd);
		// get_next_line(fd);
	}
	free(res);
}
