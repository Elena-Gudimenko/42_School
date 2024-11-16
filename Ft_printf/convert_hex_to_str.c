/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_hex_to_str.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elvictor <elvictor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:36:50 by elvictor          #+#    #+#             */
/*   Updated: 2024/11/15 15:55:46 by elvictor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	calculate_hex_length(unsigned int number);

static char	*int_to_hex(va_list args, char specifier);

int	convert_hex_to_str(va_list args, char specifier)
{
	char	*buffer;
	size_t	length;
	int		result;

	buffer = int_to_hex(args, specifier);
	if (!buffer)
		return (0);
	length = ft_strlen(buffer);
	result = write(1, buffer, length);
	free(buffer);
	return (result);
}

static char	*int_to_hex(va_list args, char specifier)
{
	char			*hex_digits;
	unsigned int	length;
	unsigned int	number;
	char			*buffer;

	if (specifier == 'x')
		hex_digits = "0123456789abcdef";
	else
		hex_digits = "0123456789ABCDEF";
	number = va_arg(args, unsigned int);
	length = calculate_hex_length(number);
	buffer = (char *)malloc(length + 1);
	if (!buffer)
		return (NULL);
	buffer[length] = '\0';
	while (length--)
	{
		buffer[length] = hex_digits[number % 16];
		number /= 16;
	}
	return (buffer);
}

static int	calculate_hex_length(unsigned int number)
{
	unsigned int	length;

	length = 0;
	if (number == 0)
		length = 1;
	while (number)
	{
		number /= 16;
		length++;
	}
	return (length);
}
