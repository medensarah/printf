/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 04:48:37 by smedenec          #+#    #+#             */
/*   Updated: 2025/06/06 05:38:43 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "printf.h"
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stddef.h>
#include <stdarg.h>

int	ft_printf(const char *string, ...)
{
	int	count;
	va_list	args;
	va_start(args, string);

	count = 0;
	if (!string)
		return (-1);
	
	return (count);
}
