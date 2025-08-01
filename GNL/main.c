/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elvictor <elvictor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:34:16 by elvictor          #+#    #+#             */
/*   Updated: 2024/11/30 15:48:23 by elvictor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	int		file_descriptor;
	char	*line;

	if (argc < 2)
	{
		write(1, "File name is missing.\n", 22);
		return (1);
	}
	if (argc > 2)
	{
		write(1, "So much arguments.\n", 19);
		return (1);
	}
	file_descriptor = open(argv[1], O_RDONLY);
	if (file_descriptor == -1)
	{
		write(1, "Error opening file.\n", 20);
		return (1);
	}
	while ((line = get_next_line(file_descriptor)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(file_descriptor);
	return (0);
}
