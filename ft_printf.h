/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatikedd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 09:04:59 by iatikedd          #+#    #+#             */
/*   Updated: 2025/11/02 15:44:52 by iatikedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

size_t	ft_strlen(const char*s);
int		ft_printf(const char *conv, ...);
int		ft_pointer(void *ptr);
int		ft_putnbr_lower_base(unsigned int i);
int		ft_putnbr_upper_base(unsigned int i);
int		ft_putnbr_unsigned(unsigned int nb);
int		ft_putchar_fd(char c, int fd);
int		ft_putnbr_fd(int n, int fd);
int		ft_putstr_fd(char *s, int fd);

#endif
