/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonction.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 05:06:35 by smedenec          #+#    #+#             */
/*   Updated: 2025/06/09 17:11:40 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	dispatch(char c, va_list args, int *count)
{
	if (c == '%')
		putpurcent(c, count);
	else if (c == 'c')
		ft_putchar(args, count);
	else if (c == 's')
		ft_putstr(args, count);
	else if (c == 'i' || c == 'd')
		number_decimal(args, count);
	else if (c == 'u')
		number_unsigned(args, count);
	else if (c == 'x' || c == 'X')
		number_hexadecimal(args, count);
}

void	number_decimal(va_list args, int *count)
{
	int	n;

	n = va_arg(args, int);
	ft_putnbr(n, count);
}

void	number_unsigned(va_list args, int *count)
{
	unsigned int	n;

	n = va_arg(args, unsigned int);
	putnbr_unsigned(n, count);
}

void	putnbr_unsigned(unsigned int n, int *count)
{
	if (n < 10)
	{
		write(1, &(char){n + '0'}, 1);
		(*count)++;
	}
	if (n >= 10)
	{
		putnbr_unsigned(n / 10, count);
		putnbr_unsigned(n % 10, count);
	}
}

void	ft_putnbr(int n, int *count)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		count += 11;
	}
	else
	{
		if (n < 0)
		{
			n = n * -1;
			write(1, "-", 1);
			(*count)++;
		}
		if (n < 10)
		{
			write(1, &(char){n + '0'}, 1);
			(*count)++;
		}
		if (n >= 10)
		{
			ft_putnbr(n / 10, count);
			ft_putnbr(n % 10, count);
		}
	}
}

void	ft_putstr(va_list args, int *count)
{
	char	*s;

	s = va_arg(args, char *);
	while (*s)
	{
		write(1, &*s, 1);
		(*count)++;
		s++;
	}
}

void	ft_putchar(va_list args, int *count)
{
	char	c;

	c = (char)va_arg(args, int);
	write(1, &c, 1);
	(*count)++;
}

void	putpurcent(char c, int *count)
{
	write(1, &c, 1);
	(*count)++;
}
