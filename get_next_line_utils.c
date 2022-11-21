/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbendahh <zbendahh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 11:07:53 by zbendahh          #+#    #+#             */
/*   Updated: 2022/11/21 14:49:18 by zbendahh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*test(char c, int i)
{
	char	*p;

	if (c == '\0')
	{
		p = (char *)malloc(i + 1);
		p[i] = '\0';
		if (!p)
			return (NULL);
	}
	else
	{
		p = (char *)malloc(i + 2);
		p[i] = '\n';
		p[i + 1] = '\0';
		if (!p)
			return (NULL);
	}
	return (p);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

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
	while (str[j] && str[j] != '\n')
	{
		p[j] = str[j];
		j++;
	}
	return (p);
}

int	ft_nlchr(char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
	{
		if (s[i] == '\n')
			return (0);
		i++;
	}
	return (1);
}

char	*next_line(char *s)
{
	int		i;
	char	*str;
	int		j;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\0')
		return (free(s), NULL);
	str = (char *)malloc(ft_strlen(s) - i + 1);
	if (!str)
		return (NULL);
	j = 0;
	while (s[++i])
		str[j++] = s[i];
	str[j] = '\0';
	return (free(s), str);
}
