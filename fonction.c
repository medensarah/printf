/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonction.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 05:06:35 by smedenec          #+#    #+#             */
/*   Updated: 2025/06/15 20:05:22 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

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

void	puthexa(unsigned int n, char c, int *count)
{
	int		i;
	int		nbr;
	char	list[20];

	i = 0;
	while (n > 0)
	{
		nbr = n % 16;
		if (nbr < 10)
			list[i] = nbr + '0';
		else
		{
			if (c == 'X')
				list[i] = nbr - 10 + 'A';
			else
				list[i] = nbr - 10 + 'a';
		}
		n = n / 16;
		i++;
	}
	while (--i >= 0)
		count_print(list[i], count);
}
void	number_adress(va_list args, char c, int *count)
{
	long	l;

	l = (unsigned int)va_arg(args, long);
	if (l == 0)
		count_print('0', count);
	else
	{
		write(1, "0x", 2);
		count = count + 2;
		puthexa(l, c, count);
	}
}

void	number_hexa(va_list args, char c, int *count)
{
	int		n;
	long	l;

	n = va_arg(args, int);
	l = (unsigned int)n;
	if (n == 0)
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
		count += 11;
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

	s = va_arg(args, char *);
	while (*s)
	{
		write(1, &*s, 1);
		(*count)++;
		s++;
	}
}

void	count_print(char c, int *count)
{
	write(1, &c, 1);
	(*count)++;
}
