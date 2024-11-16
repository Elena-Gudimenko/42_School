/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_int_to_str.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elvictor <elvictor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 19:31:15 by elvictor          #+#    #+#             */
/*   Updated: 2024/11/16 17:26:29 by elvictor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	calculate_how_many_numbers(int n);

static char	*ft_itoa(int n);

int	convert_int_to_str(va_list args)
{
	char	*buffer;
	int		number;
	size_t	length;
	int		result;

	number = va_arg(args, int);
	buffer = ft_itoa(number);
	length = ft_strlen(buffer);
	result = write(1, buffer, length);
	free(buffer);
	return (result);
}

static char	*ft_itoa(int n)
{
	char			*buffer;
	int				length;
	unsigned int	number;

	if (n < 0)
		number = -n;
	else
		number = n;
	length = calculate_how_many_numbers(n);
	buffer = (char *)malloc(length + 1);
	if (!buffer)
		return (NULL);
	buffer[length] = '\0';
	while (length--)
	{
		buffer[length] = (number % 10) + '0';
		number /= 10;
	}
	if (n < 0)
		buffer[0] = '-';
	return (buffer);
}

static int	calculate_how_many_numbers(int n)
{
	int	length;

	length = 0;
	if (n <= 0)
		length = 1;
	while (n)
	{
		n /= 10;
		length++;
	}
	return (length);
}
