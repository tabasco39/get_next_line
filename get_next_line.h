/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranaivo <aranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 11:23:24 by aranaivo          #+#    #+#             */
/*   Updated: 2024/03/16 15:03:13 by aranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdio.h>
#include <stdlib.h>

int     ft_strlen(char *str);
char    *ft_join_until_nl(char *dest, char *str);
char    *ft_strdup(char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int	    check_nl(char *str);





#endif