/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoura-p <cmoura-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 18:42:39 by cmoura-p          #+#    #+#             */
/*   Updated: 2023/11/11 16:19:05 by cmoura-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>

# define DEC    "0123456789"
# define HEXL   "0123456789abcdef"
# define HEXU   "0123456789ABCDEF"

int		ft_printf(const char *format, ...);
int		ft_check_format(char datatype, va_list ap);
int		ft_print_char(int c);
int		ft_print_str(char *str);
int		ft_print_num(long n, char *base, char datatype);
int		ft_print_ptr(size_t n, char *base);
size_t	ft_strlen(const char *str);

#endif
