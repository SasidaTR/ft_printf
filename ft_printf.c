/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trischma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:23:17 by trischma          #+#    #+#             */
/*   Updated: 2024/05/21 14:23:19 by trischma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_handle_format(char format, va_list args)
{
	if (format == 'c')
		ft_putchar(va_arg(args, int));
	else if (format == 's')
		ft_putstr(va_arg(args, char *));
	else if (format == 'p')
		ft_putptr(va_arg(args, void *));
	else if (format == 'd' || format == 'i')
		ft_putnbr(va_arg(args, int));
	else if (format == 'u')
		ft_putnbr_u(va_arg(args, unsigned int));
	else if (format == 'x')
		ft_puthex(va_arg(args, unsigned int));
	else if (format == 'X')
		ft_puthex_upper(va_arg(args, unsigned int));
	else if (format == '%')
		ft_putchar('%');
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;

	va_start(args, format);
	i = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			ft_handle_format(format[i + 1], args);
			i++;
		}
		else
			ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (0);
}
