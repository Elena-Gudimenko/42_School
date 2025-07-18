/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_unsigned_to_str.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elvictor <elvictor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 17:10:34 by elvictor          #+#    #+#             */
/*   Updated: 2024/11/16 16:10:38 by elvictor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned int	calculate_how_many_numbers(unsigned int n);

static char			*ft_itoa(unsigned int n);

int	convert_unsigned_to_str(va_list args)
{
	char			*buffer;
	unsigned int	number;
	int				result;
	size_t			length;

	number = va_arg(args, unsigned int);
	buffer = ft_itoa(number);
	if (!buffer)
		return (0);
	length = ft_strlen(buffer);
	result = write(1, buffer, length);
	free(buffer);
	return (result);
}

static char	*ft_itoa(unsigned int n)
{
	unsigned int	length;
	char			*buffer;

	length = calculate_how_many_numbers(n);
	buffer = (char *)malloc(length + 1);
	if (!buffer)
		return (NULL);
	buffer[length] = '\0';
	while (length--)
	{
		buffer[length] = (n % 10) + '0';
		n /= 10;
	}
	return (buffer);
}

static unsigned int	calculate_how_many_numbers(unsigned int n)
{
	unsigned int	length;

	length = 0;
	if (n == 0)
		length = 1;
	while (n)
	{
		n /= 10;
		length++;
	}
	return (length);
}
