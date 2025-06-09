/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 04:42:01 by smedenec          #+#    #+#             */
/*   Updated: 2025/06/09 20:06:29 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdio.h>
// a enlever

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stddef.h>
# include <stdarg.h>

int		ft_printf(const char *s, ...);
void	dispatch(char c, va_list args, int *count);
void	count_print(char c, int *count);
void	ft_putstr(va_list args, int *count);
void	ft_putnbr(int n, int *count);
void	putnbr_unsigned(unsigned int n, int *count);
void	number_decimal(va_list args, int *count);
void	number_unsigned(va_list args, int *count);
void	number_hexa(va_list args, char c, int *count);
void	puthexa(long n, char c, int *count);

#endif
