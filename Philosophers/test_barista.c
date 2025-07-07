/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_barista.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elvictor <elvictor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 17:51:39 by elvictor          #+#    #+#             */
/*   Updated: 2025/07/07 20:39:45 by elvictor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>

void	*make_coffee(void *data)
{
	printf("Barista is preparing coffee\n");
	sleep(2); //second
	printf("Coffee is ready\n");
	return (NULL);
}

int	main()
{
	pthread_t	baristas[200];
	int			i;
	
	i = 0;
	while (i < 200)
	{
		if (pthread_create(baristas + i, NULL, make_coffee, NULL))
			exit(EXIT_FAILURE);
		i++;
	}
		i = 0;
	while (i < 200)
	{
		printf("Identifier-> %lu\n", baristas[i]);
		i++;
	}
	i = 0;
	while (i < 200)
	{
		pthread_join(baristas[i], NULL);
		i++;
	}
}
