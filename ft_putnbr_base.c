/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoura-p <cmoura-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 19:33:08 by cmoura-p          #+#    #+#             */
/*   Updated: 2023/11/10 20:29:12 by cmoura-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(long n, char *base)
{
	int	size;
	int	b_size;

	size = 0;
	b_size = ft_strlen(base);
	if (n < 0)
	{
		write(1, "-", 1);
		size++;
		n = -n;
	}
	if (n >= b_size)
	{
		size += ft_putnbr_base(n / b_size, base);
		n = n % b_size;
	}
	size += write(1, &base[n], 1);
	return (size);
}
