/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbendahh <zbendahh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 12:49:40 by zbendahh          #+#    #+#             */
/*   Updated: 2022/11/21 14:50:24 by zbendahh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_substr(char *str)
{
	int		i;
	int		j;
	char	*p;

	i = 0;
	j = 0;
	if (str[0] == '\0')
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	p = test(str[i], i);
	if (!p)
		return (NULL);
	while (str[j] && str[j] != '\n')
	{
		p[j] = str[j];
		j++;
	}
	return (p);
}

char	*get_next_line(int fd)
{
	static char	*s[10240];
	char		*buffer;
	char		*len;
	int			rd;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	rd = 1;
	while (ft_nlchr(s[fd]) == 1 && rd)
	{
		rd = read(fd, buffer, BUFFER_SIZE);
		if (rd == -1)
			return (free(buffer), NULL);
		buffer[rd] = '\0';
		s[fd] = ft_strjoin(s[fd], buffer);
	}
	len = ft_substr(s[fd]);
	s[fd] = next_line(s[fd]);
	return (free(buffer), len);
}
