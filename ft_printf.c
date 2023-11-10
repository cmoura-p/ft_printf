/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoura-p <cmoura-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:09:12 by cmoura-p          #+#    #+#             */
/*   Updated: 2023/11/10 21:50:42 by cmoura-p         ###   ########.fr       */
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

int main(void)
{
    int count;
    
    count = ft_printf("Apenas a letra %c\n", 'A');
    write(1, &count, 1);
    ft_printf("=> %d\n", count);
    count = ft_printf("Hello%s\n", " World");
    ft_printf("=> %d\n", count);
    
    ft_printf("Return: %d\n", ft_printf("CHAR %c CHAR\n", 'd'));
    ft_printf("Return: %d\n", ft_printf("STRING %s STRING\n", "null"));
    ft_printf("Return: %d\n", ft_printf("DECIMAL %d DECIMAL\n", 23));
    ft_printf("Return: %d\n", ft_printf("UNS DECIMAL %u UNS DECIMAL\n", -81));
    ft_printf("Return: %d\n", ft_printf("hexadec %x hexadec\n", 42));
    ft_printf("Return: %d\n", ft_printf("HEXADEC %X HEXADEC\n", 42));

//    The real PRINTF
    printf("Return: %d\n", printf("\nOriginal printf:\n"));
    printf("Return: %d\n", printf("CHAR %c CHAR\n", 'd'));
    printf("Return: %d\n", printf("STRING %s STRING\n", "null"));
    printf("Return: %d\n", printf("POINTER %p POINTER\n", &"hi"));
    printf("Return: %d\n", printf("DECIMAL %d DECIMAL\n", 23));
    printf("Return: %d\n", printf("INTEGER %i INTEGER\n", 42));
    printf("Return: %d\n", printf("UNS DECIMAL %u UNS DECIMAL\n", -81));
    printf("Return: %d\n", printf("hexadec %x hexadec\n", 42));
    printf("Return: %d\n", printf("HEXADEC %X HEXADEC\n", 42));
    printf("Return: %d\n", printf("PERCENT %% PERCENT\n"));
      
    return (0);
}
