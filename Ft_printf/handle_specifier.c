/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_specifier.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elvictor <elvictor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 17:09:41 by elvictor          #+#    #+#             */
/*   Updated: 2024/11/16 15:22:20 by elvictor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_specifier(char specifier, va_list args, int total)
{
	int	printed;

	printed = 0;
	if (specifier == 'c')
		printed = print_char(args);
	else if (specifier == 's')
		printed = print_str(args);
	else if (specifier == 'd' || specifier == 'i')
		printed = convert_int_to_str(args);
	else if (specifier == 'x' || specifier == 'X')
		printed = convert_hex_to_str(args, specifier);
	else if (specifier == 'u')
		printed = convert_unsigned_to_str(args);
	else if (specifier == '%')
		printed = print_percentage();
	else if (specifier == 'p')
		printed = convert_ptr_to_str(args);
	else
	{
		if (total > 0)
			return (-1);
		write(1, "%", 1);
	}
	return (printed);
}
