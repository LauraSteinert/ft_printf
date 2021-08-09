/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_hexa_u.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsteiner <lsteiner@students.42sp.org.br>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 22:27:16 by lsteiner          #+#    #+#             */
/*   Updated: 2021/08/08 22:27:16 by lsteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	treat_zero(long int number)
{
	if (number == 0)
	{
		ft_putchar_fd('0', 1);
		return (1);
	}
	return (0);
}

int	format_hexa_u(va_list *arguments)
{
	char		hexa_num[100];
	int			i;
	int			j;
	int			temp;
	long int	number;

	i = 1;
	number = va_arg(*arguments, unsigned int);
	if (treat_zero(number))
		return (1);
	while (number != 0)
	{
		temp = number % 16;
		if (temp < 10)
			temp = temp + 48;
		else
			temp = temp + 55;
		hexa_num[i++] = temp;
		number = number / 16;
	}
	j = i;
	while (--j > 0)
		ft_putchar_fd(hexa_num[j], 1);
	return (i - 1);
}
