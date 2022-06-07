/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldiogo <ldiogo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 16:55:52 by ldiogo            #+#    #+#             */
/*   Updated: 2022/06/02 16:31:02 by ldiogo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h" 

char	*get_next_line(int fd)
{
	static char *line;
	char *str;
	int i;
	char *rtn;
	char *rtnf;
	
	i = 1;	
	if (!line)
	{
		line = malloc(sizeof (char) * 1);
		line[0] = '\0';
	}
	str = malloc(sizeof (char) * BUFFER_SIZE + 1);
	while (!(ft_strchr(str, '\n')) && i)
	{
		i = read (fd, str, BUFFER_SIZE);
		str[i + 1] = '\0';
		rtn = line;
		line = ft_strjoin(rtn, str);
		//printf("===========\n%s\n", line);
	}
	line = ft_strchrplus(line, '\n');
	rtnf = ft_strndup (rtn);
	//printf("\n%s\n===============\n", rtnf);
	//printf("\nline = %s\n---------------\n", line);
	free (str);
	return (rtnf);
}

/*int main()
{
	int fd;

	fd = open ("file.txt", O_RDWR);
	get_next_line(fd);
	get_next_line(fd);
	//get_next_line(fd);
	//get_next_line(fd);
	//get_next_line(fd);			
	//system("leaks a.out");
}*/

