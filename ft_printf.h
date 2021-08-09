/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsteiner <lsteiner@students.42sp.org.br>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 00:14:23 by lsteiner          #+#    #+#             */
/*   Updated: 2021/08/09 00:14:23 by lsteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "./libft/source/libft.h"

# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	format_hexa_u(va_list *arguments);
int	format_hexa_l(va_list *arguments);
int	format_ptr(va_list *arguments);
int	format_char(va_list *arguments);
int	format_str(va_list *arguments);
int	format_int(va_list *arguments);
int	format_unsigned(va_list *arguments);

#endif
