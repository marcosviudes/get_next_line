/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviudes <mviudes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 21:42:05 by mviudes           #+#    #+#             */
/*   Updated: 2020/01/20 19:01:50 by mviudes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			main(void)
{
	int		fd;
	char	*line;
	int		i;

	fd = open("prueba.txt", O_RDONLY);
	i = 1;
	while (i != 0)
	{
		i = get_next_line(fd, &line);
		if (i == -1)
		{
			printf("ERROR");
			return (0);
		}
		if (i > 0)
			printf("%s$\n", line);
	}
	close(fd);
	printf("End of file");
	return (0);
}
