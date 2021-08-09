/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_unsigned.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsteiner <lsteiner@students.42sp.org.br>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 23:31:51 by lsteiner          #+#    #+#             */
/*   Updated: 2021/08/08 23:31:51 by lsteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_len(long n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		len = 1;
	if (n < 0)
	{
		n = n * -1;
		len++;
	}
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static void	ft_put_unsigned(unsigned int n, int fd)
{
	char				s[11];
	unsigned int		counter;
	int					i;

	i = 1;
	counter = n / 10;
	while (counter)
	{
		counter /= 10;
		i++;
	}
	s[i] = '\0';
	while (i--)
	{
		s[i] = (n % 10) + '0';
		n /= 10;
	}
	ft_putstr_fd(s, fd);
}

int	format_unsigned(va_list *arguments)
{
	unsigned int	target;

	target = va_arg(*arguments, unsigned int);
	ft_put_unsigned(target, 1);
	target = ft_len((long)target);
	return (target);
}
