/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elvictor <elvictor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 19:03:20 by elvictor          #+#    #+#             */
/*   Updated: 2024/11/16 15:24:13 by elvictor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_str(va_list args)
{
	char	*str;
	size_t	lenght;

	str = (char *)va_arg(args, char *);
	if (!str)
		str = "(null)";
	lenght = ft_strlen(str);
	return (write(1, str, lenght));
}
