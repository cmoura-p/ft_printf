/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoura-p <cmoura-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 20:42:58 by cmoura-p          #+#    #+#             */
/*   Updated: 2023/11/16 14:31:24 by cmoura-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_ptr(size_t n, char *base)
{
	int	i;
	int	b_size;

	b_size = ft_strlen(base);
	i = 0;
	if (n == 0)
		return (write(1, "(nil)", 5));
	if (n < 16)
	{
		i = write(1, "0x", 2);
		i += ft_print_num((long)n, base, 'x');
	}
	else
	{
		i = write(1, "0x", 2);
		i += ft_print_num((long)(n / b_size), base, 'x');
		i += ft_print_num((long)(n % b_size), base, 'x');
	}
	return (i);
}
