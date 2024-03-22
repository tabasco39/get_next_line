/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranaivo <aranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 11:21:52 by aranaivo          #+#    #+#             */
/*   Updated: 2024/03/21 07:56:54 by aranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//get length of string
size_t ft_strlen(char *str)
{
    size_t  i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

char    *ft_strdup(char *str)
{
    char    *result;
    int     i;

    i = 0;
    result = malloc((ft_strlen(str) + 1) * sizeof(char));
    if (!result)
        return (NULL);
    while (str[i])
    {
        result[i] = str[i];
        i++;
    }
    result[i] = '\0';
    return (result);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*result;

	i = start;
	j = 0;
	if (len > ft_strlen((char *)s) - (size_t)start)
		len = ft_strlen((char *)s) - (size_t)start; 
	if ((size_t)start >= ft_strlen((char *)s))
		len = 0;
	result = (char *)malloc((len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	else
	{
		while (j < len && (size_t)start < ft_strlen((char *)s))
		{
			result[j] = s[i];
			j++;
			i++;
		}
	}
	result[j] = '\0';
	return (result);
}

//concatenate string and until the newline character
char    *ft_join_until_nl(char *dest, char *str)
{
    char    *result;
    int     i;
    int     j;

    i = 0;
    result = malloc((ft_strlen(str) + ft_strlen(dest) + 1) * sizeof(char));
    if (!result)
        return (NULL);
    while (dest[i])
    {
        result[i] = dest[i];
        i++;
    }
    j = 0;
    while(str[j])
    {
        result[i] = str[j];
        i++;
        j++;
    }
    result[i] = '\0';
    return (result);
}

int	check_nl(char *str)
{
	int	i;

    i = 0;
    // if(str[0] == '\n')
    // {
    //     return (0);
    // }
	while(str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}
