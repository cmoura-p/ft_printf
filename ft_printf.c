/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoura-p <cmoura-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:09:12 by cmoura-p          #+#    #+#             */
/*   Updated: 2023/11/07 20:50:57 by cmoura-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libft.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int ft_print_char(int c);
int ft_print_str(char *str);
//int ft_print_vphex(void *lhexa);
int ft_print_num(long c, int base);

int avarage(int num, ...)
{
    int soma = 0;
    int i = 0;
    va_list ap;

    va_start(ap, num);
    while(i < num)
    {
        soma = soma + va_arg(ap, int);
        i++;
    }
    va_end(ap);
    return (soma / num);
}
int ft_print_char(int c)
{
    return write(1, &c, 1);
}

int ft_print_str(char *str)
{
    int i;
    
    i = 0;
    while (*str)
    {
        ft_print_char((int)*str);
        i++;
        str++;
    }
    return (i);    
}

/*int ft_print_vphex(void *data)
{
    
        aqui tenho que pesquisar como faco
    
}
*/
int ft_print_num(long n, int base)
{
    int     i;
    char    *sysmbols;
    
    if (base == 10)
        i = 10;
    sysmbols = "0123456789abcdef";
    if (n < 0)
    {
        write(1, "-", 1);
        
    }
    return (0);
}

int ft_check_format(char datatype, va_list ap)
{
    int i;
    
    i = 0;
    if (datatype == 'c')
        i += ft_print_char(va_arg(ap, int));
    else if (datatype == 's')
        i += ft_print_str(va_arg(ap, char *));
//    else if (datatype == 'p')
//        i += ft_print_vphex(va_arg(ap, void *));
    else if (datatype == 'd' || datatype == 'i')
        i += ft_print_num((long)(va_arg(ap, int)), 10);
    else if (datatype == 'u')
        i += ft_print_num((long)(va_arg(ap, unsigned int)), 0);
    else if (datatype == 'x')
        i += ft_print_num((long)(va_arg(ap, int)), 16);
    else if (datatype == 'X')
        i += ft_print_num((long)(va_arg(ap, int)), 32);
    else if (datatype == '%')
        i += ft_print_char(va_arg(ap, int));
    return (i);
}

int ft_printf(const char *format, ...)
{
    va_list ap;
    int     i;

    i = 0;
    va_start(ap, format);
    while(*format)
    {
        if(*format == '%')
            i += ft_check_format(*(++format), ap);
        else
            i += write(1, format, 1);
        format++;
    }
    va_end(ap);
    return (i);
}

int main(void)
{
/*    printf("Return: %d\n", printf("\nOriginal printf:\n"));
    printf("Return: %d\n", printf("CHAR %c CHAR\n", 'd'));
    printf("Return: %d\n", printf("STRING %s STRING\n", "null"));
    printf("Return: %d\n", printf("POINTER %p POINTER\n", &"hi"));
    printf("Return: %d\n", printf("DECIMAL %d DECIMAL\n", 23));
    printf("Return: %d\n", printf("INTEGER %i INTEGER\n", 42));
    printf("Return: %d\n", printf("UNS DECIMAL %u UNS DECIMAL\n", -81));
    printf("Return: %d\n", printf("hexadec %x hexadec\n", 42));
    printf("Return: %d\n", printf("HEXADEC %X HEXADEC\n", 42));
    printf("Return: %d\n", printf("PERCENT %% PERCENT\n"));
*/    ft_printf("Return: %d\n", ft_printf("\nft_printf:\n"));
    ft_printf("Return: %d\n", ft_printf("CHAR %c CHAR\n", 'd'));
    ft_printf("Return: %d\n", ft_printf("STRING %s STRING\n", "null"));
//    ft_printf("Return: %d\n", ft_printf("POINTER %p POINTER\n", &"hi"));
    ft_printf("Return: %d\n", ft_printf("DECIMAL %d DECIMAL\n", 23));
//    ft_printf("Return: %d\n", ft_printf("INTEGER %i INTEGER\n", 42));
    ft_printf("Return: %d\n", ft_printf("UNS DECIMAL %u UNS DECIMAL\n", -81));
    ft_printf("Return: %d\n", ft_printf("hexadec %x hexadec\n", 42));
    ft_printf("Return: %d\n", ft_printf("HEXADEC %X HEXADEC\n", 42));
//    ft_printf("Return: %d\n", ft_printf("PERCENT %% PERCENT\n"));
//    return (0);

    int media = avarage(5,2,4,6,8,10);
    
    printf("A media com resultado inteiro eh %d\n", media);
    
}