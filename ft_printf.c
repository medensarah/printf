/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 04:48:37 by smedenec          #+#    #+#             */
/*   Updated: 2025/06/17 17:54:27 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	int		*count;
	int		num;
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

// int	main(void)
// {
// 	char		*string;
// 	int			*point;
// 	int			integer;

// 	int			mine;
// 	int			real;

// 	string = "non";
// 	integer = 96;
// 	point = &integer;
// 	printf("real\n");
// 	real = printf("integer = %p String = %p\n", point, string);
// 	printf("return = %d\n", real);
// 	//
// 	printf("mine\n");
// 	mine = ft_printf("integer = %p String = %p\n", point, string);
// 	printf("return = %d\n", mine);
// }
