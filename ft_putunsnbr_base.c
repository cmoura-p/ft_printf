/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsnbr_base.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoura-p <cmoura-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 19:40:00 by cmoura-p          #+#    #+#             */
/*   Updated: 2023/11/10 20:28:02 by cmoura-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunsnbr_base(unsigned long n, char *base)
{
	int				size;
	unsigned int	b_size;

	size = 0;
	b_size = ft_strlen(base);
	if (n >= b_size)
	{
		size += ft_putunsnbr_base(n / b_size, base);
		n = n % b_size;
	}
	size += write(1, &base[n], 1);
	return (size);
}
