/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeepach <gyeepach@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 16:56:37 by gyeepach          #+#    #+#             */
/*   Updated: 2024/04/24 16:56:25 by gyeepach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	ft_putstr(char *str);
int	ft_putnbr(int n);
int	ft_puthexa(unsigned long long n, int base);
int	ft_putchar(int c);
int	ft_putaddress(void *p);
int	ft_putunsigned(unsigned int n);

#endif