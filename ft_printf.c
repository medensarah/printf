/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 04:48:37 by smedenec          #+#    #+#             */
/*   Updated: 2025/06/15 20:11:01 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_printf(const char *s, ...)
{
	int		*count;
	int		num;
	int		a;
	va_list	args;

	if (!s)
		return (-1);
	va_start(args, s);
	num = 0;
	count = &num;
	while (*s)
	{
		if (*s == '%')
			dispatch(*++s, args, count);
		else
		{
			write(1, s, 1);
			(*count)++;
		}
	s++;
	}
	return (*count);
}
int	main(void)
{
	char	carac;
	char	*string;
	unsigned int		integer;
	unsigned	unsign;
	int	a;
	int	b;


	carac = '1';
	string = "iigne";
	integer = -4967297;
	unsign = -2147483648;
	a = printf("v= %d\n", unsign);
	b = ft_printf("m= %d\n", unsign);
	printf("Vret= %d\nMret= %d\n", a, b);
}
