/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsteiner <lsteiner@students.42sp.org.br>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 23:22:51 by lsteiner          #+#    #+#             */
/*   Updated: 2021/08/08 23:22:51 by lsteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format_char(va_list *arguments)
{
	char	target;

	target = va_arg(*arguments, int);
	ft_putchar_fd(target, 1);
	return (1);
}
