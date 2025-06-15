/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonction.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 05:06:35 by smedenec          #+#    #+#             */
/*   Updated: 2025/06/15 21:56:54 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	dispatch(char c, va_list args, int *count)
{
	if (c == '%')
		count_print(c, count);
	else if (c == 'c')
	{
		c = (char)va_arg(args, int);
		count_print(c, count);
	}
	else if (c == 's')
		ft_putstr(args, count);
	else if (c == 'i' || c == 'd')
		number_decimal(args, count);
	else if (c == 'u')
		number_unsigned(args, count);
	else if (c == 'x' || c == 'X')
		number_hexa(args, c, count);
	else if (c == 'p')
		number_adress(args, c, count);
}

void	puthexa(long unsigned int n, char c, int *count)
{
	char	*base;
	char	a;

	base = "0123456789abcdef";
	if (c == 'X')
		base = "0123456789ABCDEF";
	if (n < 0)
	{
		n = n * -1;
		count_print('-', count);
	}
	if (n < 16)
	{
		a = base[n];
		count_print(a, count);
	}
	if (n >= 16)
	{
		puthexa(n / 16, c, count);
		puthexa(n % 16, c, count);
	}
}

void	number_adress(va_list args, char c, int *count)
{
	unsigned long int	l;

	l = va_arg(args, unsigned long int);
	if (l == 0)
	{
		write(1, "(null)", 6);
		(*count) += 6;
	}
	else
	{
		write(1, "0x", 2);
		(*count) += 2;
		puthexa(l, c, count);
	}
}

void	number_hexa(va_list args, char c, int *count)
{
	unsigned long int	l;

	l = va_arg(args, unsigned long int);
	if (l == 0)
		count_print('0', count);
	else
		puthexa(l, c, count);
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
		(*count) += 11;
	}
	else
	{
		if (n < 0)
		{
			n = n * -1;
			count_print('-', count);
		}
		if (n < 10)
			count_print((char){n + '0'}, count);
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
	int	i;

	i = 0;
	s = va_arg(args, char *);
	if (!s)
	{
		write(1, "(null)", 6);
		(*count) += 6;
	}
	while (s[i])
	{
		write(1, &s[i], 1);
		(*count)++;
		i++;
	}
}

void	count_print(char c, int *count)
{
	write(1, &c, 1);
	(*count)++;
}
