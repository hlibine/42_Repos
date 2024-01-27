/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:10:43 by hlibine           #+#    #+#             */
/*   Updated: 2024/01/08 13:49:54 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

char	*get_next_line(int fd);
int		gnl_strlen(const char *s);
size_t	gnl_strlcat(char *dst, const char *src, size_t dstsize);
char	*gnl_strjoin(char const *s1, char const *s2);
char	*gnl_strdup(const char *s1);
size_t	gnl_strlcpy(char *dst, const char *src, size_t dstsize);
int		gnl_strlencust(const char *str);

#endif