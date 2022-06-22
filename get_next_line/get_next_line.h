/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldiogo <ldiogo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 16:19:41 by ldiogo            #+#    #+#             */
/*   Updated: 2022/06/22 17:17:44 by ldiogo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#ifndef BUFFER_SIZE
#define BUFFER_SIZE 10
#endif

char	*get_next_line(int fd);
int		ft_strlen(char *str);
char	*ft_strchr(const char *s, int c);
char	*ft_strchrplus(const char *s, int c);
int		ft_strlenline(char *str);
void	*ft_memcpy(void *dest, void *src, size_t len);
char	*ft_strndup(char *str);
char	*ft_strjoin(char *s1, char *s2);
int     strlenq(char *str);
void	*ft_memcpyc(void *dest, char src, size_t len);
char	*ft_exstrchr(char *s);

#endif
