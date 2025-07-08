/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   race_condition.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elvictor <elvictor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 14:24:42 by elvictor          #+#    #+#             */
/*   Updated: 2025/07/08 15:50:41 by elvictor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <stdint.h>

#define TH 1000

// Shared resource
uint64_t		ledger = 0;
// lock
pthread_mutex_t	ledger_lock = PTHREAD_MUTEX_INITIALIZER;

void	*update_ledger(void *data)
{
	// lock
	pthread_mutex_lock(&ledger_lock);
	ledger += 1;
	// unlock
	pthread_mutex_unlock(&ledger_lock);
	return NULL;
}

int main()
{
	pthread_t	waiters[TH];
	
	//pthread_mutex_init(&ledger_lock, NULL);
	for (int i = 0; i < TH; ++i)
	{
		if (pthread_create(waiters + i, NULL, update_ledger, NULL))
			exit(EXIT_FAILURE);
	}
	for (int i = 0; i < TH; ++i)
	{
		pthread_join(waiters[i], NULL);
	}
	printf("\t%lu\n", ledger);
}