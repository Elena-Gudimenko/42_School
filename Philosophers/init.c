/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elvictor <elvictor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 17:36:54 by elvictor          #+#    #+#             */
/*   Updated: 2025/07/04 14:31:25 by elvictor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	data_init(t_table *table)
{
	table->end_simulation = false;
	table->philos = safe_malloc(table->philo_nbr);
	
}
