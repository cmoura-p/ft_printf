/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoura-p <cmoura-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:09:12 by cmoura-p          #+#    #+#             */
/*   Updated: 2023/11/08 16:15:58 by cmoura-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libft.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int ft_print_char(int c);
int ft_print_str(char *str);
int ft_print_num(long c, int base);
int ft_check_format(char datatype, va_list ap);

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

int ft_print_num(long n, int base)
{
    int     i;
    char    *symbols;
    
    symbols = "0123456789abcdef";
    if (n < 0)
    {
        write(1, "-", 1);
        return (ft_print_num(-n, base) +1);
    }
    else if (n < base)
        return (ft_print_num(symbols[n], base));
    else
    {
        i = ft_print_num(n / base, base);
        return (i + ft_print_num(n % base, base));
    }
    return (i);
}

int ft_check_format(char datatype, va_list ap)
{
    int i;
    
    i = 0;
    if (datatype == 'c')
        i += ft_print_char(va_arg(ap, int));
    else if (datatype == 's')
        i += ft_print_str(va_arg(ap, char *));
    else if (datatype == 'd')
        i += ft_print_num((long)(va_arg(ap, int)), 10);
    else if (datatype == 'x')
        i += ft_print_num((long)(va_arg(ap, unsigned int)), 16);
    else
        i += write(1, &datatype, 1);
    //else if (datatype == 'X')
    //    i += ft_print_num((long)(va_arg(ap, int)), 32);
    //else if (datatype == '%')
    //    i += ft_print_char(va_arg(ap, int));
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
            /*
             (*(++format)) o pointer estah em %, por isso o
             ++format pois queremos o proximo caractere
             
             obviamente tenho que guardar em i todos os 
             caracteres que tenho lido
             o ft_check_format ira retornar a quantidade 
             de caracteres que foram lidos
            */
        else
            i += write(1, format, 1);
            /*
            caso nao seja um %, ou seja, um caractere qq
            fazemos um simples write do caractere
            o comando write pode retornar o numero de bytes
            que foram escitos e como o ft_check_formar
            atualiza i, fazemos o mesmo aqui no else
            */
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
    
    //ft_printf("Return: %d\n", ft_printf("CHAR %c CHAR\n", 'd'));
    //ft_printf("Return: %d\n", ft_printf("STRING %s STRING\n", "null"));
    //ft_printf("Return: %d\n", ft_printf("DECIMAL %d DECIMAL\n", 23));
    //ft_printf("Return: %d\n", ft_printf("UNS DECIMAL %u UNS DECIMAL\n", -81));
    //ft_printf("Return: %d\n", ft_printf("hexadec %x hexadec\n", 42));
    //ft_printf("Return: %d\n", ft_printf("HEXADEC %X HEXADEC\n", 42));

/*  The real PRINTF
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
*/    
   return (0);
}