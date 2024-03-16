/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranaivo <aranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 11:20:34 by aranaivo          #+#    #+#             */
/*   Updated: 2024/03/16 17:12:28 by aranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include "get_next_line.h"

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 10
#endif

char *get_next_line(int fd)
{
	char *temp_data;
	char *result; // variable which stocked buffer data
	char *temp;
	int status;
	static char *data_stocked;

	status = 0;
	size_t read_value = BUFFER_SIZE;
	result = ft_strdup("\0");
	printf("data_stocked_bf : %s\n", data_stocked);
	if (data_stocked)
	{
		printf (" nl = %d \n", check_nl(data_stocked));
		if (check_nl(data_stocked) != 0)
		{
			result = ft_substr(data_stocked, 0, check_nl(data_stocked));
			data_stocked = ft_substr(result, check_nl(data_stocked) + 1, read_value);
			printf("data_stocked : %s\n", data_stocked);
			return (result);
		}
		//printf("HERE \n");
		result = ft_join_until_nl(result, data_stocked);
	}
	// stock temporary data of read function
	temp_data = malloc(BUFFER_SIZE * sizeof(char));
	if (!temp_data)
		return (NULL);
	 //printf("result = %s \n", result);
	while (read_value != 0)
	{
		read_value = read(fd, temp_data, BUFFER_SIZE);
		temp = malloc(read_value * sizeof(char));
		if (!temp)
			return (NULL);
		temp = ft_substr(temp_data, 0, read_value);
		result = ft_join_until_nl(result, temp);
		status = check_nl(result);
		// printf("status = %d \n", status);
		if (status != 0)
		{
			data_stocked = ft_substr(result, status + 1, read_value);
			result = ft_substr(result, 0, status);
			// printf("result = %s \n", result);
			return (result);
		}
		free(temp);
	}

	return (result);
}

int main(void)
{
	int fd = open("./test.txt", O_RDONLY);
	if (fd == -1)
		printf("KO");
	else
	{
		printf("==> %s \n", get_next_line(fd));
		printf("==> %s \n", get_next_line(fd));
		printf("==> %s \n", get_next_line(fd));
	}
}