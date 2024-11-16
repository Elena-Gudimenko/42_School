/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elvictor <elvictor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 18:16:00 by elvictor          #+#    #+#             */
/*   Updated: 2024/11/16 17:30:02 by elvictor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	int	result;
	int	x;

	x = 564;
	printf("%c %s\n", 'E', "Elena");
	ft_printf("%c %s\n", 'E', "Elena");
	printf("%i %d %d %i\n", 42, 21, -12, -2147483648);
	ft_printf("%i %d %d %i\n", 42, 21, -12, -2147483648);
	printf("%x %X %X %x\n", 155, 255, 1066, -214);
	ft_printf("%x %X %X %x\n", 155, 255, 1066, -214);
	result = printf("%u, %x, %X, %x\n", 2147483647, 255, 255, -255);
	printf("%d\n", result);
	result = ft_printf("%u, %x, %X, %x\n", 2147483647, 255, 255, -255);
	ft_printf("%d\n", result);
	printf("333%% %p %p\n", &x, (void *)0);
	ft_printf("333%% %p %p\n", &x, (void *)0);
	printf("%d\n", LONG_MIN);
	ft_printf("%d\n", LONG_MIN);
	printf("%d %d\n", INT_MAX, INT_MIN);
	ft_printf("%d %d\n", INT_MAX, INT_MIN);
	printf("%d %d %d %d %d\n", LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	ft_printf("%d %d %d %d %d\n", LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	return (0);
}
