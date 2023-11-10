/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoura-p <cmoura-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 20:42:58 by cmoura-p          #+#    #+#             */
/*   Updated: 2023/11/10 21:09:43 by cmoura-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_ptr(size_t n, char *base)
{
	int	i;
	int	s_base;

	s_base = ft_strlen(base);
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
		i += ft_print_num((long)(n / s_base), base, 'x');
		i += ft_print_num((long)(n % s_base), base, 'x');
	}
	return (i);
}
