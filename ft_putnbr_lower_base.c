/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_lower_base.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatikedd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 11:25:38 by iatikedd          #+#    #+#             */
/*   Updated: 2025/11/02 15:41:52 by iatikedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_lower_base(unsigned int i)
{
	char	*base;
	int		len;

	len = 0;
	base = "0123456789abcdef";
	if (i >= 16)
		len += ft_putnbr_lower_base(i / 16);
	ft_putchar_fd(base[i % 16], 1);
	len += 1;
	return (len);
}
