/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsteiner <lsteiner@students.42sp.org.br>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 22:49:46 by lsteiner          #+#    #+#             */
/*   Updated: 2021/08/08 22:49:46 by lsteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	treat_zero(unsigned long number)
{
	if (number == 0)
	{
		ft_putstr_fd("0x0", 1);
		return (1);
	}
	return (0);
}

int	format_ptr(va_list *arguments)
{
	unsigned long	number;
	char			hexa_num[100];
	int				i;
	int				j;
	int				temp;

	i = 1;
	number = va_arg(*arguments, unsigned long);
	if (treat_zero(number))
		return (3);
	while (number != 0)
	{
		temp = number % 16;
		if (temp < 10)
			temp = temp + 48;
		else
			temp = temp + 87;
		hexa_num[i++] = temp;
		number = number / 16;
	}
	j = i;
	ft_putstr_fd("0x", 1);
	while (--j > 0)
		ft_putchar_fd(hexa_num[j], 1);
	return (i + 1);
}
