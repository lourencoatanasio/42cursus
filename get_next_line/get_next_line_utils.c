/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldiogo <ldiogo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 16:55:54 by ldiogo            #+#    #+#             */
/*   Updated: 2022/06/22 17:16:22 by ldiogo           ###   ########.fr       */
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

	//printf("%s\n", s);
	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char*)(s + i));
		i++;
	}
	if (s[i] == (char)c)
		return ((char*)(s + i));
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

int	ft_strlenline(char *str)
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

/*void	*ft_memcpyc(void *dest, char src, size_t len)
{
	char	*d;

	if (!dest && !src)
		return (NULL);
	d = dest;
	while (len--)
	{
		*d = src;
	}
	return (dest);
}*/

char	*ft_strndup(char *str)
{
	void	*dest;

	dest = malloc(ft_strlenline(str) + 1);
	if (dest == NULL)
		return (NULL);
	return ((char *) ft_memcpy(dest, str, ft_strlenline(str) + 1));
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

int strlenq(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\n')
	{
		i++;
	}
	return (i + 1);
}

size_t	ft_strlcpy(char *dst, char *src, size_t size)
{
	size_t	i;
	if (!dst || !src)
		return (0);
	else if (!size)
		return (ft_strlen(src));
	i = 0;
	while (src[i] && i < (size - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

char	*ft_exstrchr(char *s)
{
	int		i;
	char	*tmp;
	i = 0;
	while (s[i] != '\n' && s[i])
		i++;
	if (s[i] == '\0')
	{
		free(s);
		return (NULL);
	}
	tmp = malloc((ft_strlen(s) - i) + 1);
	if (!tmp)
		return (NULL);
	ft_strlcpy(tmp, s + i + 1, ft_strlen(s) - i + 1);
	free(s);
	return (tmp);
}
