/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoura-p <cmoura-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:09:12 by cmoura-p          #+#    #+#             */
/*   Updated: 2023/11/20 20:15:32 by cmoura-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;

	i = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
			i += ft_check_format(*(++format), ap);
		else
			i += write(1, format, 1);
		++format;
	}
	va_end(ap);
	return (i);
}
/*
int main(void)
{
	char	*real = "Hoje eh segunda - 42";
    int     x;

    x = ft_printf("POINTER %p POINTER\n", &real);
	ft_printf("-> %d\n", x);
	
//  The real PRINTF
    printf("-> %d\n", printf("\nOriginal printf:\n"));
    printf("-> %d\n", printf("CHAR %c CHAR\n", 'r'));
    printf("-> %d\n", printf("STRING %s STRING\n", "real printf"));
    printf("-> %d\n", printf("POINTER %p POINTER\n", &real));
    printf("-> %d\n", printf("DECIMAL %d DECIMAL\n", 23));
    printf("-> %d\n", printf("INTEGER %i INTEGER\n", 42));
    printf("-> %d\n", printf("UNSIG DECIMAL %u UNSIG DECIMAL\n", -42));
    printf("-> %d\n", printf("hexadec %x hexadec\n", 42));
    printf("-> %d\n", printf("HEXADEC %X HEXADEC\n", 42));
    printf("-> %d\n", printf("PERCENT %% PERCENT\n"));
      
//  My PRINTF
    ft_printf("-> %d\n", ft_printf("\nMy printf:\n"));
    ft_printf("-> %d\n", ft_printf("CHAR %c CHAR\n", 'm'));
    ft_printf("-> %d\n", ft_printf("STRING %s STRING\n", "mine printf"));
    ft_printf("-> %d\n", ft_printf("POINTER %p POINTER\n", &real));
    ft_printf("-> %d\n", ft_printf("DECIMAL %d DECIMAL\n", 59));
    ft_printf("-> %d\n", ft_printf("INTEGER %i INTEGER\n", 42));
    ft_printf("-> %d\n", ft_printf("UNSIG DECIMAL %u UNSIG DECIMAL\n", -42));
    ft_printf("-> %d\n", ft_printf("hexadec %x hexadec\n", 42));
    ft_printf("-> %d\n", ft_printf("HEXADEC %X HEXADEC\n", 42));
    ft_printf("-> %d\n", ft_printf("PERCENT %% PERCENT\n"));

    return (0);
}
*/
