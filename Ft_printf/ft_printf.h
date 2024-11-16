/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elvictor <elvictor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:45:36 by elvictor          #+#    #+#             */
/*   Updated: 2024/11/16 17:09:32 by elvictor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
int		handle_specifier(char specifier, va_list args, int total);
int		parse_format(const char *format, va_list args);
int		print_char(va_list args);
size_t	ft_strlen(const char *s);
int		print_str(va_list args);
int		convert_int_to_str(va_list args);
int		convert_hex_to_str(va_list args, char specifier);
int		convert_unsigned_to_str(va_list args);
int		convert_ptr_to_str(va_list args);
int		print_percentage(void);

#endif
