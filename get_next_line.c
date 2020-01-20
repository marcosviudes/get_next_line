/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviudes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 19:08:31 by mviudes           #+#    #+#             */
/*   Updated: 2020/01/20 19:08:35 by mviudes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void			*ft_memcpy(void *str1, const void *str2, size_t n)
{
	const char	*src;
	char		*dest;
	size_t		i;

	if (!(str1 || str2 || n) || (str1 == NULL && str2 == NULL))
		return (0);
	i = 0;
	dest = str1;
	src = str2;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

size_t			ft_strnlen(const char *s, size_t maxlen)
{
	size_t		len;

	len = 0;
	while (len++ < maxlen)
		if (*s++ == '\0')
			break ;
	return (len - 1);
}

size_t			ft_strlen(const char *str)
{
	int			i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int				get_next_line(int fd, char **line)
{
	static char	*str[4096];
	char		buff[BUFFER_SIZE + 1];
	int			i;
	char		*tmp;

	!str[fd] ? str[fd] = ft_strcdup("", '\0') : str[fd];
	while ((i = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[i] = '\0';
		tmp = ft_strjoin(str[fd], buff);
		free(str[fd]);
		if (ft_strchr((str[fd] = tmp), '\n'))
			break ;
	}
	if (i < 0 || line == NULL)
		return (-1);
	*line = ft_strcdup(str[fd], '\n');
	tmp = NULL;
	if (str[fd][ft_strlen(*line)] != '\0')
		tmp = ft_strcdup(ft_strchr(str[fd], '\n') + 1, '\0');
	free(str[fd]);
	if ((str[fd] = tmp) == NULL)
		return (0);
	return (1);
}
