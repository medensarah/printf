/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 04:42:01 by smedenec          #+#    #+#             */
/*   Updated: 2025/06/07 17:29:40 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stddef.h>
# include <stdarg.h>

int		ft_printf(const char *s, ...);
void	dispatch(char c, va_list args, int *count);
void	putchar(va_list args, int *count);
void	putpurcent(char c, int *count);

#endif
