/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatikedd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 12:32:22 by iatikedd          #+#    #+#             */
/*   Updated: 2025/11/05 11:16:52 by iatikedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_checker(const char *conv, int i, va_list arg)
{
	int	s;

	s = 0;
	if (conv[i + 1] == 'c')
		s = ft_putchar_fd(va_arg(arg, int), 1);
	else if (conv[i + 1] == 's')
		s = ft_putstr_fd(va_arg(arg, char *), 1);
	else if (conv[i + 1] == 'p')
		s = ft_pointer(va_arg(arg, void *));
	else if (conv[i + 1] == 'd' || conv[i + 1] == 'i')
		s = ft_putnbr_fd(va_arg(arg, int), 1);
	else if (conv[i + 1] == 'u')
		s = ft_putnbr_unsigned(va_arg(arg, unsigned int));
	else if (conv[i + 1] == 'x')
		s = ft_putnbr_lower_base(va_arg(arg, unsigned int));
	else if (conv[i + 1] == 'X')
		s = ft_putnbr_upper_base(va_arg(arg, unsigned int));
	else if (conv[i + 1] == '%')
		s = ft_putchar_fd('%', 1);
	else
	{
		s = ft_putchar_fd(conv[i], 1);
		s += ft_putchar_fd(conv[i + 1], 1);
	}
	return (s);
}

static int	ft_printer(const char *conv, va_list arg)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (conv[i])
	{
		if (conv[i] == '%')
		{
			if (conv[i + 1])
			{
				len += ft_checker(conv, i, arg);
				i += 2;
			}
			else
				return (-1);
		}
		else
		{
			ft_putchar_fd(conv[i], 1);
			len++;
			i++;
		}
	}
	return (len);
}

int	ft_printf(const char *conv, ...)
{
	int		len;
	va_list	arg;

	if (!conv)
		return (-1);
	if (write(1, "", 0) < 0)
		return (-1);
	va_start(arg, conv);
	len = ft_printer(conv, arg);
	va_end(arg);
	return (len);
}
