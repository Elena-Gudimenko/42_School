/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elvictor <elvictor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 17:04:01 by elvictor          #+#    #+#             */
/*   Updated: 2024/11/16 17:10:29 by elvictor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		printed_char;

	if (!format)
		return (-1);
	printed_char = 0;
	va_start(args, format);
	printed_char += parse_format(format, args);
	va_end(args);
	return (printed_char);
}
