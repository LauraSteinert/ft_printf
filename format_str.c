/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsteiner <lsteiner@students.42sp.org.br>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 23:26:47 by lsteiner          #+#    #+#             */
/*   Updated: 2021/08/08 23:26:47 by lsteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format_str(va_list *arguments)
{
	char	*target;
	int		length;

	target = va_arg(*arguments, char *);
	if (target == NULL)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	length = ft_strlen(target);
	if (length == 0)
		return (0);
	ft_putstr_fd(target, 1);
	return (length);
}
