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

void	ft_putptr(void *ptr)
{
	unsigned long	addr;

	addr = (unsigned long)ptr;
	ft_putstr("0x");
	if (addr >= 16)
	{
		ft_putptr((void *)(addr / 16));
		ft_putptr((void *)(addr % 16));
	}
	else
	{
		if (addr < 10)
			ft_putchar(addr + '0');
		else
			ft_putchar(addr - 10 + 'a');
	}
}
