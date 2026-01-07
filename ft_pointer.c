/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatikedd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 11:58:05 by iatikedd          #+#    #+#             */
/*   Updated: 2025/11/02 15:45:57 by iatikedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putnbr_base(unsigned long long i)
{
	char	*base;
	int		len;

	len = 0;
	base = "0123456789abcdef";
	if (i >= 16)
		len += ft_putnbr_base(i / 16);
	ft_putchar_fd(base[i % 16], 1);
	len += 1;
	return (len);
}

int	ft_pointer(void *ptr)
{
	int					x;
	unsigned long long	p;

	if (!ptr)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	p = (unsigned long long)ptr;
	write(1, "0x", 2);
	x = 2;
	x += ft_putnbr_base(p);
	return (x);
}
