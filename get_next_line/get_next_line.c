/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldiogo <ldiogo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 16:55:52 by ldiogo            #+#    #+#             */
/*   Updated: 2022/06/22 17:16:48 by ldiogo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h" 

char	*get_next_line(int fd)
{
	static char *line;
	char *str;
	int i;
	int n;
	char *rtn;
	char *cpy;
	char *buffer;
	
	n = 0;
	i = 1;	
	if (!line)
	{
		line = malloc(sizeof (char) * 1);
		line[0] = '\0';
	}
	//printf("line = %s\n---------------\n", line);	
	str = malloc(sizeof (char) * BUFFER_SIZE + 1);
	while (!(ft_strchr(line, '\n')) && i)
	{	
		cpy = line;
		i = read (fd, buffer, BUFFER_SIZE);
		buffer[i] = '\0';
		printf("buffer = %s\n---------------\n", buffer);
		line = ft_strjoin(cpy, buffer);
		//free(cpy);
		//printf("%s\n", line);
	}	
	free(str);
	//printf("\nline = %s\n---------------\n", line);
//	rtn = malloc(sizeof (char) * (ft_strlen(line) + 1));
	printf("line1 = %s\n---------------\n", line);
	rtn = ft_strndup(line);
	printf("rtn = %s\n---------------\n", rtn);
	//printf("antes strchr = %s\n---------------\n", line);	
	line = ft_exstrchr(line);
	//printf("line = %s\n---------------\n", line);	
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
	char *fds;
	fd = open ("42_no_nl", O_RDWR);
	fds = get_next_line(fd);
	printf("1 gnl\n");
	for(int i = 0; i < 6; i++)
	{
		free(fds);
		fds = get_next_line(fd);	
		printf("1 gnl\n");	
	}
	//printf("%s\n", fds);
	system("leaks a.out");
}

