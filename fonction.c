/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonction.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 05:06:35 by smedenec          #+#    #+#             */
/*   Updated: 2025/06/09 14:53:46 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	dispatch(char c, va_list args, int *count)
{
	if (c == '%')
		putpurcent(c, count);
	if (c == 'c')
		putchar(args, count);
	if (c == 's')
		putstr(args, count);
	// if (c == 'i' || c == 'd')
	// 	putnbr(args, count);
}
// if (info == %c)
// 	putchar(va_arg(args, char));
void	putstr(va_list args, int *count)
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

void	putchar(va_list args, int *count)
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
