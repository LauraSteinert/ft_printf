/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsteiner <lsteiner@students.42sp.org.br>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 18:25:53 by lsteiner          #+#    #+#             */
/*   Updated: 2021/08/04 18:25:53 by lsteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	cases(const char *format, int current_index, va_list *arguments)
{
	char	next_char;
	int		length;

	length = 1;
	next_char = format[current_index + 1];
	if (next_char == 0 || next_char == '\0')
		return (0);
	if (next_char == 'c')
		length = format_char(arguments);
	else if (next_char == 's')
		length = format_str(arguments);
	else if (next_char == 'p')
		length = format_ptr(arguments);
	else if (next_char == 'd' || next_char == 'i')
		length = format_int(arguments);
	else if (next_char == 'u')
		length = format_unsigned(arguments);
	else if (next_char == 'X')
		length = format_hexa_u(arguments);
	else if (next_char == 'x')
		length = format_hexa_l(arguments);
	else if (next_char == '%')
		ft_putchar_fd('%', 1);
	return (length);
}

int	ft_printf(const char *format, ...)
{
	int		length;
	int		char_counter;
	int		printed;
	va_list	arguments;

	length = 0;
	char_counter = 0;
	va_start(arguments, format);
	while (format[char_counter])
	{
		if (format[char_counter] != '%')
		{
			length++;
			ft_putchar_fd(format[char_counter], 1);
		}
		else
		{
			printed = cases(format, char_counter, &arguments);
			char_counter++;
			length += printed;
		}
		char_counter++;
	}
	va_end(arguments);
	return (length);
}
