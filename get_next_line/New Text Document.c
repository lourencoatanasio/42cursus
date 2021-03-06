#include "get_next_line.h" 

char	*get_next_line(int fd)
{
	static char *line;
	char *str;
	int i;
	int n;
	char *rtn;
	char *rtnf;
	
	n = 0;
	i = 1;	
	if (!line)
	{
		line = malloc(sizeof (char) * 1);
		line[0] = '\0';
	}
	//str = malloc(sizeof (char) * BUFFER_SIZE + 1);
	while (!(ft_strchr(str, '\0')) && i)
	{
		str = malloc(sizeof (char) * BUFFER_SIZE + 1);
		i = read (fd, str, BUFFER_SIZE);
		str[i + 1] = '\0';
		line = ft_strjoin(line, str);
		free(str);
		//printf("===========\n%s\n", line);
	}
	//printf("\nline = %s\n---------------\n", line);
	rtn = malloc(sizeof (char) * (ft_strlen(line) + 1));
	//printf("line1 = %s\n---------------\n", line);
	rtn = ft_trim(line);
	printf("line = %s\n---------------\n", rtn);
	while (rtn[n] != '\0')
	{
		n++;
	}
	rtnf = &line[0];
	i = 0;
	while(line[i] != '\n')
	{
		i++;
		rtnf++;
	}
	rtnf++;
	line = rtnf;
	//rtn = line;
	//line = ft_strchrplus(line, '\n');
	//rtnf = ft_strndup (rtn);
	//printf("ft_trim = %s\n===============\n", ft_trim(rtn));
	//printf("n = %i\n---------------\n", n);	
	return (rtn);
}

int main()
{
	int fd;

	fd = open ("file.txt", O_RDWR);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);

	//system("leaks a.out");
}


#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#ifndef BUFFER_SIZE
#define BUFFER_SIZE 50
#endif

char	*get_next_line(int fd);
int		ft_strlen(char *str);
char	*ft_strchr(const char *s, int c);
char	*ft_strchrplus(const char *s, int c);
int		ft_strlenline(char *str);
void	*ft_memcpy(void *dest, void *src, size_t len);
char	*ft_strndup(char *str);
char	*ft_strjoin(char *s1, char *s2);
char    *ft_trim (char *str);
char	*ft_strjoinn(char *s1, char *s2, int n);
int     strlenq(char *str);
void	*ft_memcpyc(void *dest, char src, size_t len);

#endif

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

char	*ft_strjoinn(char *s1, char *s2, int n)
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
	ft_memcpy(str + size1, s2, n);
	str[size1 + size2] = '\0';
	return (str);
}
char *ft_trim (char *str)
{
	char *cpy;
	int i;
	i = 0;

	while (str[i] != '\n')
	{
		i++;
	}
	cpy = (char *)malloc(sizeof(char) * i + 1);
	cpy = ft_strjoinn (cpy, str, i);
	cpy[i] = '\n';
	return (cpy);
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
