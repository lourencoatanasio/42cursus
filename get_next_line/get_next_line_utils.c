/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldiogo <ldiogo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 16:55:54 by ldiogo            #+#    #+#             */
/*   Updated: 2022/06/02 16:19:25 by ldiogo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)(s + i));
	return (NULL);
}

char	*ft_strchrplus(const char *s, int c)
{
	int	i;

	i = 0;	
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)(s + i + 1));
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)(s + i + 1));
	return (NULL);
}

int	ft_strlendup(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
	{
		i++;
	}
	return (i);
}

void	*ft_memcpy(void *dest, void *src, size_t len)
{
	char	*d;
	char	*s;

	if (!dest && !src)
		return (NULL);
	d = dest;
	s = src;
	while (len--)
	{
		*d++ = *s++;
	}
	return (dest);
}

char	*ft_strndup(char *str)
{
	void	*dest;

	dest = malloc(ft_strlendup(str) + 1);
	if (dest == NULL)
		return (NULL);
	return ((char *) ft_memcpy(dest, str, ft_strlendup(str) + 1));
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		size1;
	int		size2;
	char	*str;

	if (!s1 || !s2)
		return (0);
	size1 = ft_strlen(s1);
	size2 = ft_strlen(s2);
	str = (char *)malloc((sizeof(char) + size1 + size2));
	if (!str)
	{
		return (0);
	}
	ft_memcpy(str, s1, size1);
	ft_memcpy(str + size1, s2, size2);
	str[size1 + size2] = '\0';
	return (str);
}
