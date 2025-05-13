/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elvictor <elvictor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 16:02:13 by elvictor          #+#    #+#             */
/*   Updated: 2025/05/13 17:04:55 by elvictor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	free_matrix(char **argv)
{
	int	i;

	i = -1;
	if (argv == NULL || *argv == NULL)
		return ;
	while (argv[i])
		free(argv[i++]);
	free(argv - 1);
}

void	free_stack(t_stack_node **stack)
{
	t_stack_node	*tmp;
	t_stack_node	*current;

	if (stack == NULL)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

void	error_free(t_stack_node **a, char **argv, bool flag_argc_2)
{
	free_stack(a);
	if (flag_argc_2)
		free_matrix(argv);
	write(2, "Error\n", 6);
	exit(1);
}

int	error_syntax(char *str_nbr)
{
	if (!(*str_nbr == '+' || *str_nbr == '-'
			|| (*str_nbr >= '0' && *str_nbr <= '9')))
		return (1);
	if ((*str_nbr == '+' || *str_nbr == '-')
		&& !(str_nbr[1] >= '0' && str_nbr[1] <= '9'))
		return (1);
	while (*++str_nbr)
	{
		if (!(*str_nbr >= '0' && *str_nbr <= '9'))
			return (1);
	}
	return (0);
}

int	error_duplicate(t_stack_node *a, int nbr)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->value == nbr)
			return (1);
		a = a->next;
	}
	return (0);
}
