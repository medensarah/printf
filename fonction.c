/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonction.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 05:06:35 by smedenec          #+#    #+#             */
/*   Updated: 2025/06/06 05:08:42 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "printf.h"
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stddef.h>
#include <stdarg.h>

void	putchar(char c)
{
	write(1, &c, 1);
}

