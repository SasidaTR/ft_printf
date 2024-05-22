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

int	ft_puthex_upper(unsigned int n)
{
	int	len;

	len = 0;
	if (n >= 16)
	{
		ft_puthex_upper(n / 16);
		ft_puthex_upper(n % 16);
	}
	else
	{
		if (n < 10)
		{
			ft_putchar(n + '0');
			len++;
		}
		else
		{
			ft_putchar(n - 10 + 'A');
			len++;
		}
	}
	return (len);
}
